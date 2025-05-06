//
//  ZJSDKAdEnum.h
//  ZJSDKCore
//
//  Created by Rare on 2021/8/16.
//

#ifndef ZJSDKAdEnum_h
#define ZJSDKAdEnum_h



typedef NS_ENUM(NSUInteger, ZJMediaPlayerStatus) {
    ZJMediaPlayerStatusDefalt = 0,         // 初始状态
    ZJMediaPlayerStatusLoading = 1,         // 加载中
    ZJMediaPlayerStatusPlaying = 2,         // 开始播放
    ZJMediaPlayerStatusPaused = 3,          // 用户行为导致暂停
    ZJMediaPlayerStatusError = 4,           // 播放出错
    ZJMediaPlayerStatusStoped = 5,          // 播放停止
};


typedef NS_ENUM(NSInteger,ZJAdSDKLogLevel){
    ZJAdSDKLogLevelNone,
    ZJAdSDKLogLevelDebug,
    ZJAdSDKLogLevelWarning,
    ZJAdSDKLogLevelError,
};

typedef NS_ENUM(NSInteger, ZJAdPlatformType) {
    ZJAdPlatform_None,
    ZJAdPlatform_CSJ,
    ZJAdPlatform_GDT,
    ZJAdPlatform_MTG,
    ZJAdPlatform_KS,
    ZJAdPlatform_ZJ,
    ZJAdPlatform_YM,
    ZJAdPlatform_SIG,
    ZJAdPlatform_WW,
    ZJAdPlatform_Google,
    ZJAdPlatform_Baidu,
    ZJAdPlatform_Gromore,
    ZJAdPlatform_BeiZi,
    ZJAdPlatform_WM,
    ZJAdPlatform_Pangle,
    ZJAdPlatform_TANX,
    ZJAdPlatform_QM,
    ZJAdPlatform_OCTOPUS,
    ZJAdPlatform_YIKA,
    ZJAdPlatform_QIYUN,
    ZJAdPlatform_TaKu,
};

typedef NS_ENUM(NSInteger, ZJAdType){
    ZJAdType_Unknow                 = 0,
    ZJAdType_SPLASH                 = 1,
    ZJAdType_REWARD                 = 3,
    ZJAdType_H5                     = 4,
    ZJAdType_Banner                 = 5,//banner
    ZJAdType_Interstitial           = 6,//插屏
    ZJAdType_ExpressFullVideoFeed   = 7,//视频流 
    ZJAdType_ContentVideo           = 8,//视频内容 
    ZJAdType_Native                 = 9,//原生渲染 
    ZJAdType_NativeExpress          = 11,//信息流 
    ZJAdType_FullScreenVideo        = 12,//全屏视频
    ZJAdType_News                   = 21,//新闻资讯
    ZJAdType_WXMiniProgram          = 22
};

//穿山甲联盟建议加载图片大小的尺寸
typedef NS_ENUM(NSInteger, ZJProposalSize) {
    ZJProposalSize_Banner600_90,
    ZJProposalSize_Banner640_100,
    ZJProposalSize_Banner600_150,
    ZJProposalSize_Banner600_260,
    ZJProposalSize_Banner600_286,
    ZJProposalSize_Banner600_300,
    ZJProposalSize_Banner690_388,
    ZJProposalSize_Banner600_400,
    ZJProposalSize_Banner600_500,
    ZJProposalSize_Feed228_150,
    ZJProposalSize_Feed690_388,
    ZJProposalSize_Interstitial600_400,
    ZJProposalSize_Interstitial600_600,
    ZJProposalSize_Interstitial600_900,
    ZJProposalSize_DrawFullScreen
};

// 设置个性化推荐广告
typedef NS_ENUM(NSInteger, ZJSDKPersionalizedState) {
    ZJSDKPersionalizedState_OFF, // 关闭
    ZJSDKPersionalizedState_ON, // 开启
};

// 是否允许开启广告的程序化推荐
typedef NS_ENUM(NSInteger, ZJSDKProgrammaticRecommend) {
    ZJSDKProgrammaticRecommend_OFF,
    ZJSDKProgrammaticRecommend_ON,
};

// 自渲染广告点击跳转类型
typedef NS_ENUM(NSInteger, ZJSDKAdInteractionType) {
    ZJSDKAdInteractionType_Unknown,        //unknown type
    ZJSDKAdInteractionType_App,            //open downlaod page in app
    ZJSDKAdInteractionType_Web,            //open webpage in app
    ZJSDKAdInteractionType_DeepLink,       //open deeplink
    ZJSDKAdInteractionType_AppStore,       //open appstore
};

#endif /* ZJSDKAdEnum_h */
