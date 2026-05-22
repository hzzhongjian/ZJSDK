//
//  ZJ_CJ_Macro.h
//  ZJ_CJAdSDK
//
//  Created by coderqi on 2025/11/13.
//

#ifndef ZJ_CJ_Macro_h
#define ZJ_CJ_Macro_h

/// 广告类型
typedef NS_OPTIONS(NSUInteger, ZJ_CJ_AdType) {
    /// 信息流
    ZJCJAdTypeNative          = 1,
    /// 开屏
    ZJCJAdTypeSplash          = 2,
    /// banner
    ZJCJAdTypeBanner          = 3,
    /// 插屏
    ZJCJAdTypeInterstitial    = 4,
    /// 激励
    ZJCJAdTypeRewardVideo    = 5,
    /// 信息流自渲染
    ZJCJAdTypeFeedCustom      = 6,
};

/// 广告渲染类型
typedef NS_OPTIONS(NSInteger, ZJ_CJAdRenderType) {
    /// 默认值
    ZJ_CJAdRenderTypeDefault = -9999,
    /// sdk模版渲染
    ZJ_CJAdRenderTypeTemplate = 1,
    /// 媒体自渲染
    ZJ_CJAdRenderTypeCustom   = 2,
};

/// 广告数据请求回调
typedef void(^ZJ_CJ_AdDataCallBackHandler)(NSArray * _Nullable array, NSError * _Nullable error);

/**
 * 视频播放器状态枚举
 */
typedef NS_ENUM(NSInteger, ZJ_CJ_VideoPlayerState) {
    ZJ_CJ_VideoPlayerStateUnknown = 0,  // 未知状态
    ZJ_CJ_VideoPlayerStateBuffering,    // 正在缓冲
    ZJ_CJ_VideoPlayerStatePlaying,      // 正在播放
    ZJ_CJ_VideoPlayerStatePaused,       // 已暂停
    ZJ_CJ_VideoPlayerStateStopped,      // 已停止
    ZJ_CJ_VideoPlayerStateCompleted,    // 播放完成
    ZJ_CJ_VideoPlayerStateFailed        // 播放失败
};

/**
 * 视频播放状态回调
 * @param state 当前视频播放状态
 * @param error 如果出现错误，包含错误信息
 */
typedef void(^ZJ_CJ_VideoPlayerStateCallback)(ZJ_CJ_VideoPlayerState state, NSError * _Nullable error);

/**
 * 视频播放进度回调
 * @param currentTime 当前播放时间（秒）
 * @param duration 视频总时长（秒）
 */
typedef void(^ZJ_CJ_VideoPlayerProgressCallback)(NSTimeInterval currentTime, NSTimeInterval duration);

/// 广告打开类
typedef NS_OPTIONS(NSUInteger, ZJ_CJ_AdOpenType) {
    /// push
    ZJ_CJ_AdOpenTypePush    = 1,
    /// Present
    ZJ_CJ_AdOpenTypePresent = 2,
};

/// 交互类型
typedef NS_ENUM(NSInteger, ZJ_CJ_AdInteractionType) {
    ZJ_CJ_AdInteractionTypeUnknown,        //unknown type
    ZJ_CJ_AdInteractionTypeApp,            //open download page in-app
    ZJ_CJ_AdInteractionTypeWeb,            //open webpage in-app
    ZJ_CJ_AdInteractionTypeDeepLink,       //open deeplink
    ZJ_CJ_AdInteractionTypeAppStore,       //open appstore
    ZJ_CJ_AdInteractionTypeSafari,         //open safari
    ZJ_CJ_AdInteractionTypeError           //can`t open landing page
};

/**以下为C2S bidding上报参数key**/
//竞胜方价格 单位：分
#define kZJCJAdMediaWinPrice   @"win_price"
//最大竞败方出价 单位：分
#define kZJCJAdMediaLossPrice  @"sec_price"
//竞败原因 0 未知 100价格低失败 200 超时失败
#define kZJCJAdMediaLossReason @"loss_reason"

#endif /* ZJ_CJ_Macro_h */
