//
//  YKMAdSDKManager.h
//  YKMultipleAdSDK
//
//  Created by hary on 2023/11/2.
//

#import <Foundation/Foundation.h>
#import "YKMAdEnvironment.h"
NS_ASSUME_NONNULL_BEGIN

@interface YKMAdSDKManager : NSObject
///初始化广告SDK
+ (void)initWithAppKey:(NSString *)appKey;

///设置SDK的环境，默认是正式环境
+ (void)configEnvironment:(YKMAdSDKEnvType)envType;

///开启日志打印
+ (void)enableLog:(BOOL)enable;
@end

NS_ASSUME_NONNULL_END
