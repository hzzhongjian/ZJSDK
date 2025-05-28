//
//  WanjaDefines.h
//  WanjaAD
//
//  Created by zwf on 2020/12/9.
//

#import "WanjaDevice.h"
 
#ifndef WanjaDefines_h
#define WanjaDefines_h

// 广告平台类型
typedef NS_ENUM(NSUInteger, WanjaAdPlatformType) {
    WanjaAdPlatformTypeGDT = 1,    // 广点通
    WanjaAdPlatformTypeCSJ = 2,    // 穿山甲
    WanjaAdPlatformTypeKS  = 3,    // 快手
    WanjaAdPlatformTypeSigmob  = 4,    // Sigmob
    WanjaAdPlatformTypeBaiDu  = 6,    // baidu
    WanjaAdPlatformTypeGromore  = 8,    // gromore
    WanjaAdPlatformTypeWanjaAd  = 9,    // WanjaAd
    #pragma TODO:暂时写9
};

// 错误码
typedef NS_ENUM(NSInteger, WanjaAdErrorCode) {
    WanjaAdErrorCode100 = -100,    // 参数错误
    WanjaAdErrorCode101 = -101,    // 平台初始化错误
    WanjaAdErrorCode102 = -102,    // 广告位错误
    WanjaAdErrorCode103 = -103,    // 方法调用错误
    WanjaAdErrorCode104 = -104,    // 未找到视频
    WanjaAdErrorCode105 = -105,    // 未找到广告
    WanjaAdErrorCode106 = -106,    // 未找到视图
    WanjaAdErrorCode200 = -200,    // 网络错误
    WanjaAdErrorCode301 = -301,    // 加载广告失败
    WanjaAdErrorCode302 = -302,    // 平台没有返回广告
    WanjaAdErrorCode303 = -303,    // 广告加载超时
};

typedef NS_ENUM(NSUInteger,WanjaRewardedVideoAdType) {
    WanjaRewardedVideoAdTypeEndcard         = 0,  // video + endcard
    WanjaRewardedVideoAdTypeVideoPlayable   = 1,  // video + playable
    WanjaRewardedVideoAdTypePurePlayable    = 2,  // pure playable
};

typedef NS_ENUM(NSInteger, WanjaInteractionType) {
    WanjaInteractionTypeCustorm = 0,
    WanjaInteractionTypeNO_INTERACTION = 1,  // pure ad display
    WanjaInteractionTypeURL = 2,             // open the webpage using a browser
    WanjaInteractionTypePage = 3,            // open the webpage within the app
    WanjaInteractionTypeDownload = 4,        // download the app
    WanjaInteractionTypePhone = 5,           // make a call
    WanjaInteractionTypeMessage = 6,         // send messages
    WanjaInteractionTypeEmail = 7,           // send email
    WanjaInteractionTypeVideoAdDetail = 8    // video ad details page
};

typedef NS_ENUM(NSInteger, WanjaPlayerPlayState) {
    WanjaPlayerStateFailed    = 0,
    WanjaPlayerStateBuffering = 1,
    WanjaPlayerStatePlaying   = 2,
    WanjaPlayerStateStopped   = 3,
    WanjaPlayerStatePause     = 4,
    WanjaPlayerStateDefalt    = 5
};

typedef NS_ENUM(NSInteger, WanjaAdState) {
    WanjaAdStateLoadSuccess   = 0,
    WanjaAdStateLoadTimeOut   = 1,
    WanjaAdStateClose         = 2,
    WanjaAdStateClick         = 3,
    WanjaAdStateSkip          = 4,
    WanjaAdStateShow          = 5,
    WanjaAdStateLoadError     = 6,
    WanjaAdStateVideoComplete = 7,
    WanjaAdStateVideoReward   = 8,
    WanjaAdStateIsTimeover    = 9
};

typedef NS_ENUM(NSInteger, WanjaAdType) {
    WanjaAdTypeSplashAds = 0,
    WanjaAdTypeRewardAds,
    WanjaAdTypeBannerAds,
    WanjaAdTypeNativeAds,
    WanjaAdTypeDrawAds,
    WanjaAdTypeInterstitialAds,
    WanjaAdTypeFullScreenAds,
    WanjaAdTypeNativeExpressAds,
    WanjaAdTypeDrawCustomAds
};

typedef NS_ENUM(NSInteger, WanjaAdFlowCustomType) {
    WanjaAdFlowCustomTypeSingleImg = 0,
    WanjaAdFlowCustomTypeThreeImg,
    WanjaAdFlowCustomTypeVideo
};

typedef NS_ENUM(NSInteger, WanjaACSJCustomFlowType) {
    WanjaACSJCustomFlowTypeUnknown = 0,
    WanjaACSJCustomFlowTypeBanner,
    WanjaACSJCustomFlowTypeInterstitial,
    WanjaACSJCustomFlowTypeSplash,
    WanjaACSJCustomFlowTypeSplash_Cache,
    WanjaACSJCustomFlowTypeFeed,
    WanjaACSJCustomFlowTypePaster,
    WanjaACSJCustomFlowTypeRewardVideo,
    WanjaACSJCustomFlowTypeFullscreenVideo,
    WanjaACSJCustomFlowTypeDrawVideo
};

typedef NS_ENUM(NSUInteger, WanjaAdvertScene) {
    WanjaAdvertSceneSplash = 1,        // 开屏
    WanjaAdvertSceneInfoFlow = 2,      // 信息流
    WanjaAdvertSceneReward = 3,        // 激励视频
    WanjaAdvertSceneBanner = 4,        // banner
    WanjaAdvertSceneInter = 5,         // 插屏
    WanjaAdvertSceneVideoPaster = 6,   // 贴片视频
    WanjaAdvertSceneDraw = 7,          // Draw模板
    WanjaAdvertSceneContent = 8,       // 内容
    WanjaAdvertSceneFullVideo = 9,     // 全屏视频
    WanjaAdvertSceneInfoFlowExp = 10,  // 模板信息流
    WanjaAdvertSceneInfoFlowExp2 = 11, // 模板信息流2.0
    WanjaAdvertSceneReward2 = 12,      // 激励视频2.0
    WanjaAdvertSceneInterFull = 13,    // 插屏-全屏2.0
    WanjaAdvertSceneInterHalf = 14,    // 插屏-半屏2.0
    WanjaAdvertSceneDrawCustom = 15    // Draw自渲染
};

#define WanjaWeakSelf __weak __typeof(self)weakSelf = self;

#define KWanjaScreenWidth    [UIScreen mainScreen].bounds.size.width
#define KWanjaScreenHeight   [UIScreen mainScreen].bounds.size.height
#define KWanjaStatusHeight [WanjaDevice wanja_statusBarHeight]
#define KWanjaNavigationHeight [WanjaDevice wanja_navigationBarHeight]
#define KWanjaTopHeight [WanjaDevice wanja_topHeight]
#define KWanjaTopOffset [WanjaDevice wanja_safeHeight]
#define KWanjaBottomOffset [WanjaDevice wanja_bottomOffset]
#define KWanjaTabbarHeight [WanjaDevice wanja_tabbarHeight]
#define KWanjaDeviceWidthScale ([UIScreen mainScreen].bounds.size.width)/375.0

#define KWanjaTokenAuthorization @"Authorization"
#define KWanjaLogHeaderLevel1 @"WanjaAD Protocol: "

/// FLS
#define KFLSConfigPrefix @"fulishe"
#define KFLSAdAppKey @"KFlsAdAppKey"    // fls内聚合appkey
#define KFLSAdConfig @"KFLSAdConfig"    // fls内config
#define KFLSAdConfigCreateTime @"KFLSAdConfigCreateTime" // fls内记录Config下载时间

#endif
