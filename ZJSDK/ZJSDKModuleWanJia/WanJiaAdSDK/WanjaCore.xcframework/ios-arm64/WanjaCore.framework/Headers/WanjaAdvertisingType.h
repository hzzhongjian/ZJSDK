//
//  WanjaAdvertisingType.h
//  Pods
//
//  Created by guantou on 2023/10/18.
//

#ifndef WanjaAdvertisingType_h
#define WanjaAdvertisingType_h

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, WanjaAdvertisingViewType) {
    /** 错误*/
    kWanjaAdvertisingViewTypeUnknow      = -1,
    /** webView广告*/
    kWanjaAdvertisingViewTypeWebView     = 0,
    /** 视频广告*/
    kWanjaAdvertisingViewTypePlayerView  = 1,
    /** 图片广告*/
    kWanjaAdvertisingViewTypeImageView   = 2,
    /** 空白View*/
    kWanjaAdvertisingViewTypeNULL        = 3,
};

/* 定义请求类型的枚举 */
typedef NS_ENUM(NSUInteger, WanjaAdvertisingType) {
    kWanjaAdvertTypeRewardVideo             = 1,
    kWanjaAdvertTypeSplash                  = 2,
    kWanjaAdvertTypeInterstitial            = 3,
    kWanjaAdvertTypeBanner                  = 4,
    kWanjaAdvertTypeFullScreenVedio         = 5,
    kWanjaAdvertTypeNative                  = 6,
    kWanjaAdvertTypeDrawVedio               = 7,
};

/* 渠道枚举枚举 */
typedef NS_ENUM(NSUInteger, WanjaChannelType) {
    kWanjaChannelTypeUnknow                      = 0,
    kWanjaChannelTypeWanja                     = 1,
    kWanjaChannelTypeKs                      = 2,
    kWanjaChannelTypeGdt                     = 3,
    kWanjaChannelTypeCsj                    = 4,
    kWanjaChannelTypeBd                      = 5,
    kWanjaChannelTypeLy                      = 6,
};

/* wanja进度枚举 */
typedef NS_ENUM(NSUInteger, WanjaProgressType) {
    //  默认状态未匹配到
    kWanjaExecutionProgressTypeUnknow      = 0,
    //  匹配到当前渠道
    kWanjaExecutionProgressTypeMatching    = 1,
    //  广告请求
    kWanjaExecutionProgressTypeRequest     = 2,
    //  广告返回
    kWanjaExecutionProgressTypeSuccess     = 3,
    //  广告展示
    kWanjaExecutionProgressTypeShow        = 4,
    //  广告消失
    kWanjaExecutionProgressTypeDismiss     = 5,
    //  广告失败
    kWanjaExecutionProgressTypeFail        = 6,
    //  广告流程结束
    kWanjaExecutionProgressTypeDealloc     = 7,
};


/* 是否需要比价枚举 */
typedef NS_ENUM(NSUInteger, WanjaNeedComparePrices) {
    kWanjaNeedComparePricesUnknow               = 0,
    kWanjaNeedComparePricesYES                  = 1,    // 等最高价格
    kWanjaNeedComparePricesNo                   = 2,    // 不等最高价格，直接返回
};

static NSString *const kWanjaBuyerId = @"WanjaOPUS";
static NSString *const kGdtBuyerId = @"GDT";
static NSString *const kBdBuyerId = @"BD";
static NSString *const kCsjBuyerId = @"CSJ";
static NSString *const kKsBuyerId = @"KS";
static NSString *const kLyBuyerId = @"RH";



#endif /* WanjaAdvertisingType_h */
