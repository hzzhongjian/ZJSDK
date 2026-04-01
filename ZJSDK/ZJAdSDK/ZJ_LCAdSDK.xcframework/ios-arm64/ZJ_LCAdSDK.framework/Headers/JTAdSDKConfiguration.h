//
//  JTAdSDKConfiguration.h
//  JTAdSDK
//
//  Created by Frank on 2025/6/18.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, JTAdSDKIAPStatusEnum) {
    JTAdSDKIAPStatus_Unknown,
    JTAdSDKIAPStatus_SupportIAP,
    JTAdSDKIAPStatus_NotSupportIAP,
};

/// 定位信息模型
@interface JTAdSDKLocationModel : NSObject

/// 纬度 (-90.0 ~ 90.0)
@property (nonatomic, assign) float lat;

/// 经度 (-180.0 ~ 180.0)
@property (nonatomic, assign) float lon;

@end

/// SDK配置信息模型
@interface JTAdSDKConfiguration : NSObject

/// 应用ID。目前已废弃，请使用SDKManager startAdSDKWithAppID:token:入参。
@property (nonatomic, copy) NSString * appId;

/// 应用签名。目前已废弃，请使用SDKManager startAdSDKWithAppID:token:入参。
@property (nonatomic, copy) NSString * appToken;

/// 本应用是否收费
@property (nonatomic, assign) JTAdSDKIAPStatusEnum IAPStatus;

/// 设备IDFA
@property (nonatomic, copy) NSString *idfa;

/// 限制个性化广告。默认是NO，不限制。
@property (nonatomic, assign) BOOL limitPersonalAds;

/// 设备地理位置信息
@property (nonatomic, strong) JTAdSDKLocationModel *locationModel;

/// 获取配置信息模型唯一方法
+ (instancetype)configuration;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
- (id)copy NS_UNAVAILABLE;
- (id)mutableCopy NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
