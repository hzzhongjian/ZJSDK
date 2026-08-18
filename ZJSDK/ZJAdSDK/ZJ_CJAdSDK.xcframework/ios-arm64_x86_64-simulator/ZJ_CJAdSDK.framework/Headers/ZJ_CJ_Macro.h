//
//  ZJ_CJ_Macro.h
//  ZJ_CJAdSDK
//
//  Created by coderqi on 2025/11/13.
//

#ifndef ZJ_CJ_Macro_h
#define ZJ_CJ_Macro_h

/// 广告类型
typedef NS_OPTIONS(NSUInteger, ZJ_CJAdType) {
    /// 信息流
    ZJ_CJAdTypeNative          = 1,
    /// 开屏
    ZJ_CJAdTypeSplash          = 2,
    /// banner
    ZJ_CJAdTypeBanner          = 3,
    /// 插屏
    ZJ_CJAdTypeInterstitial    = 4,
    /// 激励
    ZJ_CJAdTypeRewardVideo    = 5,
    /// 信息流自渲染
    ZJ_CJAdTypeFeedCustom      = 6,
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
typedef void(^ZJ_CJAdDataCallBackHandler)(NSArray * _Nullable array, NSError * _Nullable error);

/**
 * 视频播放器状态枚举
 */
typedef NS_ENUM(NSInteger, ZJ_CJVideoPlayerState) {
    ZJ_CJVideoPlayerStateUnknown = 0,  // 未知状态
    ZJ_CJVideoPlayerStateBuffering,    // 正在缓冲
    ZJ_CJVideoPlayerStatePlaying,      // 正在播放
    ZJ_CJVideoPlayerStatePaused,       // 已暂停
    ZJ_CJVideoPlayerStateStopped,      // 已停止
    ZJ_CJVideoPlayerStateCompleted,    // 播放完成
    ZJ_CJVideoPlayerStateFailed        // 播放失败
};

/**
 * 视频播放状态回调
 * @param state 当前视频播放状态
 * @param error 如果出现错误，包含错误信息
 */
typedef void(^ZJ_CJVideoPlayerStateCallback)(ZJ_CJVideoPlayerState state, NSError * _Nullable error);

/**
 * 视频播放进度回调
 * @param currentTime 当前播放时间（秒）
 * @param duration 视频总时长（秒）
 */
typedef void(^ZJ_CJVideoPlayerProgressCallback)(NSTimeInterval currentTime, NSTimeInterval duration);

/// 广告打开类
typedef NS_OPTIONS(NSUInteger, ZJ_CJAdOpenType) {
    /// push
    ZJ_CJAdOpenTypePush    = 1,
    /// Present
    ZJ_CJAdOpenTypePresent = 2,
};

/// 交互类型
typedef NS_ENUM(NSInteger, ZJ_CJAdInteractionType) {
    ZJ_CJAdInteractionTypeUnknown,        //unknown type
    ZJ_CJAdInteractionTypeApp,            //open download page in-app
    ZJ_CJAdInteractionTypeWeb,            //open webpage in-app
    ZJ_CJAdInteractionTypeDeepLink,       //open deeplink
    ZJ_CJAdInteractionTypeAppStore,       //open appstore
    ZJ_CJAdInteractionTypeSafari,         //open safari
    ZJ_CJAdInteractionTypeError           //can`t open landing page
};

/**以下为C2S bidding上报参数key**/
//竞胜方价格 单位：分
#define kZJ_CJAdMediaWinPrice   @"win_price"
//最大竞败方出价 单位：分
#define kZJ_CJAdMediaLossPrice  @"sec_price"
//竞败原因 0 未知 100价格低失败 200 超时失败
#define kZJ_CJAdMediaLossReason @"loss_reason"

/**以下为广告返回的拓展参数的key**/
// requestId
#define kZJ_CJAdRequestID @"request_id"

#endif /* ZJ_CJ_Macro_h */
