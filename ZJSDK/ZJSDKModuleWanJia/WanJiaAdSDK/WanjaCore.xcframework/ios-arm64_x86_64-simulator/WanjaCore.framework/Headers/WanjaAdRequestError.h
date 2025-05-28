//
//  WanjaAdRequestError.h
//  WanjaCoreSDK
//
//  Created by guantou on 2019/12/11.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// WanjaSDK Ads error domain.
extern NSString *const kWanjaErrorDomain;

// NSError codes for Wanja error domain.
typedef NS_ENUM(NSInteger, WanjaErrorCode) {
    kWanjaErrorUnknown                              = -10000,
    
    // SpaceID不能为空
    kWanjaErrorSpaceIDNULL                          = -10001,
    
    // 在请求广告数据过程中请求超时
    kWanjaErrorTimeout                              = -10002,
    
    // 在请求广告数据过程中出现了网络错误
    kWanjaErrorNetworkError                         = -10003,
    
    // 广告ID使用错误，类型不匹配
    kWanjaErrorIDUseError                           = -10004,
    
    // 广告请求成功，但没有返回广告内容
    kWanjaErrorNoFill                               = -10005,
    
    // 广告请求成功，加载素材失败
    kWanjaErrorLoadAdError                          = -10006,
    
    // 广告请求成功，获取到不支持的广告类型
    kWanjaErrorDoesNotSupport                       = -10007,
    
    // 广告View未添加到页面
    kWanjaErrorAdNotAddView                         = -11001,
    
    // 未发现上层控制器
    kWanjaErrorDoesNotCurrentViewController         = -11002,
    
    // 未发现布局广告View
    kWanjaErrorDoesNotCurrentView                   = -11003,
    
    // 原生广告上报时，页面没有添加到视图上
    kWanjaErrorDoesNotDisplayedInScreen             = -11004,
    
    // 第三方渠道错误
    kThirdPartyChannelError                         = -12001,
    
    // 第三方渠道为空
    kWanjaErrorChannelParameterNULL                 = -12002,
    
    // 获取配置失败
    kWanjaErrorGetConfigureFail                     = -10100,
    
    // 广告请求的时间过短
    kWanjaErrorAdRequestTimeLess                    = -10200,
    
    // 未找到广告位ID
    kWanjaErrorNotGetChannelSpaceID                 = -10300,
    
    // 配置错误
    kWanjaErrorConfigureError                       = -10400,
    
    //  广告返回失败
    kWanjaErrorAdBackFail                           = -10500,
    
    // appicon为空, 个别媒体要求此时，当作广告失败
    kWanjaErrorAppIconNull                          = -10600,
    
};

@interface WanjaAdRequestError : NSError

+ (WanjaAdRequestError *)errorWithCode:(WanjaErrorCode)code;

@end

NS_ASSUME_NONNULL_END
