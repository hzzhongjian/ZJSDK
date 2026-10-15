//
//  ZJFLVideoConfig.h
//  ZJFLAdSaas
//
//  Created by lurich on 2021/10/27.
//

#import <Foundation/Foundation.h>
#import "ZJFLFeedAdData.h"

@class ZJFLPlayModel;

/// 视频声音控制宏
#define ZJFLAdSaasVideoMuteEnable      @"ZJFLAdSaasVideoMuteEnable"
/// 视频播放控制宏
#define ZJFLAdSaasVideoPlayEnable      @"ZJFLAdSaasVideoPlayEnable"
/// 获取 BOOL 值的Key
#define ZJFLAdSaasVideoEnableSwitchKey @"ZJFLAdSaasVideoEnableSwitchKey"
/// 目标播放器唯一标识，用于精准静音/播放控制
#define ZJFLAdSaasVideoPlayerIDKey     @"ZJFLAdSaasVideoPlayerIDKey"

/// 释放指定播放器的Key（广告类请求ID）
#define ZJFLAdSaasVideoFreePlayerKey   @"ZJFLAdSaasVideoFreePlayerKey"
/// 释放视频播放器
#define ZJFLAdSaasVideoFreePlayerName  @"ZJFLAdSaasVideoFreePlayerName"

typedef NS_ENUM(NSInteger, ZJFLVideoAutoPlayPolicy) {
    ZJFLVideoAutoPlayPolicyWIFI   = 0, // WIFI 下自动播放
    ZJFLVideoAutoPlayPolicyAlways = 1, // 总是自动播放，无论网络条件
    ZJFLVideoAutoPlayPolicyNever  = 2, // 从不自动播放，无论网络条件
};

typedef enum : NSUInteger {
    ZJFLVideoStatusNull,      //url无效
    ZJFLVideoStatusLocation,  //本地已缓存
    ZJFLVideoStatusPreload,   //待缓存
} ZJFLVideoCacheStatus;

NS_ASSUME_NONNULL_BEGIN

@interface ZJFLVideoConfig : NSObject

/**
 *  视频自动播放策略，默认 ZJFLVideoAutoPlayPolicyAlways,
 *  选择 ZJFLVideoAutoPlayPolicyNever 策略时，需要开发者手动控制视频播放/暂停
 *
 *  播放控制 ZJFLAdSaasVideoPlayEnable  YES：播放； NO：暂停
 *  [[NSNotificationCenter defaultCenter] postNotificationName:ZJFLAdSaasVideoPlayEnable object:nil userInfo:@{ZJFLAdSaasVideoEnableSwitchKey:@(status)}];
 */
@property (nonatomic, assign) ZJFLVideoAutoPlayPolicy autoPlayPolicy;

/**
 *  自动播放时，是否静音。默认 YES。loadAd 前设置。
 *
 *  声音实时控制 ZJFLAdSaasVideoMuteEnable  YES：静音； NO：有声
 *  [[NSNotificationCenter defaultCenter] postNotificationName:ZJFLAdSaasVideoMuteEnable object:nil userInfo:@{ZJFLAdSaasVideoEnableSwitchKey:@(status)}];
 */
@property (nonatomic, assign) BOOL videoMuted;

/**
 *  由SDK控制视频是否静音。 默认NO
 * */
@property (nonatomic, assign) BOOL isVideoMutedConfig DEPRECATED_MSG_ATTRIBUTE("已弃用");

/**
 *  是否循环播放视频广告，默认YES
 * */
@property (nonatomic, assign) BOOL replay;

/// 当前配置绑定的实例化播放器（预加载/全屏渲染使用）
@property (nonatomic, strong, readonly) ZJFLPlayModel *playModel;

/**
 *  sdk渲染全屏视频
 * */
-(void) renderFullScreenVideoWithUrl: (ZJFLFeedAdData *) adData completeBlock: (void(^)(BOOL result)) completeBlock;

@end

NS_ASSUME_NONNULL_END
