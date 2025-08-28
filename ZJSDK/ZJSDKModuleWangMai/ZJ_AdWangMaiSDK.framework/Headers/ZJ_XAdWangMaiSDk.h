//
//  ZJ_XAdWangMaiSDk.h
//  adwangmai_sdk
//
//  Created by 周泽浩 on 2022/11/30.
//  Copyright © 2022 YD. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ZJ_AdWangMaiSDK/ZJ_XAdLocation.h>
NS_ASSUME_NONNULL_BEGIN

@interface ZJ_XAdWangMaiSDk : NSObject

/// 是否允许SDK使用地理位置信息
/// @param allowsUseLocation 默认为YES, YES可以获取，NO禁止获取。
/// @warning  初始化SDK前调用，否则有可能不生效
- (void)allowsUseLocationStatus:(BOOL)allowsUseLocation;

/// 可传入地理位置信息，sdk使用您传入的地理位置信息。
/// @param location 地理位置参数
/// @warning  初始化SDK前调用，否则有可能不生效
- (void)setUserLocation:(ZJ_XAdLocation *)location;

/// 是否允许SDK获取IDFA信息
/// @param allowsUseIDFA 默认为YES, YES可以获取，NO禁止获取。
/// @warning  初始化SDK前调用，否则有可能不生效
- (void)allowsUseIDFAStatus:(BOOL)allowsUseIDFA;

/// 可传入idfa信息,sdk使用您传入的idfa信息。
/// @param idfa idfa设备信息,传入原始值。
/// @warning  初始化SDK前调用，否则有可能不生效
- (void)setDeviceIDFA:(NSString *)idfa;

/// 可传入caid
/// @param cdInfo 参数数组，数组内部为字典对象,Key为cd(参数)和version(版本号),对应的值均为字符串类型,示例:@{@"cd":@"",@"version":@""}
/// @warning  初始化SDK前调用，否则有可能不生效
- (void)setCdInfo:(NSArray *)cdInfo;

/// 开启个性化推荐广告,默认YES:开启
/// @param enablePersonalized 开启个性化推荐广告
/// @warning  初始化SDK前调用，否则有可能不生效
- (void)enablePersonalized:(BOOL)enablePersonalized;

/// 设置本地默认配置
/// @param fileName 文件名称
/// @warning  初始化SDK前传入，否则有可能不生效
- (void)setLocalConfigFileName:(NSString *)fileName;

+ (instancetype)sharedInstance;

/**
  @brief 初始化SDK
 @param appToken 平台生成的appToken
 @param appKey 应用key
 @param appId 小程序跳转所需appId,用于向微信注册应用
 @param universalLink 小程序跳转所需universalLink,用于向微信注册应用
 */
- (void)initWithAppToken:(NSString *)appToken appKey:(NSString *)appKey appId:(NSString *_Nullable)appId universalLink:(NSString *_Nullable)universalLink;

/**
  @brief 初始化SDK
 @param appToken 平台生成的appToken
 @param appKey 应用key
 @param appId 小程序跳转所需appId,用于向微信注册应用
 @param universalLink 小程序跳转所需universalLink,用于向微信注册应用
 @param handler 初始化结果
 */
- (void)initWithAppToken:(NSString *)appToken appKey:(NSString *)appKey appId:(NSString *_Nullable)appId universalLink:(NSString *_Nullable)universalLink handler:(void(^)(BOOL success, NSError *error))handler;

/// sdk版本号
+ (NSString *)sdkVersion;
@end

NS_ASSUME_NONNULL_END
