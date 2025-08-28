//
//  ZJAdEventReport.h
//  ZJSDKCore
//
//  Created by Rare on 2021/3/1.
//

#import <Foundation/Foundation.h>
#import <ZJSDKCore/ZJAdBaseNetworking.h>
#import <ZJSDKCore/NSError+ZJAd.h>
#import <ZJSDKCore/ZJSDKAdEnum.h>
#import <ZJSDKCore/ZJAdExposureReportParam.h>


NS_ASSUME_NONNULL_BEGIN

typedef NSString *ZJEventString NS_STRING_ENUM;
FOUNDATION_EXPORT NSString * const ZJEvent_START;//开始调用
FOUNDATION_EXPORT NSString * const ZJEvent_Load;//加载成功
FOUNDATION_EXPORT NSString * const ZJEvent_Show;//展示成功
FOUNDATION_EXPORT NSString * const ZJEvent_Finish;//触发激励
FOUNDATION_EXPORT NSString * const ZJEvent_Click;//点击
FOUNDATION_EXPORT NSString * const ZJEvent_Error;//错误
FOUNDATION_EXPORT NSString * const ZJEvent_Other;//其他信息
FOUNDATION_EXPORT NSString * const ZJEvent_Start_Show; // 媒体调用我们激励视频的展示方法
FOUNDATION_EXPORT NSString * const ZJEvent_EnterBackground; // 从前台进入后台
//FOUNDATION_EXPORT NSString * const ZJEvent_Close; // 广告关闭

FOUNDATION_EXPORT NSString * const ZJEvent_BidFloor; // bidding广告位获取的ecpm值小于设置的bidFloor时

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

+ (NSNumber *)adADNNameConvertPmType:(ZJAdADNName)adADNName;

+ (NSString *)adPlatformTypeConvertPmName:(ZJAdPlatformType)adPlatformType;

@end

NS_ASSUME_NONNULL_END
