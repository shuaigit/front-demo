/**************************************************************************************************
 *
 * Copyright (c) 2019-2024 Axera Semiconductor Co., Ltd. All Rights Reserved.
 *
 * This source file is the property of Axera Semiconductor Co., Ltd. and
 * may not be copied or distributed in any isomorphic form without the prior
 * written consent of Axera Semiconductor Co., Ltd.
 *
 **************************************************************************************************/

#pragma once
#include <map>
#include "AXFrame.hpp"
#include "Detector.hpp"
#include "IObserver.h"
#define DETECTOR_OBS "detector_obs"

class CDetectObserver : public IObserver {
public:
    CDetectObserver(CDetector* pSink) : m_pSink(pSink){};
    virtual ~CDetectObserver(AX_VOID) = default;

public:
    AX_BOOL OnRecvData(OBS_TARGET_TYPE_E eTarget, AX_U32 nGrp, AX_U32 nChn, AX_VOID* pData) override {
        if (!m_pSink) {
            return AX_TRUE;
        }
        CAXFrame* pFrame = (CAXFrame*)pData;
        if (!pFrame) {
            return AX_TRUE;
        }
        if (m_mapSnsMatch.find(nGrp) == m_mapSnsMatch.end()) {
            LOG_MM_D(DETECTOR_OBS, "invalid nGrp:%d", nGrp);
            pFrame->FreeMem();
            return AX_TRUE;
        }
        return m_pSink->SendFrame(m_mapSnsMatch[nGrp], pFrame);
    }

    AX_BOOL OnRegisterObserver(OBS_TARGET_TYPE_E eTarget, AX_U32 nGrp, AX_U32 nChn, OBS_TRANS_ATTR_PTR pParams) override {
        DETECTOR_ATTR_T* pConfig = m_pSink->GetDetectorCfg();
        if (pConfig->nGrpCount >= MAX_DETECTOR_GROUP_NUM) {
            LOG_MM_E(DETECTOR_OBS, "Detector number is larger than MAX_DETECTOR_GROUP_NUM(%d)!", MAX_DETECTOR_GROUP_NUM);
        }

        if (pParams->nWidth * pParams->nHeight > pConfig->nWidth * pConfig->nHeight) {
            pConfig->nWidth = pParams->nWidth;
            pConfig->nHeight = pParams->nHeight;
        }

        if (pConfig->fFramerate == 0
            || pConfig->fFramerate < pParams->fFramerate) {
            pConfig->fFramerate = pParams->fFramerate;
        }

        pConfig->nSnsId[pConfig->nGrpCount] = pParams->nSnsSrc;
        pConfig->nGrpCount++;

        LOG_MM_I(DETECTOR_OBS, "nGrp: %d, nGrpCount: %d, pParams->nSnsSrc: %d", nGrp, pConfig->nGrpCount, pConfig->nSnsId[pConfig->nGrpCount - 1]);

        m_mapSnsMatch[nGrp] = pParams->nSnsSrc;

        return AX_TRUE;
    }

private:
    CDetector* m_pSink{nullptr};
    std::map<AX_U32, AX_U8> m_mapSnsMatch;
};
