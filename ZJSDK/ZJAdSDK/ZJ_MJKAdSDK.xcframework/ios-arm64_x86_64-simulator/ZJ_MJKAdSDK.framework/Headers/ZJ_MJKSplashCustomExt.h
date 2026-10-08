//
//  ZJ_MJKSplashCustomExt.h
//  ZJ_MJKAdOS
//
//  Created by Harry Jiang on 30/4/25.
//

#ifndef ZJ_MJKSplashCustomExt_h
#define ZJ_MJKSplashCustomExt_h
#import <Foundation/Foundation.h>
/**
 超时时间，单位秒，默认3秒
 */
extern NSString *const ZJ_MJKSplashExtraTolerateTimeoutKey;

/**
 设置底价，默认1，单位是分/千次曝光
 */
extern NSString *const ZJ_MJKSplashExtraBidFloorKey;

/**
 设置视频广告是否静音，默认是0静音，1为非静音
 */
extern NSString *const ZJ_MJKSplashExtraVideoMuteKey;

#endif /* ZJ_MJKSplashCustomExt_h */
