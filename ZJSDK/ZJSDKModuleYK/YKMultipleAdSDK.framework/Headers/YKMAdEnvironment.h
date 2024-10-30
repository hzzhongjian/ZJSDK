//
//  YKMAdEnvironment.h
//  YKMultipleAdSDK
//
//  Created by hary on 2023/12/7.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, YKMAdSDKEnvType) {
    YKMAdSDKEnvProduction = 0, //生产环境
    YKMAdSDKEnvTest = 1,   //测试环境
    YKMAdSDKEnvPreRelease = 2, /// 预发布环境
};
