/**************************************************************************************************
 *
 * Copyright (c) 2019-2024 Axera Semiconductor Co., Ltd. All Rights Reserved.
 *
 * This source file is the property of Axera Semiconductor Co., Ltd. and
 * may not be copied or distributed in any isomorphic form without the prior
 * written consent of Axera Semiconductor Co., Ltd.
 *
 **************************************************************************************************/

#ifndef __AX_RTSP_DEF_H__
#define __AX_RTSP_DEF_H__

#include "ax_base_type.h"
#include "ax_global_type.h"

#define RTSP_MAX_CHN_NUM (8)

typedef enum axRTSP_MEDIA_TYPE_E {
    AX_RTSP_MEDIA_VIDEO,
    AX_RTSP_MEDIA_AUDIO,
    AX_RTSP_MEDIA_BUTT
} AX_RTSP_MEDIA_TYPE_E;

typedef struct axRTSP_SESS_ATTR {
    AX_U32 nChannel;
    struct rstp_video_attr {
        AX_BOOL bEnable;
        AX_PAYLOAD_TYPE_E ePt;
    } stVideoAttr;
    struct rstp_audio_attr {
        AX_BOOL bEnable;
        AX_PAYLOAD_TYPE_E ePt;
        AX_U32 nSampleRate;
        AX_S32 nAOT; // audio object type
        AX_U8 nChnCnt;
    } stAudioAttr;
} AX_RTSP_SESS_ATTR_T;

typedef AX_VOID *AX_RTSP_HANDLE;

#endif // __AX_RTSP_DEF_H__