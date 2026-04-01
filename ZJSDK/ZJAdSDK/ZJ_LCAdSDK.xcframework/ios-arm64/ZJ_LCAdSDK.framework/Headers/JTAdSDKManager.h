//
//  JTAdSDKManager.h
//  JTAdSDK
//
//  Created by Frank on 2025/6/18.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 聚推SDK管理器
@interface JTAdSDKManager : NSObject

/// 获取管理器实例的唯一方法
+ (instancetype)manager;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
- (id)copy NS_UNAVAILABLE;
- (id)mutableCopy NS_UNAVAILABLE;

/// 老版本启动SDK方法，已废弃，请使用下方带入参的方式初始化SDK
- (void)startAdSDK;

/// 启动聚推SDK方法
- (void)startAdSDKWithAppID:(NSString *)appId appToken:(NSString *)appToken;

/// 当前SDK版本
- (NSString *)sdkVersion;

@end

NS_ASSUME_NONNULL_END
