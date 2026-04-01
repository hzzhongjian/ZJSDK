//
//  ZJ_SSFWSourceAdType.h
//  Pods
//
//  Created byttt on 2023/1/29.
//

#ifndef ZJ_SSFWSourceAdType_h
#define ZJ_SSFWSourceAdType_h

typedef enum : NSUInteger {
    ZJ_SSFWAdUnknown,           // 未知的广告源
    ZJ_SSFWAdCSJ,               // 穿山甲
    ZJ_SSFWAdGDT,               // 广点通
    ZJ_SSFWAdKS,                // 快手
    ZJ_SSFWAdFancy,             // ZJ_SSFWFAPI
    ZJ_SSFWAdJD,                // 京东
    ZJ_SSFWADMY,                // 美约
    ZJ_SSFWAdUbixMerak,         // ubix 自有预算
    ZJ_SSFWAdOneAd
} ZJ_SSFWAdSourceType;


#endif /* ZJ_SSFWSourceAdType_h */
