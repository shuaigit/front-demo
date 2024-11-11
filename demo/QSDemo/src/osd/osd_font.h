/**************************************************************************************************
 *
 * Copyright (c) 2019-2024 Axera Semiconductor Co., Ltd. All Rights Reserved.
 *
 * This source file is the property of Axera Semiconductor Co., Ltd. and
 * may not be copied or distributed in any isomorphic form without the prior
 * written consent of Axera Semiconductor Co., Ltd.
 *
 **************************************************************************************************/

#ifndef _OSD_FONT_H_
#define _OSD_FONT_H_

#include "ax_base_type.h"
#include "ax_osd_type.h"

#ifdef FONT_USE_FREETYPE
#include "freetype.h"
#include "ft2build.h"
#include "ftglyph.h"
#endif
#include "FontIndex.h"

#include <wchar.h>
#include <math.h>

#define OSD_PIXEL_MAX_WIDTH 3840
#define OSD_PIXEL_MAX_HEIGHT 2160
#define ROTATION_WIDTH_ALIGEMENT (8)

#define RED 0xFF0000
#define PINK 0xFFC0CB
#define GREEN 0x00FF00
#define BLUE 0x0000FF
#define PURPLE 0xA020F0
#define ORANGE 0xFFA500
#define YELLOW 0xFFFF00
#define WHITE 0xFFFFFF

/* OSD Align Type */
typedef enum {
    OSDFONT_ALIGN_TYPE_LEFT_TOP,
    OSDFONT_ALIGN_TYPE_RIGHT_TOP,
    OSDFONT_ALIGN_TYPE_LEFT_BOTTOM,
    OSDFONT_ALIGN_TYPE_RIGHT_BOTTOM,
    OSDFONT_ALIGN_TYPE_MAX
} OSDFONT_ALIGN_TYPE_E;

/* Init OSD font
   @param - [IN]fontPath: font file path.
   @return - error code

   description:
   1. Init font file path
*/
AX_BOOL OSDFONT_Init(const AX_CHAR *fontfILEPath);

/* DeInit OSD Font
*/
AX_BOOL OSDFONT_DeInit(AX_VOID);

/* Generate argb data with the input text string
   @param - [IN] pTextStr: text needs to be transformated,support freetype font.
   @param - [IN/OUT]     pArgbBuffer: buffer to store osd argb data
   @param - [IN]     u32OSDWidth: OSD width
   @param - [IN]     u32OSDHeight: OSD height
   @param - [IN]sX:x axis value in osd coordinate
   @param - [IN]sY:y axis value in osd coordinate
   @param - [IN]     uFontSize: font size
   @param - [IN]     bIsBrushSide: flag for brushing character side
   @param - [IN]     uFontColor: font color
   @param - [IN]     uBgColor: background color for osd,two bytes should be same and different from other color
   @param - [IN]     uSideColor: color for brushing side
   @return - argb data buffer pointer, nullptr if error

   description:
   1. Generate argb data with input text string, and set the font color and background color.
 */
AX_VOID *OSDFONT_GenARGB(wchar_t *pTextStr, AX_U16 *pArgbBuffer, AX_U32 u32OSDWidth, AX_U32 u32OSDHeight, AX_S16 sX, AX_S16 sY,
                 AX_U16 uFontSize, AX_BOOL bIsBrushSide, AX_U32 uFontColor, AX_U32 uBgColor,
                 AX_U32 uSideColor, OSDFONT_ALIGN_TYPE_E enAlign);

AX_VOID *OSDFONT_GenBitmap(wchar_t *pTextStr, AX_U8 *pBitmapBuffer, AX_U32 u32OSDWidth, AX_U32 u32OSDHeight, AX_S16 sX, AX_S16 sY,
                   AX_U16 uFontSize, OSDFONT_ALIGN_TYPE_E enAlign);

AX_S32 OSDFONT_CalcStrSize(wchar_t *pTextStr, AX_U16 uFontSize, AX_U32 *u32OSDWidth, AX_U32 *u32OSDHeight);

#ifdef FONT_USE_FREETYPE
FT_Bitmap *OSDFONT_FTGetGlpyhBitMap(AX_U16 u16CharCode);
#endif
#endif