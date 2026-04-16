//
//  ZJ_CJ_SDKManager.h
//  ZJ_CJAdSDK
//
//  Created by coderqi on 2025/11/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^ZJ_CJ_InitResultBlock)(BOOL isSucc, NSError * _Nullable error);

@interface ZJ_CJ_SDKManager : NSObject

/**
 * SDK 初始化接口，请在 app 初始化时调用。
 * @param clientId - ZJ_CJ_开发者后台创建的clientId
 * @param clientSecret - ZJ_CJ_开发者后台创建的clientSecret
 */
+ (NSError *)initWithClientId:(NSString *)clientId andClientSecret:(NSString *)clientSecret;

/**
 * SDK 初始化接口，请在 app 初始化时调用。
 * @param clientId - ZJ_CJ_开发者后台创建的clientId
 * @param clientSecret - ZJ_CJ_开发者后台创建的clientSecret
 * @param resultBlock - ZJ_CJ_SDK初始化结果
 */
+ (NSError *)initWithClientId:(NSString *)clientId andClientSecret:(NSString *)clientSecret andInitResult:(ZJ_CJ_InitResultBlock)resultBlock;


/**
 * 获取 SDK 版本
 */
+ (NSString *)SDKVersion;

/**
 *  是否允许sdk 获取当前设备经纬度信息
 *  @param canGetLBSBySDK    默认NO，不允许
 */
+ (void)getDeviceLBSBySDK:(BOOL)canGetLBSBySDK;

/**
 *  是否在控制台打印Log
 *  @param isOpen    默认NO，不允许
 */
+ (void)setOpenLog:(BOOL)isOpen;

/**
 *  接入方透传经纬度信息
 *  @param lon  经度信息
 *  @param lat  纬度信息
 */
 + (void)updateLocalLBSLon:(nullable NSString *)lon
                       lat:(nullable NSString *)lat;


@end

NS_ASSUME_NONNULL_END
