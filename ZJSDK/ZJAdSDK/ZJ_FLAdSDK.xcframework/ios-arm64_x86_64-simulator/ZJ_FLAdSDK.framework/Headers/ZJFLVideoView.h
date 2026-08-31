//
//  ZJFLVideoView.h
//  AdDemo
//
//  Created by lurich on 2021/9/8.
//

#import <UIKit/UIKit.h>
#import <AVKit/AVKit.h>
#import <ZJ_FLAdSDK/ZJFLVideoConfig.h>
#import <ZJ_FLAdSDK/ZJFLNativeAdRenderProtocol.h>

@class ZJFLLinearModel;

@class ZJFLVideoView;
@class ZJFLVideoPlayer;
@class ZJFLVideoReportContext;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - ZJFLVideoViewPlayerDelegate

/**
 *  ZJFLVideoView 播放器事件代理协议。
 *
 *  典型使用场景：
 *  - 原生模板广告（信息流 / Banner）：监听播放状态做曝光、完成上报
 *  - 插屏 / 开屏视频：监听 Stoped 后关闭广告页
 *  - 预加载场景：监听缓存下载成功/失败
 *
 *  注意：状态回调可能来自主线程；delegate 内避免同步阻塞操作。
 */
@protocol ZJFLVideoViewPlayerDelegate <NSObject>

/**
 *  播放器媒体状态变化回调。
 *
 *  状态枚举见 ZJFLMediaPlayerStatus（Initial → Loading → WillStart → Started/Playing → Paused/Stoped/Error）。
 *
 *  @param videoView  触发状态变化的视频视图
 *  @param status     当前媒体播放状态
 */
- (void)zjfl_nativeAdView:(ZJFLVideoView *)videoView playerStatusChanged:(ZJFLMediaPlayerStatus)status;

/** 视频 URL 整文件缓存下载成功（由 ZJFLVideoPlayer 下载完成后转发） */
-(void)zjfl_videoUrlCacheDownloadSuccess;

/**
 *  视频 URL 整文件缓存下载失败。
 *  @param error 失败原因，domain 为 ZJFLMaasErrorDomain，code 为 ZJFLErrorCode406
 */
-(void)zjfl_videoUrlCacheDownloadFailedWithError:(NSError *)error;

@end

#pragma mark - ZJFLVideoView

/**
 *  广告视频容器视图（UIView 子类）。
 *
 *  ## 典型接入流程
 *  ```
 *  ZJFLVideoView *videoView = [[ZJFLVideoView alloc] init];
 *  videoView.delegate = self;
 *  videoView.videoConfig = config;          // 自动播放 / 静音 / 循环等
 *  videoView.requestID = adRequestID;       // 与广告请求绑定，用于精准释放播放器
 *  [videoView renderWirhVideo:videoUrl Image:coverUrl];
 *  ```
 *
 *  ## 线程安全
 *  所有 UI 与 AVPlayer 操作均应在主线程；Block 回调已在主线程派发。
 */
@interface ZJFLVideoView : UIView

#pragma mark - 代理与配置

/** 播放器状态 / 缓存事件代理（weak，避免循环引用） */
@property (nonatomic, weak) id<ZJFLVideoViewPlayerDelegate> delegate;

/**
 *  是否启用 SDK 内部的可见性自动控制。
 *  默认 YES。设为 NO 时由业务方自行调用 video_play / video_pause。
 *  VAST、全屏插屏场景内部会忽略此开关。
 */
@property (nonatomic, assign) BOOL isAutoControl;

/** 视频播放配置：自动播放策略、静音、是否循环等，详见 ZJFLVideoConfig */
@property (nonatomic, strong) ZJFLVideoConfig *videoConfig;

/**
 *  广告请求 ID，与 ZJ_FLAdSDKVideoFreePlayerName 通知配合使用。
 *  同时作为 ZJFLVideoPlayer 的 playerID（若为空则使用 UUID）。
 */
@property (nonatomic, copy) NSString *requestID;

/** 当前播放进度（秒），只读，转发自 videoPlayer.currentTime */
@property (nonatomic, assign) NSTimeInterval currentTime;

/** 视频总时长（秒），只读，转发自 videoPlayer.totalTime */
@property (nonatomic, assign) NSTimeInterval duration;

/**
 *  是否为全屏插屏（开屏）场景。
 *  YES 时不添加模糊背景，暂停图标始终隐藏，可见性控制不启用。
 */
@property (nonatomic, assign) BOOL isFullInterStitial;

/** VAST ClickThrough 跳转 URL（VAST 场景由外部赋值） */
@property (nonatomic, copy) NSString *clickThrough;

/** VAST 点击监测 URL 数组 */
@property (nonatomic, strong) NSMutableArray *clickTrackingArr;

/**
 *  是否为 VAST 类型视频。
 *  YES 时：不走可见性控制；render 后不自动 video_play；暂停图标隐藏。
 */
@property (nonatomic, assign) BOOL isVast;

/** 广告配置的视频时长（秒），用于 VAST 等上报，非 AVAsset 实际时长 */
@property (nonatomic, assign) NSInteger videoTime;

/**
 *  是否为「纯视频 View」模式。
 *  YES 时不创建封面 backImgView 与高斯模糊背景，仅展示 playLayer。
 */
@property (nonatomic, assign) BOOL singleVideoView;

/** VAST Linear 模型，每个视频实例独立保存，供监测上报使用 */
@property (nonatomic, strong) ZJFLLinearModel *linearModel;

/** 底层播放器实例，懒创建，每个 ZJFLVideoView 独立持有（readonly） */
@property (nonatomic, strong, readonly) ZJFLVideoPlayer *videoPlayer;

/**
 *  广告位类型，
 */
@property (nonatomic, assign ) NSInteger adv_place_type;

/** init 时记录的顶层 VC，用于流量提示挂载与可见性校验（readonly） */
@property (nonatomic, weak, readonly) UIViewController *videoShowController;

#pragma mark - Block 回调（与 delegate 并存，按需选用）

/** 播放进度 0.0 ~ 1.0 */
@property(nonatomic , copy , readwrite)void (^playBlock)(CGFloat progress);

/** 播放进度明细：当前秒数、总时长、进度比 */
@property(nonatomic , copy , readwrite)void (^playTimeUpdateBlock)(NSTimeInterval currentTime, NSTimeInterval duration, CGFloat progress);

/** 暂停时触发（含可见性强制暂停、用户暂停、video_pause 等） */
@property(nonatomic , copy , readwrite)void (^playPause)(void);

/** 真正开始播放时触发（video_playing 成功执行后） */
@property(nonatomic , copy , readwrite)void (^playStart)(void);

/** 静音状态变化时触发 */
@property(nonatomic , copy , readwrite)void (^playMuteChange)(BOOL isMute);

#pragma mark - 渲染与预加载

/**
 *  渲染视频广告（主入口）。
 *
 *  内部流程：创建/复用 videoPlayer → 封面/模糊背景 → 构造 AVURLAsset →
 *  配置静音 → 按可见性策略 startPlay 或 pending → 添加 playLayer 与暂停图标 →
 *
 *  @param videoUrl  本地路径或 http(s) URL
 *  @param imageUrl  封面图 URL（http 开头则网络加载；否则从视频首帧异步抽取）
 */
- (void)renderWirhVideo:(NSString *)videoUrl Image:(nullable NSString *)imageUrl;

/**
 *  预加载视频到本地缓存（若已有缓存则不重复下载）。
 *  @return ZJFLVideoCacheStatus 缓存状态
 */
-(ZJFLVideoCacheStatus) preloadVideoUrlCache: (NSString *) videoUrl;

/**
 *  预加载视频（兼容旧 API，内部等同 preloadVideoUrlCache）。
 *  @return 固定返回 ZJFLVideoStatusPreload（url 无效时返回 ZJFLVideoStatusNull）
 */
-(ZJFLVideoCacheStatus) preloadVideoWithUrl: (NSString *) videoUrl;

#pragma mark - 播放控制

/** 从头 seek 到 0 并重新播放 */
- (void)replay;

/**
 *  按 autoPlayPolicy 决定是否播放（WiFi 策略下蜂窝网会延迟展示点击播放入口）。
 *  不会直接创建 AVPlayer，最终由 video_playing 执行。
 */
- (void)video_play;

/** 外部暂停入口：清除续播标记并 pause */
- (void)video_pause;

/**
 *  设置静音。
 *  @param muted YES 静音，NO 有声
 */
- (void)videoMuted:(BOOL)muted;

/** 释放 videoPlayer、移除 layer*/
-(void)freePlayer;

/** 获取当前播放器监测上报快照（VAST/曝光上报用） */
- (ZJFLVideoReportContext *)reportContext;

/** 当前播放器唯一标识（与 requestID 或 UUID 一致） */
- (NSString *)videoPlayerID;

@end

NS_ASSUME_NONNULL_END
