//
//  ZJContentAdapterStateProtocol.h
//  ZJSDKCore
//
//  Created by 麻明康 on 2023/1/6.
//

#import <Foundation/Foundation.h>
#import <ZJSDKCore/ZJContentInfo.h>

NS_ASSUME_NONNULL_BEGIN

@class ZJTubePageAdapter;

@protocol ZJAdapterContentAdapterVideoStateProtocol <NSObject>
/**
 * 视频开始播放
 * @param videoContent 内容模型
 */
- (void)zjAdapter_videoDidStartPlay:(id<ZJContentInfo>)videoContent;
/**
* 视频暂停播放
* @param videoContent 内容模型
*/
- (void)zjAdapter_videoDidPause:(id<ZJContentInfo>)videoContent;
/**
* 视频恢复播放
* @param videoContent 内容模型
*/
- (void)zjAdapter_videoDidResume:(id<ZJContentInfo>)videoContent;
/**
* 视频停止播放
* @param videoContent 内容模型
* @param finished     是否播放完成
*/
- (void)zjAdapter_videoDidEndPlay:(id<ZJContentInfo>)videoContent isFinished:(BOOL)finished;
/**
* 视频播放失败
* @param videoContent 内容模型
* @param error        失败原因
*/
- (void)zjAdapter_videoDidFailedToPlay:(id<ZJContentInfo>)videoContent withError:(NSError *)error;
@end


@protocol ZJContentAdapterStateProtocol <NSObject>
/**
* 内容展示
* @param content 内容模型
*/
- (void)zjAdapter_contentDidFullDisplay:(id<ZJContentInfo>)content;
/**
* 内容隐藏
* @param content 内容模型
*/
- (void)zjAdapter_contentDidEndDisplay:(id<ZJContentInfo>)content;
/**
* 内容暂停显示，ViewController disappear或者Application resign active
* @param content 内容模型
*/
- (void)zjAdapter_contentDidPause:(id<ZJContentInfo>)content;
/**
* 内容恢复显示，ViewController appear或者Application become active
* @param content 内容模型
*/
- (void)zjAdapter_contentDidResume:(id<ZJContentInfo>)content;


@end

// 广告加载相关回调
@protocol ZJContentAdapterLoadCallBackProtocol <NSObject>

/// 广告对象加载成功
- (void)zjAdapter_contentLoadSuccess:(ZJTierAdAdapter *)adapter;

/// 广告对象请求开失败回调
- (void)zjAdapter_contentLoadFail:(ZJTierAdAdapter *)adapter error:(NSError *)error;

@end


/// 短剧播放器回调DJXDrawVideoViewControllerDelegate
@protocol ZJShortPlayPlayerCallBackProtocol <NSObject>

/*! @abstract 视频切换时的回调 */
- (void)zjAdapter_shortplayDrawVideoCurrentVideoChanged:(NSInteger)index content:(id<ZJContentInfo>)content;

/*! @abstract 加载失败按钮点击重试回调 */
- (void)zjAdapter_shortplayDrawVideoDidClickedErrorButtonRetry:(id<ZJContentInfo>)content;

/*! @abstract 默认关闭按钮被点击的回调 */
- (void)zjAdapter_shortplayDrawVideoCloseButtonClicked:(id<ZJContentInfo>)content;

/*! @abstract 数据刷新完成回调 */
- (void)zjAdapter_shortplayDrawVideoDataRefreshCompletion:(NSError *)error content:(id<ZJContentInfo>)content;

/*! @abstract tab栏切换控制器的回调*/
- (void)zjAdapter_shortplayPageViewControllerSwitchToIndex:(NSInteger)index content:(id<ZJContentInfo>)content;

@end

// 广告回调
@protocol ZJShortPlayAdCallBackProtocol <NSObject>

@optional

/*! @abstract 发起广告请求 */
- (void)zjAdapter_shortplaySendAdRequest:(id<ZJContentInfo>)content;

/*! @abstract 广告加载成功 */
- (void)zjAdapter_shortplayAdLoadSuccess:(id<ZJContentInfo>)content;

/*! @abstract 广告加载失败 */
- (void)zjAdapter_shortplayAdLoadFail:(id<ZJContentInfo>)content error:(NSError *)error;

/*! @abstract 广告填充失败 */
- (void)zjAdapter_shortplayAdFillFail:(id<ZJContentInfo>)content;

/*! @abstract 广告曝光 */
- (void)zjAdapter_shortplayAdWillShow:(id<ZJContentInfo>)content;

/*! @abstract 视频广告开始播放 */
- (void)zjAdapter_shortplayVideoAdStartPlay:(id<ZJContentInfo>)content;

/*! @abstract 视频广告暂停播放 */
- (void)zjAdapter_shortplayVideoAdPause:(id<ZJContentInfo>)content;

/*! @abstract 视频广告继续播放 */
- (void)zjAdapter_shortplayVideoAdContinue:(id<ZJContentInfo>)content;

/*! @abstract 视频广告停止播放 */
- (void)zjAdapter_shortplayVideoAdOverPlay:(id<ZJContentInfo>)content;

/*! @abstract 点击广告 */
- (void)zjAdapter_shortplayClickAdViewEvent:(id<ZJContentInfo>)content;
/*! @abstract 广告缓冲 */
- (void)zjAdapter_shortplayVideoBufferEvent:(id<ZJContentInfo>)content;

/*! @abstract 激励视频广告结束 */
- (void)zjAdapter_shortplayVideoRewardFinishEvent:(id<ZJContentInfo>)content;

/*! @abstract 激励视频广告跳过 */
- (void)zjAdapter_shortplayVideoRewardSkipEvent:(id<ZJContentInfo>)content;

@end


// 业务接口回调
@protocol ZJShortPlayInterfaceCallBackProtocol <NSObject>

/*! @abstract 解锁流程开始 */
- (void)zjAdapter_shortplayPlayletDetailUnlockFlowStart:(id<ZJContentInfo>)content;

/*! @abstract 解锁流程取消 */
- (void)zjAdapter_shortplayPlayletDetailUnlockFlowCancel:(id<ZJContentInfo>)content;


/*! @abstract 解锁流程结束，回调解锁结果
 *  - success: 是否解锁成功
 *   - error: 解锁失败错误信息
 */
- (void)zjAdapter_shortplayPlayletDetailUnlockFlowEnd:(id<ZJContentInfo>)content
                           success:(BOOL)success
                             error:(NSError * _Nullable)error;

@optional

/*! @abstract 点击混排中进入跳转播放页的按钮 */
- (void)zjAdapter_shortplayClickEnterView:(id<ZJContentInfo>)content;

/*! @abstract 本剧集观看完毕，切到下一部短剧回调 */
- (void)zjAdapter_shortplayNextPlayletWillPlay:(id<ZJContentInfo>)content;

- (UIView *)zjAdapter_shortplayPlayletDetailBottomBanner:(id<ZJContentInfo>)content;

@end


// 自定义详情页cell试图
@protocol ZJShortPlayCustomViewCallBackProtocol <NSObject>

/// 创建自定义View直接返回，外部不要持有，cell自己持有复用
/// @param cell 短剧的cell
- (UIView *)zjAdapter_shortplayPlayletDetailCellCustomView:(UITableViewCell *)cell;

/// 根据数据更新UI
/// @param cell 短剧的cell
/// @param customView `djx_playletDetailCellCustomView:`返回的自定义View，短剧的cell内部会持有
/// @param playletInfo 短剧的数据
- (void)zjAdapter_shortplayPlayletDetailCell:(UITableViewCell *)cell updateCustomView:(UIView *)customView withPlayletData:(id)playletInfo;

/// 当cell执行到layoutSubviews时会回调此协议方法
/// @param cell 短剧的cell
/// @param customView `djx_playletDetailCellCustomView:`返回的自定义View
- (void)zjAdapter_shortplayPlayletDetailCell:(UITableViewCell *)cell layoutSubviews:(UIView *)customView;

/// 当cell执行到layoutSubviews后会回调此协议方法
/// @param cell 短剧的cell
/// @param customView `djx_playletDetailCellCustomView:`返回的自定义View
- (void)zjAdapter_shortplayPlayletDetailCell:(UITableViewCell *)cell afterLayoutSubviews:(UIView *)customView;

@end


/// 自定义Draw流的subview
@protocol ZJShortPlayCustomDrawAdViewCallBackProtocol <NSObject>

- (UIView *)zjAdapter_shortplayDetailCellCreateAdView:(UITableViewCell *)cell adInputIndex:(NSUInteger)adIndex;

- (void)zjAdapter_shortplayDetailCell:(UITableViewCell *)cell bindDataToDrawAdView:(UIView *)drawAdView adInputIndex:(NSUInteger)adIndex;

@optional

- (void)zjAdapter_shortplayDetailCell:(UITableViewCell *)cell layoutSubview:(UIView *)drawAdView adInputIndex:(NSUInteger)adIndex;

- (void)zjAdapter_shortplayDetailCell:(UITableViewCell *)cell willDisplayDrawAdView:(UIView *)drawAdView adInputIndex:(NSUInteger)adIndex;

- (void)zjAdapter_shortplayDetailCell:(UITableViewCell *)cell didEndDisplayDrawAdView:(UIView *)drawAdView adInputIndex:(NSUInteger)adIndex;


@end


/// 滑滑溜底部自定义Banner广告
@protocol ZJShortPlayDrawVideoViewControllerBannerCallBackProtocol <NSObject>

- (UIView *)zjAdapter_shortplayDrawVideoVCBottomBannerView:(UIViewController *)vc adapter:(ZJTubePageAdapter *)adapter;

@end

NS_ASSUME_NONNULL_END
