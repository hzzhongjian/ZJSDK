//
//  ZJ_MJKSelfRenderFeedData.h
//  ZJ_MJKAdSDK
//
//  Created by Harry Jiang on 2026/3/9.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class ZJ_MJKSelfRenderFeedAd;

@protocol IZJ_MJKSelfRenderFeedData <NSObject>
- (nullable UIImage *)contentImage;
- (nullable NSString *)contentImageUrl;
- (NSInteger)contentImageWidth;
- (NSInteger)contentImageHeight;
- (nullable UIImage *)brandIcon;
- (nullable NSString *)brandIconUrl;
- (NSInteger)brandIconWidth;
- (NSInteger)brandIconHeight;
- (NSString *)brandTitle;
- (NSString *)brandDesc;
- (BOOL)isVideo;
- (nullable UIView *)videoView;
- (NSInteger)videoWidth;
- (NSInteger)videoHeight;
- (NSInteger)videoDuration;
- (nullable UIImage *)adIcon;
- (NSInteger)adIconWidth;
- (NSInteger)adIconHeight;
- (nullable NSString *)adIconUrl;
@end

@protocol ZJ_MJKSelfRenderFeedAdEventDelegate <NSObject>

@optional

/**
 * 广告点击事件
 * @param feedAd 信息流广告对象
 */
- (void)onSelfRenderFeedAdClick:(ZJ_MJKSelfRenderFeedAd *)feedAd;

/**
 * 广告展示事件
 * @param feedAd 信息流广告对象
 */
- (void)onSelfRenderFeedAdShow:(ZJ_MJKSelfRenderFeedAd *)feedAd;

/**
 * 广告隐藏事件
 * @param feedAd 信息流广告对象
 */
- (void)onSelfRenderFeedAdHidden:(ZJ_MJKSelfRenderFeedAd *)feedAd;

/**
 * 广告曝光确认事件
 * @param feedAd 信息流广告对象
 * @param confirm 是否确认曝光
 */
- (void)onSelfRenderFeedAdExposure:(ZJ_MJKSelfRenderFeedAd *)feedAd confirm:(BOOL)confirm;

//广告内跳落地页打开回调
-(void)onSelfRenderFeedAdLandingPageStart:(ZJ_MJKSelfRenderFeedAd *)feedAd;

//广告内跳落地页关闭回调
-(void)onSelfRenderFeedAdLandingPageClose:(ZJ_MJKSelfRenderFeedAd *)feedAd;

@end

@protocol ZJ_MJKSelfRenderFeedInsideDelegate <NSObject>

@required

/**
 * 自定义渲染广告点击事件
 */
- (void)onSelfRenderClick;

/**
 * 自定义渲染广告曝光确认事件
 * @param adView 广告视图
 * @param confirm 是否确认曝光
 */
- (void)onSelfRenderExposure:(UIView *)adView confirm:(BOOL)confirm;

/**
 * 自定义渲染广告开始展示事件
 * @param adView 广告视图
 */
- (void)onSelfRenderShow:(UIView *)adView;

/**
 * 自定义渲染广告停止展示事件
 * @param adView 广告视图
 */
- (void)onSelfRenderStop:(UIView *)adView;

/**
 广告开始播放
 */
- (void)onSelfRendeVideoPlayerStart;

/**
 广告开始播放
 */
- (void)onSelfRendeVideoPlayerFinish ;

/**
 广告播放中
 */
- (void)onSelfRendeVideoPlayerProgress:(NSTimeInterval)timePlayed totalTime:(NSTimeInterval)totalTime ;

@end

@protocol ZJ_MJKSelfRenderVideoViewDelegate <NSObject>

@optional

/**
 * 视频准备好
 */
- (void)onVideoReady;

/**
 * 视频开始播放
 */
- (void)onVideoStart;

/**
 * 视频播放失败
 */
- (void)onVideoError:(NSError *)error;

/**
 * 视频播放进度
 * @param playTime 已播放时间
 * @param totalTime 视频总时长
 */
- (void)onVideoProgressWithPlayTime:(NSTimeInterval)playTime totalTime:(NSTimeInterval)totalTime;

/**
 * 视频完成播放
 */
- (void)onVideoComplete;

@end

@interface ZJ_MJKSelfRenderFeedData : NSObject <IZJ_MJKSelfRenderFeedData>

- (instancetype)initWithExtra:(NSDictionary<NSString *, id> *)extra
 selfRenderFeedInsideDelegate:(id<ZJ_MJKSelfRenderFeedInsideDelegate>)delegate;

- (void)registerSelfRenderViewsWithContext:(UIViewController *)context
                        selfRenderFeedView:(UIView *)selfRenderFeedView
                                 clickViews:(NSArray<UIView *> *)clickViews
             selfRenderFeedAdEventDelegate:(id<ZJ_MJKSelfRenderFeedAdEventDelegate>)eventDelegate;

/**
 广告事件回调
 */
@property (nonatomic, weak) id<ZJ_MJKSelfRenderFeedAdEventDelegate> selfRenderFeedAdEventDelegate;

/**
 视频广告播放回调
 */
@property (nonatomic, weak) id<ZJ_MJKSelfRenderVideoViewDelegate> selfRenderVideoViewDelegate;

/**
 更新视频尺寸
 */
- (void)updateVideoSize:(CGSize) videoSize;

/**
 手动暂停视频
 */
- (void)pauseVideo;

/**
 手动继续播放
 */
- (void)playVideo;

/**
 是否静音
 ZJ_MJKSelfRenderFeedAd初始化时配置了是否默认开启声音，这里可以进行操作声音
 播放开始后可以进行操作
 0是静音，声音范围0.0~1.0
 */
- (void)soundVolume:(CGFloat) volume ;

/*
 是否正在播放
 */
- (BOOL)videoPlaying;


/**
 销毁
 */
- (void)destroy;

@end

NS_ASSUME_NONNULL_END
