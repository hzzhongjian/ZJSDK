//
//  ZJAdSDK.h
//  ZJSDK
//
//  Created by Rare on 2022/2/18.
//  Copyright © 2022 zj. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ZJSDKCore/ZJSDKAdEnum.h>

NS_ASSUME_NONNULL_BEGIN


@class ZJSDKInitModel;

@interface ZJAdSDK : NSObject


/**
 SDK 注册接口，请在 app 初始化时调用。新版本对接请使用registerSDK方式初始化
 @param appId - 媒体ID
*/
+ (void)registerAppId:(NSString *)appId;


/**
 * SDK 注册接口，请在 app 初始化时调用。
 */
+ (void)registerSDK:(ZJSDKInitModel *)initModel;


/**
 * SDK 注册接口，请在 app 初始化时调用。首次调用，网络权限从不可用切换到可用，block可能会回调多次
 * @param initModel - 初始化数据
 * @param callback 初始化信息
 */
+ (void)registerSDK:(ZJSDKInitModel *)initModel callback:(void(^)(BOOL completed, NSDictionary *info))callback;

/**
 SDK 注册接口，请在 app 初始化时调用，首次调用，网络权限从不可用切换到可用，block可能会回调多次。
 @param appId - 媒体ID
 @param callback 初始化信息
*/
+ (void)registerAppId:(NSString*)appId callback:(void(^)(BOOL completed, NSDictionary *info))callback;

/**
 日志打印设置
 */
+ (void)setLogLevel:(ZJAdSDKLogLevel)level;


/**
 SDK版本号
*/
+ (NSString *)SDKVersion;

/**
 appId
*/
+ (NSString *)appId;


/**
 *个性化推荐广告开关，看到的广告数量不变，相关度降低
 *默认为ON打开,
 *请在SDK初始化之前使用
 */
+ (void)persionalizedState:(ZJSDKPersionalizedState)persionalizedState;

/**
 *程序化推荐开关，关闭后，看到的广告数量不变，但将不会为你推荐程序化广告
 *是否允许开启广告的程序化推荐 OFF 关闭，ON开启，默认为ON开启
 *默认打开
 *请在SDK初始化之前使用
 */
+ (void)programmaticRecommend:(ZJSDKProgrammaticRecommend)enableProgrammaticRecommend;

@end

NS_ASSUME_NONNULL_END
