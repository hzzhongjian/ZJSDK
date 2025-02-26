//
//  ZJTubePageTierLoader.h
//  ZJSDK
//
//  Created by 麻明康 on 2025/1/8.
//  Copyright © 2025 zj. All rights reserved.
//

#import <ZJSDK/ZJSDK.h>
#import <ZJSDKCore/ZJTubePageConfig.h>

NS_ASSUME_NONNULL_BEGIN

@class ZJTubePageTierLoader;

@protocol ZJTubePageTierLoaderStateDelegate <NSObject>

/// 内容展示
- (void)zj_contentLoaderDidFullDisplay:(id<ZJContentInfo>)videoContent;

/// 内容隐藏
- (void)zj_contentLoaderDidEndDisplay:(id<ZJContentInfo>)videoContent;

/// 内容暂停显示
- (void)zj_contentLoaderDidPause:(id<ZJContentInfo>)videoContent;

/// 内容恢复显示
- (void)zj_contentLoaderDidResume:(id<ZJContentInfo>)videoContent;

/// 任务完成回调
- (void)zj_contentLoaderTaskComplete:(id<ZJContentInfo>)content;

@end

@protocol ZJTubePageTierLoaderVideoStateDelegate <NSObject>

/// 视频开始播放
- (void)zj_videoLoaderDidStartPlay:(id<ZJContentInfo>)videoContent;

/// 视频暂停播放
- (void)zj_videoLoaderDidPause:(id<ZJContentInfo>)videoContent;

///视频恢复播放
- (void)zj_videoLoaderDidResume:(id<ZJContentInfo>)videoContent;

/// 视频停止播放
- (void)zj_videoLoaderDidEndPlay:(id<ZJContentInfo>)videoContent isFinished:(BOOL)isFinished;

/// 视频播放失败
- (void)zj_videoLoaderDidFailedToPlay:(id<ZJContentInfo>)videoContent withError:(NSError *)error;

@end

// 短剧播放器回调
@protocol ZJTubePageTierLoaderPlayerCallbackDelegate <NSObject>

/*! @abstract 视频切换时的回调 */
- (void)zjTubePageTierLoader_shortplayDrawVideoCurrentVideoChanged:(NSInteger)index adapter:(id<ZJContentInfo>)content;

/*! @abstract 加载失败按钮点击重试回调 */
- (void)zjTubePageTierLoader_shortplayDrawVideoDidClickedErrorButtonRetry:(id<ZJContentInfo>)content;

/*! @abstract 默认关闭按钮被点击的回调 */
- (void)zjTubePageTierLoader_shortplayDrawVideoCloseButtonClicked:(id<ZJContentInfo>)content;

/*! @abstract 数据刷新完成回调 */
- (void)zjTubePageTierLoader_shortplayDrawVideoDataRefreshCompletion:(NSError *)error content:(id<ZJContentInfo>)content;

/*! @abstract tab栏切换控制器的回调*/
- (void)zjTubePageTierLoader_shortplayPageViewControllerSwitchToIndex:(NSInteger)index content:(id<ZJContentInfo>)content;

@end

// 广告回调
@protocol ZJTubePageTierLoaderAdCallbackDelegate <NSObject>

@optional

/*! @abstract 发起广告请求 */
- (void)zjTubePageTierLoader_shortplaySendAdRequest:(id<ZJContentInfo>)content;

/*! @abstract 广告加载成功 */
- (void)zjTubePageTierLoader_shortplayAdLoadSuccess:(id<ZJContentInfo>)content;

/*! @abstract 广告加载失败 */
- (void)zjTubePageTierLoader_shortplayAdLoadFail:(id<ZJContentInfo>)content error:(NSError *)error;

/*! @abstract 广告填充失败 */
- (void)zjTubePageTierLoader_shortplayAdFillFail:(id<ZJContentInfo>)content;

/*! @abstract 广告曝光 */
- (void)zjTubePageTierLoader_shortplayAdWillShow:(id<ZJContentInfo>)content;

/*! @abstract 视频广告开始播放 */
- (void)zjTubePageTierLoader_shortplayVideoAdStartPlay:(id<ZJContentInfo>)content;

/*! @abstract 视频广告暂停播放 */
- (void)zjTubePageTierLoader_shortplayVideoAdPause:(id<ZJContentInfo>)content;

/*! @abstract 视频广告继续播放 */
- (void)zjTubePageTierLoader_shortplayVideoAdContinue:(id<ZJContentInfo>)content;

/*! @abstract 视频广告停止播放 */
- (void)zjTubePageTierLoader_shortplayVideoAdOverPlay:(id<ZJContentInfo>)content;

/*! @abstract 点击广告 */
- (void)zjTubePageTierLoader_shortplayClickAdViewEvent:(id<ZJContentInfo>)content;
/*! @abstract 广告缓冲 */
- (void)zjTubePageTierLoader_shortplayVideoBufferEvent:(id<ZJContentInfo>)content;

/*! @abstract 激励视频广告结束 */
- (void)zjTubePageTierLoader_shortplayVideoRewardFinishEvent:(id<ZJContentInfo>)content;

/*! @abstract 激励视频广告跳过 */
- (void)zjTubePageTierLoader_shortplayVideoRewardSkipEvent:(id<ZJContentInfo>)content;

@end


// 业务接口回调
@protocol ZJTubePageTierLoaderInterfaceCallbackDelegate <NSObject>

/*! @abstract 解锁流程开始 */
- (void)zjTubePageTierLoader_shortplayPlayletDetailUnlockFlowStart:(id<ZJContentInfo>)content;

/*! @abstract 解锁流程取消 */
- (void)zjTubePageTierLoader_shortplayPlayletDetailUnlockFlowCancel:(id<ZJContentInfo>)content;


/*! @abstract 解锁流程结束，回调解锁结果
 *  - success: 是否解锁成功
 *   - error: 解锁失败错误信息
 */
- (void)zjTubePageTierLoader_shortplayPlayletDetailUnlockFlowEnd:(id<ZJContentInfo>)content
                           success:(BOOL)success
                             error:(NSError * _Nullable)error;

@optional

/*! @abstract 点击混排中进入跳转播放页的按钮 */
- (void)zjTubePageTierLoader_shortplayClickEnterView:(id<ZJContentInfo>)content;

/*! @abstract 本剧集观看完毕，切到下一部短剧回调 */
- (void)zjTubePageTierLoader_shortplayNextPlayletWillPlay:(id<ZJContentInfo>)content;

- (UIView *)zjTubePageTierLoader_shortplayPlayletDetailBottomBanner:(id<ZJContentInfo>)content;

@end

// 自定义详情页cell试图回调
@protocol ZJTubePageTierLoaderCustomViewCallBackDelegate <NSObject>

/// 创建自定义View直接返回，外部不要持有，cell自己持有复用
/// @param cell 短剧的cell
- (UIView *)zjTubePageTierLoader_shortplayPlayletDetailCellCustomView:(UITableViewCell *)cell;
/// 根据数据更新UI
/// @param cell 短剧的cell
/// @param customView `djx_playletDetailCellCustomView:`返回的自定义View，短剧的cell内部会持有
/// @param playletInfo 短剧的数据
- (void)zjTubePageTierLoader_shortplayPlayletDetailCell:(UITableViewCell *)cell updateCustomView:(UIView *)customView withPlayletData:(id)playletInfo;

/// 当cell执行到layoutSubviews时会回调此协议方法
/// @param cell 短剧的cell
/// @param customView `djx_playletDetailCellCustomView:`返回的自定义View
- (void)zjTubePageTierLoader_shortplayPlayletDetailCell:(UITableViewCell *)cell layoutSubviews:(UIView *)customView;

/// 当cell执行到layoutSubviews后会回调此协议方法
/// @param cell 短剧的cell
/// @param customView `djx_playletDetailCellCustomView:`返回的自定义View
- (void)zjTubePageTierLoader_shortplayPlayletDetailCell:(UITableViewCell *)cell afterLayoutSubviews:(UIView *)customView;

@end

// 自定义Draw流的subview回调
@protocol ZJTubePageTierLoaderCustomDrawAdViewCallBackDelegate <NSObject>

- (UIView *)zjTubePageTierLoader_shortplayDetailCellCreateAdView:(UITableViewCell *)cell adInputIndex:(NSUInteger)adIndex;

- (void)zjTubePageTierLoader_shortplayDetailCell:(UITableViewCell *)cell bindDataToDrawAdView:(UIView *)drawAdView adInputIndex:(NSUInteger)adIndex;

@optional

- (void)zjTubePageTierLoader_shortplayDetailCell:(UITableViewCell *)cell layoutSubview:(UIView *)drawAdView adInputIndex:(NSUInteger)adIndex;

- (void)zjTubePageTierLoader_shortplayDetailCell:(UITableViewCell *)cell willDisplayDrawAdView:(UIView *)drawAdView adInputIndex:(NSUInteger)adIndex;

- (void)zjTubePageTierLoader_shortplayDetailCell:(UITableViewCell *)cell didEndDisplayDrawAdView:(UIView *)drawAdView adInputIndex:(NSUInteger)adIndex;


@end


// 滑滑溜底部自定义Banner广告
@protocol ZJTubePageTierLoaderDrawVideoViewBannerCallbackDelegate <NSObject>

- (UIView *)zjTubePageTierLoader_shortplayDrawVideoVCBottomBannerView:(UIViewController *)vc adapter:(ZJTubePageAdapter *)adapter;

@end



@interface ZJTubePageTierLoader : ZJTierAdLoader

@property (nonatomic, weak) id <ZJTubePageTierLoaderStateDelegate> stateDelegate;

@property (nonatomic, weak) id <ZJTubePageTierLoaderVideoStateDelegate> videoStateDelegate;

/// 短剧播放器回调
@property (nonatomic, weak) id <ZJTubePageTierLoaderPlayerCallbackDelegate> playerCallbackDelegate;

/// 广告回调
@property (nonatomic, weak) id <ZJTubePageTierLoaderAdCallbackDelegate> adCallbackDelegate;

/// 业务接口回调
@property (nonatomic, weak) id <ZJTubePageTierLoaderInterfaceCallbackDelegate> interfaceCallbackDelegate;

/// 自定义详情页cell试图回调
@property (nonatomic, weak) id <ZJTubePageTierLoaderCustomViewCallBackDelegate> customViewCallBackDelegate;

/// 自定义Draw流的subview回调
@property (nonatomic, weak) id <ZJTubePageTierLoaderCustomDrawAdViewCallBackDelegate> customDrawAdViewCallBackDelegate;

/// 滑滑溜底部自定义Banner广告
@property (nonatomic, weak) id <ZJTubePageTierLoaderDrawVideoViewBannerCallbackDelegate> drawVideoViewBannerCallbackDelegate;


@property (nonatomic, strong) ZJTubePageConfig *tubePageConfig;

@end

NS_ASSUME_NONNULL_END
