#ifndef __H264HWENC_H__
#define __H264HWENC_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <libavformat/avformat.h>

// ��������
//++ android mediacodec hardware h264 encoder ++//
void *h264hwenc_mediacodec_init  (int iw, int ih, int ow, int oh, int frate, int bitrate, void *ffencoder);
void  h264hwenc_mediacodec_close (void *ctxt);
int   h264hwenc_mediacodec_encode(void *ctxt, AVFrame *frame, int timeout);
int   h264hwenc_mediacodec_picture_format(void *ctxt);
int   h264hwenc_mediacodec_picture_alloc (void *ctxt, AVFrame *frame);
int   h264hwenc_mediacodec_picture_free  (void *ctxt, AVFrame *frame);
//-- android mediacodec hardware h264 encoder --//

//++ allwinner mediaserver hardware h264 encoder ++//
void *h264hwenc_mediaserver_init  (int iw, int ih, int ow, int oh, int frate, int bitrate, void *ffencoder);
void  h264hwenc_mediaserver_close (void *ctxt);
int   h264hwenc_mediaserver_encode(void *ctxt, AVFrame *frame, int timeout);
int   h264hwenc_mediaserver_picture_format(void *ctxt);
int   h264hwenc_mediaserver_picture_alloc (void *ctxt, AVFrame *frame);
int   h264hwenc_mediaserver_picture_free  (void *ctxt, AVFrame *frame);
//-- allwinner mediaserver hardware h264 encoder --//

#if defined USE_MEDIACODEC_H264ENC
#define h264hwenc_init              h264hwenc_mediacodec_init
#define h264hwenc_close             h264hwenc_mediacodec_close
#define h264hwenc_encode            h264hwenc_mediacodec_encode
#define h264hwenc_picture_format    h264hwenc_mediacodec_picture_format
#define h264hwenc_picture_alloc     h264hwenc_mediacodec_picture_alloc
#define h264hwenc_picture_free      h264hwenc_mediacodec_picture_free
#elif defined USE_MEDIASERVER_H264ENC
#define h264hwenc_init              h264hwenc_mediaserver_init
#define h264hwenc_close             h264hwenc_mediaserver_close
#define h264hwenc_encode            h264hwenc_mediaserver_encode
#define h264hwenc_picture_format    h264hwenc_mediaserver_picture_format
#define h264hwenc_picture_alloc     h264hwenc_mediaserver_picture_alloc
#define h264hwenc_picture_free      h264hwenc_mediaserver_picture_free
#else
inline void *h264hwenc_init  (int iw, int ih, int ow, int oh, int frate, int bitrate, void *ffencoder) { return NULL; }
inline void  h264hwenc_close (void *ctxt) { return; }
inline int   h264hwenc_encode(void *ctxt, AVFrame *frame, int timeout) { return 0; }
inline int   h264hwenc_picture_format(void *ctxt)  { return 0; }
inline int   h264hwenc_picture_alloc (void *ctxt, AVFrame *frame) { return 0; }
inline int   h264hwenc_picture_free  (void *ctxt, AVFrame *frame) { return 0; }
#endif

#ifdef __cplusplus
}
#endif

#endif
