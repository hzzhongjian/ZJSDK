//
//  QMAdSDKManager.h
//  QMAdSDK
//
//  Created by qusy on 2023/12/29.
//

#import <Foundation/Foundation.h>
#import <QMAdSDK/QMAdSDKConfiguration.h>

typedef NS_ENUM(NSUInteger, QMAdSDKInitializationState) {
    QMAdSDKInitializationStateNotReady = 0,
    QMAdSDKInitializationStateReady = 1,
    QMAdSDKInitializationStateFailed = 2
};

NS_ASSUME_NONNULL_BEGIN

__attribute__((objc_subclassing_restricted))
@interface QMAdSDKManager : NSObject

/// 版本号
+ (NSString *)sdkVersion;

/// 小版本号
+ (NSString *)shortSdkVersion;

/// QMCD
+ (NSArray *)qmcds;

/// The  initialization state
+ (QMAdSDKInitializationState)sdkState;

/// 是否允许摇一摇/扭一扭（单设备纬度）
/// 默认：YES 允许
+ (void)setTwistSwitch:(BOOL)enabled;

/// The  initialization method
+ (void)setupSDKWith:(QMAdSDKConfiguration *)config;

/// 初始化 SDK
+ (void)setupSDKWith:(QMAdSDKConfiguration *)config completion:(void (^)(BOOL success, NSError *error))handler;

@end

NS_ASSUME_NONNULL_END
