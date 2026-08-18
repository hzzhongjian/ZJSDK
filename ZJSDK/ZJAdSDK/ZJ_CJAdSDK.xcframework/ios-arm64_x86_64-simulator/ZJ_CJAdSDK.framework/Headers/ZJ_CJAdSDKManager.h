//
//  ZJ_CJAdSDKManager.h
//  ZJ_CJAdSDK
//
//  Created by coderqi on 2025/11/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^ZJ_CJInitResultBlock)(BOOL isSucc, NSError * _Nullable error);

@interface ZJ_CJAdSDKManager : NSObject

/**
 * SDK 初始化接口，请在 app 初始化时调用。
 * 可在任意线程调用；`resultBlock` 保证在主线程回调。
 * @param clientId - ZJ_CJ开发者后台创建的clientId
 * @param clientSecret - ZJ_CJ开发者后台创建的clientSecret
 * @param resultBlock - ZJ_CJ SDK初始化结果（主线程回调）
 */
+ (NSError *)initWithClientId:(NSString *)clientId andClientSecret:(NSString *)clientSecret andInitResult:(ZJ_CJInitResultBlock)resultBlock;

/**
 * 获取 SDK 版本
 */
+ (NSString *)SDKVersion;

/**
 * 是否允许 SDK 获取设备经纬度（默认 NO）。
 * 设为 YES 后：已授权则读取坐标；权限未决定时，仅当宿主 Info.plist 已配置
 * NSLocationWhenInUseUsageDescription 等定位用途文案才会弹出系统授权框；
 * 宿主未声明定位权限时 SDK 不会弹窗，请求照常发出且坐标为空。
 * @param canGetLBSBySDK YES=允许按上述规则获取；NO=不获取
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

/**
 *  接入方透传设备ID
 *  若 deviceID 非空，SDK 直接使用该值作为设备ID，不再自行请求获取。
 *  @param deviceID 媒体获取的设备ID字符串；传 nil 或空串表示不透传，由 SDK 自行获取
 */
+ (void)setDeviceID:(nullable NSString *)deviceID;

/**
 *  是否打开个性化广告开关
 *  @param isOpen  是否打开
 */
+ (void)setPersonalInfo:(BOOL)isOpen;


@end

NS_ASSUME_NONNULL_END
