//
//  WanjaTimeTools.h
//  WanjaCoreSDK
//
//  Created by guantou on 2019/12/10.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 开启外部错误log
 */
UIKIT_EXTERN BOOL Wanja_OpenTheLog;

/**
 应用内部调试log
 */
//  是否开启请求时长log
UIKIT_EXTERN BOOL Wanja_RequestTimeLog;
//  是否开启生命周期log
UIKIT_EXTERN BOOL Wanja_OpenCycleLog;
//  是否开启广告请求log
UIKIT_EXTERN BOOL Wanja_OpenAdRequestLog;
//  是否开启广告返回log
UIKIT_EXTERN BOOL Wanja_OpenAdResponseLog;
//  是否开启广告返回转化数据log
UIKIT_EXTERN BOOL Wanja_OpenAdDisposeResponseLog;
//  是否开启心跳请求log
UIKIT_EXTERN BOOL Wanja_OpenHeartbeatRequestLog;
//  是否开启心跳返回log
UIKIT_EXTERN BOOL Wanja_OpenHeartbeatResponseLog;
//  是否开启Log请求log
UIKIT_EXTERN BOOL Wanja_OpenLogRequestLog;
//  是否开启Log返回log
UIKIT_EXTERN BOOL Wanja_OpenLogResponseLog;
//  是否开启内部其他log
UIKIT_EXTERN BOOL Wanja_OpenOtherLog;
//  是否开启内部错误log
UIKIT_EXTERN BOOL Wanja_OpenErrorLog;
//  是否开启渠道上报log
UIKIT_EXTERN BOOL Wanja_OpenChannelReportLog;
//  是否开启Wanja上报log
UIKIT_EXTERN BOOL Wanja_OpenWanjaReportLog;

/**
 渠道是否初始化
 */
//UIKIT_EXTERN BOOL kChannelFalconInitConfiguration;
UIKIT_EXTERN BOOL kWanjaChannelBUAdInitConfiguration;

/**
 渠道名称
 */
static NSString *const kChannelWanja = @"wanjaopus";
//static NSString *const kChannelFalcon = @"lieying";

/**
 网络超时时长
 */
static CGFloat const kWanjaAdRequestTime = 5.0f;
static CGFloat const kWanjaReportRequestTime = 15.0f;

static CGFloat const kWanjaLogRequestTime = 1800;

static NSString *const kWanjaLogRequestLastTime = @"WanjaLogRequestLastTime";

/**
 静态
 */
static NSString *const kWanjaDefaultConfigure = @"WanjaDefaultConfigure";
static NSString *const kWanjaLandingPageBackDone = @"WanjaLandingPageBackDone";
static NSString *const kWanjaCrashDict = @"kWanjaCrashDict";

//  处理JS使用的静态字段
static NSString *const kWanja_JSBackGotoPage = @"wanja://GotoPage";
static NSString *const kWanja_JSBackCallNo = @"wanja://CallNo";
static NSString *const kWanja_JSBackClosePage = @"wanja://ClosePage";
static NSString *const kWanja_JSBackDownload = @"wanja://Download";
static NSString *const kWanja_JSBackDeepLink = @"wanja://DeepLink";

static NSString * _Nonnull const WanjaLoaderInters = @"WanjaAdInterstitialAd";
static NSString * _Nonnull const WanjaLoaderVideo = @"WanjaAdVideoAd";
static NSString * _Nonnull const WanjaLoaderSplash = @"WanjaSplashAd";
static NSString * _Nonnull const WanjaLoaderBanner = @"WanjaAdBannerAd";
static NSString * _Nonnull const WanjaLoaderFlow = @"WanjaAdFlowAd";

static NSString * _Nonnull const WanjaLoaderCsjInters = @"WanjaCsjExpInterstitialAd";
//static NSString * _Nonnull const WanjaLoaderCsjDraw = @"WanjaCsjDrawAd";
//static NSString * _Nonnull const WanjaLoaderCsjDrawCustom = @"WanjaCsjDrawCustomAd";
static NSString * _Nonnull const WanjaLoaderCsjVideo = @"WanjaCsjRewardVideoAd";
static NSString * _Nonnull const WanjaLoaderCsjSplash = @"WanjaCsjSplashAd";
//static NSString * _Nonnull const WanjaLoaderCsjFsVideo = @"WanjaCsjFullScreenAd";
static NSString * _Nonnull const WanjaLoaderCsjBanner = @"WanjaCsjBannerAd";
//static NSString * _Nonnull const WanjaLoaderCsjCustomFlow = @"WanjaCsjFlowCustomAd";
static NSString * _Nonnull const WanjaLoaderCsjFlow = @"WanjaCsjFlowAd";

static NSString * _Nonnull const WanjaLoaderGdtInters = @"WanjaGdtExpInterstitialAd";
//static NSString * _Nonnull const WanjaLoaderGdtDraw = @"WanjaGdtDrawAd";
//static NSString * _Nonnull const WanjaLoaderGdtDrawCustom = @"WanjaGdtDrawCustomAd";
static NSString * _Nonnull const WanjaLoaderGdtVideo = @"WanjaGdtRewardVideoAd";
static NSString * _Nonnull const WanjaLoaderGdtSplash = @"WanjaGdtSplashAd";
//static NSString * _Nonnull const WanjaLoaderGdtFsVideo = @"WanjaGdtFullScreenAd";
static NSString * _Nonnull const WanjaLoaderGdtBanner = @"WanjaGdtBannerAd";
//static NSString * _Nonnull const WanjaLoaderCsjCustomFlow = @"WanjaGdtFlowCustomAd";
static NSString * _Nonnull const WanjaLoaderGdtFlow = @"WanjaGdtFlowAd";

static NSString * _Nonnull const WanjaLoaderKsInters = @"WanjaKsExpInterstitialAd";
//static NSString * _Nonnull const WanjaLoaderKsDraw = @"WanjaKsDrawAd";
static NSString * _Nonnull const WanjaLoaderKsVideo = @"WanjaKsRewardVideoAd";
static NSString * _Nonnull const WanjaLoaderKsSplash = @"WanjaKsSplashAd";
//static NSString * _Nonnull const WanjaLoaderKsFsVideo = @"WanjaKsFullScreenAd";
//static NSString * _Nonnull const WanjaLoaderKsCustomFlow = @"WanjaKsFlowCustomAd";
static NSString * _Nonnull const WanjaLoaderKsFlow = @"WanjaKsFlowAd";

static NSString * _Nonnull const WanjaLoaderBdInters = @"WanjaBdInterstitialAd";
static NSString * _Nonnull const WanjaLoaderBdExpInters = @"WanjaBdExpInterstitialAd";
static NSString * _Nonnull const WanjaLoaderBdDraw = @"WanjaBdDrawVideoAd";
static NSString * _Nonnull const WanjaLoaderBdVideo = @"WanjaBdRewardVideoAd";
static NSString * _Nonnull const WanjaLoaderBdSplash = @"WanjaBdSplashAd";
static NSString * _Nonnull const WanjaLoaderBdFsVideo = @"WanjaBdFullScreenAd";
static NSString * _Nonnull const WanjaLoaderBdBanner = @"WanjaBdBannerAd";
static NSString * _Nonnull const WanjaLoaderBdCustomFlow = @"WanjaBdCustomFlowAd";
static NSString * _Nonnull const WanjaLoaderBdFlow = @"WanjaBdFlowAd";

static NSString * _Nonnull const WanjaLoaderLyInters = @"WanjaLyInterstitialAd";
static NSString * _Nonnull const WanjaLoaderLyVideo = @"WanjaLyVideoAd";
static NSString * _Nonnull const WanjaLoaderLySplash = @"WanjaLySplashAd";
static NSString * _Nonnull const WanjaLoaderLyBanner = @"WanjaLyBannerAd";
static NSString * _Nonnull const WanjaLoaderLyCustomFlow = @"WanjaLyFlowCustomAd";
static NSString * _Nonnull const WanjaLoaderLyFlow = @"WanjaLyFlowAd";

static NSString * _Nonnull const APPCsjAdAdapter = @"WanjaCsjAdAdapter";
static NSString * _Nonnull const APPGdtAdAdapter = @"WanjaGdtAdAdapter";
static NSString * _Nonnull const APPKsAdAdapter = @"WanjaKsAdapter";
static NSString * _Nonnull const APPBdAdAdapter = @"WanjaBdAdAdapter";
static NSString * _Nonnull const APPLyAdAdapter = @"WanjaLyAdAdapter";



static dispatch_queue_t wanja_queue_static_configure() {
    static dispatch_queue_t wanja_queue_configure;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        wanja_queue_configure = dispatch_queue_create("com.lvjunxue.wanjaQueue.configure", DISPATCH_QUEUE_SERIAL);
    });
    return wanja_queue_configure;
}

static dispatch_queue_t wanja_queue_static_adRequest() {
    static dispatch_queue_t wanja_queue_adRequest;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        wanja_queue_adRequest = dispatch_queue_create("com.lvjunxue.wanjaQueue.adRequest", DISPATCH_QUEUE_CONCURRENT);
    });
    return wanja_queue_adRequest;
}

static dispatch_queue_t wanja_queue_static_adReport() {
    static dispatch_queue_t wanja_queue_adReport;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        wanja_queue_adReport = dispatch_queue_create("com.lvjunxue.wanjaQueue.adReport", DISPATCH_QUEUE_SERIAL);
    });
    return wanja_queue_adReport;
}

static dispatch_queue_t wanja_queue_static_offLineReport() {
    static dispatch_queue_t wanja_queue_offLineReport;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        wanja_queue_offLineReport = dispatch_queue_create("com.lvjunxue.wanjaQueue.offLineReport", DISPATCH_QUEUE_SERIAL);
    });
    return wanja_queue_offLineReport;
}

static dispatch_queue_t wanja_queue_group_request() {
    static dispatch_queue_t wanja_queue_groupRequest;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        wanja_queue_groupRequest = dispatch_queue_create("com.lvjunxue.wanjaQueue.groupRequest", DISPATCH_QUEUE_CONCURRENT);
    });
    return wanja_queue_groupRequest;
}

static dispatch_queue_t wanja_queue_catch_manager() {
    static dispatch_queue_t wanja_queue_catchManager;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        wanja_queue_catchManager = dispatch_queue_create("com.lvjunxue.wanjaQueue.catchManager", DISPATCH_QUEUE_SERIAL);
    });
    return wanja_queue_catchManager;
}

static dispatch_queue_t wanja_queue_normal_request() {
    static dispatch_queue_t wanja_queue_normalRequest;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        wanja_queue_normalRequest = dispatch_queue_create("com.lvjunxue.wanjaQueue.normalRequest", DISPATCH_QUEUE_CONCURRENT);
    });
    return wanja_queue_normalRequest;
}
