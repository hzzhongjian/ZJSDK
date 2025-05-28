//
//  WanjaVersionTools.h
//  WanjaCoreSDK
//
//  Created by guantou on 2019/12/10.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*
 *  关于版本的工具集
 */
@interface WanjaVersionTools : NSObject

//  获取SDK版本号
+ (NSString *)wanjaSDKVersion;
//  获取安装SDK的APP版本号
+ (NSString *)currentAppVersion;
//  获取安装SDK的APP开发版本
+ (NSString *)currentAppCodeVersion;
//  获取安装SDK的Bundle
+ (NSString *)currentBundle;
//  获取安装SDK的App名字
+ (NSString *)currentAppName;

@end

NS_ASSUME_NONNULL_END
