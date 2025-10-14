//
//  NSError+ZJAd.h
//  ZJSDKCore
//
//  Created by Rare on 2021/6/9.


#import <Foundation/Foundation.h>
#import <ZJSDKCore/ZJAdUnionItemModel.h>

NS_ASSUME_NONNULL_BEGIN

#define kZJTANXErrorDomain @"COM.ZJ.TANX.SDK"
#define kZJGOOGLEErrorDomain @"COM.ZJ.GOOGLE.SDK"
#define kZJBAIDUErrorDomain @"COM.ZJ.BAIDU.SDK"
#define kZJCSJErrorDomain @"COM.ZJ.CSJ.SDK"
#define kZJPANGLEErrorDomain @"COM.ZJ.PANGLE.SDK"
#define kZJGDTErrorDomain @"COM.ZJ.GDT.SDK"
#define kZJKSErrorDomain @"COM.ZJ.KS.SDK"
#define kZJMTGErrorDomain @"COM.ZJ.MTG.SDK"
#define kZJSIGErrorDomain @"COM.ZJ.SIG.SDK"
#define kZJBEIZIErrorDomain @"COM.ZJ.BEIZI.SDK"
#define kZJDSPErrorDomain @"COM.ZJ.DSP.SDK"
#define kZJQMErrorDomain @"COM.ZJ.QM.SDK"
#define kZJOCTOPUSErrorDomain @"COM.ZJ.OCTOPUS.SDK"
#define kZJYKErrorDomain @"COM.ZJ.YK.SDK"
#define kZJQIYUNErrorDomain @"COM.ZJ.QIYUN.SDK"
#define kZJTAKUErrorDomain @"COM.ZJ.TAKU.SDK"
#define kZJQIMINGADXDomain @"COM.ZJ.QIMING.SDK"
#define kZJWangMaiErrorDomain @"COM.ZJ.WANGMAI.SDK"
#define kZJMeiShuErrorDomain @"COM.ZJ.MeiShu.SDK"

typedef NS_ENUM(NSInteger, ZJErrorCodeAd)
{
    ZJErrorCodeAd_Unknown = 100100, // 未知错误
    ZJErrorCodeAd_Unregistered = 100101, // 未注册
    ZJErrorCodeAd_Timeout = 100200, // 请求超时
    ZJErrorCodeAd_LackLibraries = 100201, // 缺少依赖库
    ZJErrorCodeAd_AdId = 100202, // adid错误
    ZJErrorCodeAd_AllAdReturnError = 100203, // 广告返回错误
    ZJErrorCodeAd_is_being_limit = 100301, // 广告被限制
    ZJErrorCodeAd_WXLibrarieMissed = 100403, // 微信OpenSDK依赖缺失
    ZJErrorCodeAd_WXLibrarieRegistFail = 100404, // 微信注册失败
    ZJErrorCodeAd_WXNotResponseImp = 100405, // 微信未响应
    ZJErrorCodeAd_DisplayError = 100500, // 显示错误
    ZJErrorCodeAd_MissParameter = 100601, // 缺少参数
    ZJErrorCodeAd_AdInvalid = 100602, // 广告不合法
    ZJErrorCodeAd_app_tradeId_verify_fail = 100701,//媒体激励校验未通过
    ZJErrorCodeAd_POS_ID_RETURN_EMPTY_BY_SDK_FILTER_CODE = 100800,// 未匹配到合适广告，请稍后重试
    ZJErrorCodeAd_CONFIG_ERROR = 1000009, // 配置数据错误
    ZJErrorCodeAd_Splash_RepeatedExposure_ERROR = 1000900, // 开屏广告重复曝光的错误
    ZJErrorCodeAd_RewardVideo_RepeatedExposure_ERROR = 1000901, // 激励视频广告重复曝光的错误
    ZJErrorCodeAd_SplashFullVideo_RepeatedExposure_ERROR = 1000902, // 开屏全屏视频广告重复曝光的错误
    ZJErrorCodeAd_Interstitial_RepeatedExposure_ERROR = 1000903, // 插屏广告重复曝光的错误
    ZJErrorCodeAd_FullScreenVideo_RepeatedExposure_ERROR = 1000904, // 全屏视频广告重复曝光的错误
    ZJErrorCodeAd_NativeExpress_RepeatedExposure_ERROR = 1000905, // 信息流广告重复曝光的错误
    ZJErrorCodeAd_Native_RepeatedExposure_ERROR = 1000906, // 自渲染广告重复曝光的错误
    
};


@interface NSError (ZJAd)


+ (NSError *)zjAdError_errorWithCode:(ZJErrorCodeAd)code adItemConfig:(nullable ZJAdUnitModel *)adItemConfig userInfo:(nullable NSDictionary<NSString *, id> *)dict;

+ (NSError *)app_tradeId_verify_fail;

+ (NSError *)errorWithCode:(NSInteger)code message:(nullable NSString *)message;

- (NSDictionary *)convertDictionary;

- (NSString *)convertJSONString;

@end

NS_ASSUME_NONNULL_END
