//
//  ZJAdEventReport.h
//  ZJSDKCore
//
//  Created by Rare on 2021/3/1.
//

#import <Foundation/Foundation.h>
#import "ZJAdBaseNetworking.h"
#import "NSError+ZJAd.h"
#import <ZJSDKCore/ZJSDKAdEnum.h>
NS_ASSUME_NONNULL_BEGIN

typedef NSString *ZJEventString NS_STRING_ENUM;
FOUNDATION_EXPORT NSString * const ZJEvent_START;//开始调用
FOUNDATION_EXPORT NSString * const ZJEvent_Load;//加载成功
FOUNDATION_EXPORT NSString * const ZJEvent_Show;//展示成功
FOUNDATION_EXPORT NSString * const ZJEvent_Finish;//触发激励
FOUNDATION_EXPORT NSString * const ZJEvent_Click;//点击
FOUNDATION_EXPORT NSString * const ZJEvent_Error;//错误
FOUNDATION_EXPORT NSString * const ZJEvent_Other;//其他信息


@interface ZJAdEventReport : ZJAdBaseNetworking

//事件上报
+ (void)reportEventWithZjad_id:(NSString *)zjad_id
                        adType:(ZJAdType)adType
                         event:(ZJEventString)event
                     unionType:(NSString *)unionType
                      zj_pm_id:(NSString *)zj_pm_id
                 supplementMsg:(NSString * _Nullable )supplementMsg
                      otherDic:(NSDictionary * _Nullable)otherDic
                     ad_config:(ZJAdUnitModel *)ad_config
                      callback:(void(^)(_Nullable id responseObject, NSError * _Nullable error))callback;

+ (nullable NSURLSessionTask *)reportAppInitWithCallback:(nullable void(^)(_Nullable id responseObject, NSError * _Nullable error))callback;

+ (NSString *)getTimestampSince1970;

+ (NSNumber *)adPlatformTypeConvertPmType:(ZJAdPlatformType)adPlatformType;

@end

NS_ASSUME_NONNULL_END
