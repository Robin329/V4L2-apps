#include <fcntl.h>
#include <linux/videodev2.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

static int get_now_time()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

/* 保存内核映射缓冲区的地址和大小 */
typedef struct VideoBuffer {
	void *start;
	size_t length;
} VideoBuffer;
unsigned int CAP_W = 640;
unsigned int CAP_H = 480;
unsigned int CAP_BUF_NUM = 4;

int main(int argc, char **argv)
{
	int camera_fd;
	if (argc < 2)
		camera_fd = open("/dev/video10", O_RDWR); // 阻塞打开
	else
		camera_fd = open(argv[1], O_RDWR);
	printf("argc:%d argv:%s\n", argc, argv[1]);
	struct v4l2_capability cap = { 0 };
	int ret = ioctl(camera_fd, VIDIOC_QUERYCAP, &cap);

	if (ret < 0) {
		printf("ioctl VIDIOC_QUERYCAY ERROR!\n");

		goto fail;
	}
	printf("cap.driver:%s\n", cap.driver);
	printf("cap.card:%s\n", cap.card);
	printf("cap.bus_info:%s\n", cap.bus_info);
	printf("cap.version:%#x\n", cap.version);
	printf("cap.capabilities:%#x\n", cap.capabilities);
	printf("cap.device_caps:%#x\n", cap.device_caps);
	if (cap.capabilities & V4L2_CAP_VIDEO_OUTPUT) {
		printf("Video output device!\n");
	}
	if (cap.capabilities & V4L2_CAP_VIDEO_CAPTURE) {
		printf("Is a video capture device\n");
	}
	if (cap.capabilities & V4L2_CAP_VIDEO_OVERLAY) {
		printf("Can do video overlay\n");
	}
	struct v4l2_fmtdesc fmt_desc;
	int i, j;
	memset(&fmt_desc, 0, sizeof(struct v4l2_fmtdesc));
	fmt_desc.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	/* 有可能摄像头支持的图像格式不止一种 */
	for (i = 0;; i++) {
		fmt_desc.index = i;
		ret = ioctl(camera_fd, VIDIOC_ENUM_FMT, &fmt_desc);
		/* 获取所有格式完成 */
		if (-1 == ret) {
			break;
		}
		/* 打印摄像头图像格式 */
		printf("Picture Format: %s\n", fmt_desc.description);
		/* 查询该图像格式所支持的分辨率 */
		struct v4l2_frmsizeenum frmsize;
		frmsize.pixel_format = fmt_desc.pixelformat;
		/* 该格式支持分辨率不止一种 */
		for (j = 0;; j++) {
			frmsize.index = j;
			ret = ioctl(camera_fd, VIDIOC_ENUM_FRAMESIZES,
				    &frmsize);
			/* 获取所有分辨率完成 */
			if (-1 == ret) {
				break;
			}
			/* 打印分辨率 */
			printf("width: %d height: %d\n", frmsize.discrete.width,
			       frmsize.discrete.height);
		}
	}
	struct v4l2_format fmt;
	memset(&fmt, 0, sizeof(fmt));
	fmt.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	fmt.fmt.pix.width = CAP_W;
	fmt.fmt.pix.height = CAP_H;
	fmt.fmt.pix.pixelformat = V4L2_PIX_FMT_H264;
	fmt.fmt.pix.field = V4L2_FIELD_NONE;
	if (ioctl(camera_fd, VIDIOC_S_FMT, &fmt) == -1) {
		printf("set video format error!\n");
		goto fail;
	}
	struct v4l2_requestbuffers req;
	req.count = CAP_BUF_NUM;
	req.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	req.memory = V4L2_MEMORY_MMAP;
	if (-1 == ioctl(camera_fd, VIDIOC_REQBUFS, &req)) {
		printf("require buffer errors!\n");
		goto fail;
	}

	struct v4l2_buffer buf;
	VideoBuffer *buffers = calloc(req.count, sizeof(*buffers));
	unsigned int num;
	for (num = 0; num < req.count; num++) {
		memset(&buf, 0, sizeof(buf));
		buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
		buf.memory = V4L2_MEMORY_MMAP;
		buf.index = num;
		if (ioctl(camera_fd, VIDIOC_QUERYBUF, &buf) == -1) {
			printf("alloc buffer errors!\n");
			return -1;
		}
		buffers[num].length = buf.length;
		/* 内存映射到用户空间 */
		buffers[num].start =
			mmap(NULL, buf.length, PROT_READ | PROT_WRITE,
			     MAP_SHARED, camera_fd, buf.m.offset);
		if (buffers[num].start == MAP_FAILED) {
			printf("mmap error!\n");
			return -1;
		}
		/* 把帧放入队列 */
		if (ioctl(camera_fd, VIDIOC_QBUF, &buf) == -1) {
			printf("VIDIOC_QBUF error!\n");
			return -1;
		}
	}

	enum v4l2_buf_type type;
	type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	/* 开始采集 */
	ioctl(camera_fd, VIDIOC_STREAMON, &type);
	memset(&buf, 0, sizeof(buf));
	buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	buf.memory = V4L2_MEMORY_MMAP;
	int count = 100;
	FILE *fp;
	fp = fopen("./test_640_480.h264", "wb+");
	if (fp == NULL) {
		printf("open failed!\n");
		goto fail;
	}
	long int lastTime = get_now_time();
	printf("start:%ld ms\n", lastTime);
	while (count--) {
		printf("count:%d\n", count);
		/* 从队列中取出帧 */
		ret = ioctl(camera_fd, VIDIOC_DQBUF, &buf);
		if (ret < 0) {
			printf("VIDIOC_DQBUF FAILED!\n");
			goto fail;
		}
		fwrite(buffers[buf.index].start, 1, buf.bytesused, fp);
		/* 把帧放回队列 */
		ret = ioctl(camera_fd, VIDIOC_QBUF, &buf);
		if (ret < 0) {
			printf("VIDIOC_QBUF FAILED!\n");
			fclose(fp);
			ioctl(camera_fd, VIDIOC_STREAMOFF, &type);
			/* 断开内存映射连接 */
			for (i = 0; i < CAP_BUF_NUM; i++) {
				munmap(buffers[i].start, buffers[i].length);
			}
			goto fail;
		}
	}
	long int culTime = get_now_time();
	printf("Stop Time:%ld\n", culTime);
	printf("Total time:%ld ms\n", culTime - lastTime);
	fclose(fp);
	ioctl(camera_fd, VIDIOC_STREAMOFF, &type);
	/* 断开内存映射连接 */
	for (i = 0; i < CAP_BUF_NUM; i++) {
		munmap(buffers[i].start, buffers[i].length);
	}
fail:
	close(camera_fd);
	return 0;
}