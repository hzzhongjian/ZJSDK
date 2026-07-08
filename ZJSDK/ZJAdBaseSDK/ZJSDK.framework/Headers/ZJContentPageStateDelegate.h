//
//  ZJContentPageStateDelegate.h
//  ZJSDK
//
//  Created by 麻明康 on 2023/1/6.
//  Copyright © 2023 zj. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ZJSDKCore/ZJContentInfo.h>
#import <ZJSDKCore/ZJContentAdapterStateDelegate.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZJContentPageVideoStateDelegate <NSObject>
@optional
/**
 * 视频开始播放
 * @param videoContent 内容模型
 */
- (void)zj_videoDidStartPlay:(id<ZJContentInfo>)videoContent;
/**
* 视频暂停播放
* @param videoContent 内容模型
*/
- (void)zj_videoDidPause:(id<ZJContentInfo>)videoContent;
/**
* 视频恢复播放
* @param videoContent 内容模型
*/
- (void)zj_videoDidResume:(id<ZJContentInfo>)videoContent;
/**
* 视频停止播放
* @param videoContent 内容模型
* @param finished     是否播放完成
*/
- (void)zj_videoDidEndPlay:(id<ZJContentInfo>)videoContent isFinished:(BOOL)finished;
/**
* 视频播放失败
* @param videoContent 内容模型
* @param error        失败原因
*/
- (void)zj_videoDidFailedToPlay:(id<ZJContentInfo>)videoContent withError:(NSError *)error;

/// 一下四个代理方法只在横板视频里面调用
/// 进入横版视频详情页
/// @param viewController 详情页VC
/// @param content 视频信息
- (void)zj_horizontalFeedVideoDetailDidEnter:(UIViewController *)viewController contentInfo:(id<ZJContentInfo>)content;

/// 离开横版视频详情页
/// @param viewController 详情页VC
- (void)zj_horizontalFeedVideoDetailDidLeave:(UIViewController *)viewController;

/// 视频详情页appear
/// @param viewController 详情页VC
- (void)zj_horizontalFeedVideoDetailDidAppear:(UIViewController *)viewController;

/// 详情页disappear
/// @param viewController 详情页VC
- (void)zj_horizontalFeedVideoDetailDidDisappear:(UIViewController *)viewController;


@end


@protocol ZJContentPageStateDelegate <NSObject>

@optional
/**
* 内容展示
* @param content 内容模型
*/
- (void)zj_contentDidFullDisplay:(id<ZJContentInfo>)content;
/**
* 内容隐藏
* @param content 内容模型
*/
- (void)zj_contentDidEndDisplay:(id<ZJContentInfo>)content;
/**
* 内容暂停显示，ViewController disappear或者Application resign active
* @param content 内容模型
*/
- (void)zj_contentDidPause:(id<ZJContentInfo>)content;
/**
* 内容恢复显示，ViewController appear或者Application become active
* @param content 内容模型
*/
- (void)zj_contentDidResume:(id<ZJContentInfo>)content;

/// 任务完成回调
- (void)zjAdapter_contentTaskComplete:(id<ZJContentInfo>)content;

@end

/// 短剧内容加载成功和失败的代理方法，根据加载成功/失败来判断是否可以加载短剧页面
@protocol ZJContentPageLoadCallBackDelegate <NSObject>

@optional
/// 内容加载成功
- (void)zj_contentPageLoadSuccess;

/// 内容加载失败
- (void)zj_contentPageLoadFailure:(NSError *)error;

@end


// 从csj开始使用
/// 短剧播放器回调
@protocol ZJShortPlayPlayerDelegate <NSObject>

@optional

/*! @abstract 视频切换时的回调 */
- (void)zj_shortplayDrawVideoCurrentVideoChanged:(NSInteger)index adapter:(id<ZJContentInfo>)content;

/*! @abstract 加载失败按钮点击重试回调 */
- (void)zj_shortplayDrawVideoDidClickedErrorButtonRetry:(id<ZJContentInfo>)content;

/*! @abstract 默认关闭按钮被点击的回调 */
- (void)zj_shortplayDrawVideoCloseButtonClicked:(id<ZJContentInfo>)content;

/*! @abstract 数据刷新完成回调 */
- (void)zj_shortplayDrawVideoDataRefreshCompletion:(NSError *)error content:(id<ZJContentInfo>)content;

/*! @abstract tab栏切换控制器的回调*/
- (void)zj_shortplayPageViewControllerSwitchToIndex:(NSInteger)index content:(id<ZJContentInfo>)content;

/**! @abstract 推荐页面底部banner视图**/
- (UIView *)zj_shortplayDrawVideoVCBottomBannerView:(UIViewController *)vc content:(id<ZJContentInfo>)content;

@end


// 广告回调
@protocol ZJShortPlayAdDelegate <NSObject>

@optional

/*! @abstract 发起广告请求 */
- (void)zj_shortplaySendAdRequest:(id<ZJContentInfo>)content;

/*! @abstract 广告加载成功 */
- (void)zj_shortplayAdLoadSuccess:(id<ZJContentInfo>)content;

/*! @abstract 广告加载失败 */
- (void)zj_shortplayAdLoadFail:(id<ZJContentInfo>)content error:(NSError *)error;

/*! @abstract 广告填充失败 */
- (void)zj_shortplayAdFillFail:(id<ZJContentInfo>)content;

/*! @abstract 广告曝光 */
- (void)zj_shortplayAdWillShow:(id<ZJContentInfo>)content;

/*! @abstract 视频广告开始播放 */
- (void)zj_shortplayVideoAdStartPlay:(id<ZJContentInfo>)content;

/*! @abstract 视频广告暂停播放 */
- (void)zj_shortplayVideoAdPause:(id<ZJContentInfo>)content;

/*! @abstract 视频广告继续播放 */
- (void)zj_shortplayVideoAdContinue:(id<ZJContentInfo>)content;

/*! @abstract 视频广告停止播放 */
- (void)zj_shortplayVideoAdOverPlay:(id<ZJContentInfo>)content;

/*! @abstract 点击广告 */
- (void)zj_shortplayClickAdViewEvent:(id<ZJContentInfo>)content;
/*! @abstract 广告缓冲 */
- (void)zj_shortplayVideoBufferEvent:(id<ZJContentInfo>)content;

/*! @abstract 激励视频广告结束 */
- (void)zj_shortplayVideoRewardFinishEvent:(id<ZJContentInfo>)content;

/*! @abstract 激励视频广告跳过 */
- (void)zj_shortplayVideoRewardSkipEvent:(id<ZJContentInfo>)content;

@end


// 业务接口回调
@protocol ZJShortPlayInterfaceDelegate <NSObject>

/*! @abstract 解锁流程开始 */
- (void)zj_shortplayPlayletDetailUnlockFlowStart:(id<ZJContentInfo>)content;

/*! @abstract 解锁流程取消 */
- (void)zj_shortplayPlayletDetailUnlockFlowCancel:(id<ZJContentInfo>)content;

/**用来控制是否自定义解锁弹窗的**/
- (BOOL)zj_shortplayPlayletDetailCustomUnlockView;

/*! 自定义解锁弹窗 cancelUnlockCallback取消回调，unlockCallback确认的回调 */
- (void)zj_shortplayPlayletDetailUnlockFlowCancelUnlock:(void (^)(void))cancelUnlockCallback
                                                unlockCallback:(void(^)(void))unlockCallback;

/*! @abstract 解锁流程结束，回调解锁结果
 *  - success: 是否解锁成功
 *   - error: 解锁失败错误信息
 */
- (void)zj_shortplayPlayletDetailUnlockFlowEnd:(id<ZJContentInfo>)content
                           success:(BOOL)success
                             error:(NSError * _Nullable)error;

@optional

/*! @abstract 点击混排中进入跳转播放页的按钮 */
- (void)zj_shortplayClickEnterView:(id<ZJContentInfo>)content;

/*! @abstract 本剧集观看完毕，切到下一部短剧回调 */
- (void)zj_shortplayNextPlayletWillPlay:(id<ZJContentInfo>)content;

- (UIView *)zj_shortplayPlayletDetailBottomBanner:(id<ZJContentInfo>)content;

@end


// 自定义详情页cell试图
@protocol ZJShortPlayCustomViewDelegate <NSObject>

/// 创建自定义View直接返回，外部不要持有，cell自己持有复用
/// @param cell 短剧的cell
- (UIView *)zj_shortplayPlayletDetailCellCustomView:(UITableViewCell *)cell;

/// 根据数据更新UI
/// @param cell 短剧的cell
/// @param customView `djx_playletDetailCellCustomView:`返回的自定义View，短剧的cell内部会持有
/// @param playletInfo 短剧的数据
- (void)zj_shortplayPlayletDetailCell:(UITableViewCell *)cell updateCustomView:(UIView *)customView withPlayletData:(id)playletInfo;

/// 当cell执行到layoutSubviews时会回调此协议方法
/// @param cell 短剧的cell
/// @param customView `djx_playletDetailCellCustomView:`返回的自定义View
- (void)zj_shortplayPlayletDetailCell:(UITableViewCell *)cell layoutSubviews:(UIView *)customView;

/// 当cell执行到layoutSubviews后会回调此协议方法
/// @param cell 短剧的cell
/// @param customView `djx_playletDetailCellCustomView:`返回的自定义View
- (void)zj_shortplayPlayletDetailCell:(UITableViewCell *)cell afterLayoutSubviews:(UIView *)customView;

@end


/// 自定义Draw流的subview
@protocol ZJShortPlayCustomDrawAdViewDelegate <NSObject>

- (UIView *)zj_shortplayDetailCellCreateAdView:(UITableViewCell *)cell adInputIndex:(NSUInteger)adIndex;

- (void)zj_shortplayDetailCell:(UITableViewCell *)cell bindDataToDrawAdView:(UIView *)drawAdView adInputIndex:(NSUInteger)adIndex;

@optional

- (void)zj_shortplayDetailCell:(UITableViewCell *)cell layoutSubview:(UIView *)drawAdView adInputIndex:(NSUInteger)adIndex;

- (void)zj_shortplayDetailCell:(UITableViewCell *)cell willDisplayDrawAdView:(UIView *)drawAdView adInputIndex:(NSUInteger)adIndex;

- (void)zj_shortplayDetailCell:(UITableViewCell *)cell didEndDisplayDrawAdView:(UIView *)drawAdView adInputIndex:(NSUInteger)adIndex;


@end


/// 滑滑溜底部自定义Banner广告
@protocol ZJShortPlayDrawVideoViewControllerBannerDelegate <NSObject>

- (UIView *)zj_shortplayDrawVideoVCBottomBannerView:(UIViewController *)vc;

@end

NS_ASSUME_NONNULL_END
