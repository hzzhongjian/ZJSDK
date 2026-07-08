//
//  WindAds.h
//  WindSDK
//
//  Created by Codi on 2021/11/1.
//

#import <Foundation/Foundation.h>
#import <WindSDK/WindAdOptions.h>
#import <WindSDK/WindPrivacyProtocol.h>

typedef NS_ENUM(NSUInteger, WindLogLevel){
    WindLogLevelError=8,
    WindLogLevelWarning=6,
    WindLogLevelInformation=4,
    WindLogLevelDebug=2
};

typedef NS_ENUM (NSInteger, WindCCPAStatus) {
    WindCCPAUnknown = 0,
    WindCCPAAccepted,
    WindCCPADenied,
};


typedef NS_ENUM (NSInteger, WindConsentStatus) {
    WindConsentUnknown = 0,
    WindConsentAccepted,
    WindConsentDenied,
};

typedef NS_ENUM (NSInteger, WindAgeRestrictedStatus) {
    WindAgeRestrictedStatusUnknow = 0,
    WindAgeRestrictedStatusYES, //年龄受限制
    WindAgeRestrictedStatusNO,  //成年人，年龄不受限制
};

typedef enum : NSUInteger {
    WindAdult = 0,
    WindChildren = 1,
} WindAdultState;

typedef enum : NSUInteger {
    WindPersonalizedAdvertisingOn = 0,
    WindPersonalizedAdvertisingOff = 1,
} WindPersonalizedAdvertisingState;


typedef void(^WindAdDebugCallBack)(NSString *msg, WindLogLevel level);

@interface WindAds : NSObject

/// 获取SDK版本号
+ (NSString *)sdkVersion;

/// 获取平台唯一ID，
/// @warning  需要在一次广告请求后生成，否则返回为nil
+ (NSString *)getUid;

/// SDK初始化
/// - Parameter options: 初始化参数，设置appid&appkey
+ (void)startWithOptions:(WindAdOptions *)options;


/// 生成个SDK Token，用作服务器bidding参数
/// @warning  初始化前调用，否则有可能不生效
+ (NSString *)getSdkToken;

/// DeBug开关显示
/// @param enable true 开启debug，false 关闭debug
+ (void)setDebugEnable:(BOOL)enable;

/// 设置自定义设备信息
/// @param delegate 自定义代理对象
/// @warning  初始化前调用，否则有可能不生效
+ (void)setCustomPrivacyDelegate:(id<WindPrivacyProtocol>)delegate;

/// 设置隐私状态-CCPA
+ (void)updateCCPAStatus:(WindCCPAStatus)status;
/// 获取CCPA状态
+ (WindCCPAStatus)getCCPAStatus;

/// 设置隐私状态-GDPR
+ (WindConsentStatus)getUserGDPRConsentStatus;
/// 获取GDPR状态
+ (void)setUserGDPRConsentStatus:(WindConsentStatus)status;

/// 设置隐私状态-COPPA
+ (WindAgeRestrictedStatus)getAgeRestrictedStatus;
/// 获取COPPA状态
+ (void)setIsAgeRestrictedUser:(WindAgeRestrictedStatus)status;

/// 设置成年状态
/// - Parameter state: WindAdult: 成年人， WindChildren: 未成年人 default=WindAdult
+ (void)setAdult:(WindAdultState)state;
/// 获取当前设置的成年人状态
+ (WindAdultState)getAdultState;

/// 设置个性化推荐开关，默认开启
/// - Parameter state: WindPersonalizedAdvertisingOn: 开启个性化推荐， WindPersonalizedAdvertisingOff: 关闭个性化推荐,
+ (void)setPersonalizedAdvertising:(WindPersonalizedAdvertisingState)state;
+ (WindPersonalizedAdvertisingState)getPersonalizedAdvertisingState;

/// 设置用户年龄
+ (void)setUserAge:(NSUInteger)age;
/// 获取用户年龄
+ (NSUInteger)getUserAge;


@end
