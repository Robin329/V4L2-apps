#ifndef __FFENCODER_H_
#define __FFENCODER_H_

// ����ͷ�ļ�
extern "C" {
#include <libavformat/avformat.h>
}

#ifdef __cplusplus
extern "C" {
#endif

// ���Ͷ���
typedef struct
{
    // input params
    int   in_audio_channel_layout;
    int   in_audio_sample_fmt;
    int   in_audio_sample_rate;
    int   in_video_width;
    int   in_video_height;
    int   in_video_pixfmt;
    int   in_video_frame_rate_num;
    int   in_video_frame_rate_den;

    // output params
    char *out_filename;
    int   out_audio_bitrate;
    int   out_audio_channel_layout;
    int   out_audio_sample_rate;
    int   out_video_bitrate;
    int   out_video_width;
    int   out_video_height;
    int   out_video_frame_rate_num;
    int   out_video_frame_rate_den;

    // other params
    int   scale_flags;
    int   audio_buffer_number;
    int   video_buffer_number;
    int   enable_h264hwenc;
} FFENCODER_PARAMS;

// ��������
void* ffencoder_init (FFENCODER_PARAMS *params);
void  ffencoder_free (void *ctxt);
int   ffencoder_audio(void *ctxt, void *data[AV_NUM_DATA_POINTERS], int nbsample, int64_t pts);
int   ffencoder_video(void *ctxt, void *data[AV_NUM_DATA_POINTERS], int linesize[AV_NUM_DATA_POINTERS], int64_t pts);
int   ffencoder_write_video_frame(void *ctxt, int flags, void *data, int size, int64_t pts);

#ifdef __cplusplus
}
#endif

#endif


