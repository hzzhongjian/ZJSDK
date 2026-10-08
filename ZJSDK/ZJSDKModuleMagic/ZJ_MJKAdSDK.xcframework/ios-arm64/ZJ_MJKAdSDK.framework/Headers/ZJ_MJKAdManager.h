//
//  ZJ_MJKLiAdManager.h
//  ADSDK
//
//  Created by jiangzhenwei on 2019/7/9.
//  Copyright © 2019 lishipin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <ZJ_MJKAdSDK/ZJ_MJKAdError.h>
#import <ZJ_MJKAdSDK/ZJ_MJKAdDelegate.h>
#import <ZJ_MJKAdSDK/ZJ_MJKAdPrivacyConfig.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZJ_MJKAdManager : NSObject

/**
 初始化
 **/
+ (void)initWithAppId:(NSString *)appId delegate:(id<ZJ_MJKAdInitDelegate> _Nullable)delegate;

/**
 初始化。config 可为 nil
 */
+ (void)initWithAppId:(NSString *)appId config:(ZJ_MJKAdPrivacyConfig * _Nullable)config delegate:(id<ZJ_MJKAdInitDelegate> _Nullable)delegate;

/**
 初始化
 媒体id初始化
 **/
+ (void)initWithMediaId:(NSString *)mediaId delegate:(id<ZJ_MJKAdInitDelegate> _Nullable)delegate;

/**
 媒体 ID 初始化。config 可为 nil
 */
+ (void)initWithMediaId:(NSString *)mediaId config:(ZJ_MJKAdPrivacyConfig * _Nullable)config delegate:(id<ZJ_MJKAdInitDelegate> _Nullable)delegate;

/**
 获取SDK版本号
 */
+ (NSString *)getSDKVersion;

/**
 支持小程序跳转需要设置
 微信appid和universal link链接
 同时集成微信openSDK和配置好universal link链接
 */
+ (void)setWXAppId:(NSString *)appid universalLink:(NSString *)universalLink;


/**
 设置个性化广告推荐
 **/
+ (void)setPersonalizedAdState:(BOOL)state;

/**
 重置广告标识符
 */
+ (void)resetIDFA:(NSString *)idfa;

/**
 设置请求测试环境
 */
+ (void)setTestEnvironment:(BOOL) isTest;

/**
 设置debug模式
 */
+ (void)setDebugEnable:(BOOL)isDebug;

@end

NS_ASSUME_NONNULL_END
