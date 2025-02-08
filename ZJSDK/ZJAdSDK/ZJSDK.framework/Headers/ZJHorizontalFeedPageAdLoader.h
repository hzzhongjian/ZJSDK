//
//  ZJHorizontalFeedPageAdLoader.h
//  ZJSDK
//
//  Created by 麻明康 on 2025/1/20.
//  Copyright © 2025 zj. All rights reserved.
//

#import <ZJSDK/ZJSDK.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZJHorizontalFeedPageAdLoaderStateDelegate <NSObject>

/**
* 内容展示
* @param content 内容模型
*/
- (void)zj_horizontalFeedPageLoaderDidFullDisplay:(id<ZJContentInfo>)content;
/**
* 内容隐藏
* @param content 内容模型
*/
- (void)zj_horizontalFeedPageLoaderDidEndDisplay:(id<ZJContentInfo>)content;
/**
* 内容暂停显示，ViewController disappear或者Application resign active
* @param content 内容模型
*/
- (void)zj_horizontalFeedPageLoaderDidPause:(id<ZJContentInfo>)content;
/**
* 内容恢复显示，ViewController appear或者Application become active
* @param content 内容模型
*/
- (void)zj_horizontalFeedPageLoaderDidResume:(id<ZJContentInfo>)content;

/// 任务完成回调
- (void)zj_horizontalFeedPageLoaderTaskComplete:(id<ZJContentInfo>)content;

@end



@protocol ZJHorizontalFeedPageAdLoaderVideoStateDelegate <NSObject>

/**
 * 视频开始播放
 * @param videoContent 内容模型
 */
- (void)zj_horizontalFeedPageLoaderVideoDidStartPlay:(id<ZJContentInfo>)videoContent;
/**
* 视频暂停播放
* @param videoContent 内容模型
*/
- (void)zj_horizontalFeedPageLoaderVideoDidPause:(id<ZJContentInfo>)videoContent;
/**
* 视频恢复播放
* @param videoContent 内容模型
*/
- (void)zj_horizontalFeedPageLoaderVideoDidResume:(id<ZJContentInfo>)videoContent;
/**
* 视频停止播放
* @param videoContent 内容模型
* @param finished     是否播放完成
*/
- (void)zj_horizontalFeedPageLoaderVideoDidEndPlay:(id<ZJContentInfo>)videoContent isFinished:(BOOL)finished;
/**
* 视频播放失败
* @param videoContent 内容模型
* @param error        失败原因
*/
- (void)zj_horizontalFeedPageLoaderVideoDidFailedToPlay:(id<ZJContentInfo>)videoContent withError:(NSError *)error;

/// 进入横版视频详情页
/// @param viewController 详情页VC
/// @param content 视频信息
- (void)zj_horizontalFeedPageLoaderVideoDetailDidEnter:(UIViewController *)viewController contentInfo:(id<ZJContentInfo>)content;

/// 离开横版视频详情页
/// @param viewController 详情页VC
- (void)zj_horizontalFeedPageLoaderVideoDetailDidLeave:(UIViewController *)viewController;

/// 视频详情页appear
/// @param viewController 详情页VC
- (void)zj_horizontalFeedPageLoaderVideoDetailDidAppear:(UIViewController *)viewController;

/// 详情页disappear
/// @param viewController 详情页VC
- (void)zj_horizontalFeedPageLoaderVideoDetailDidDisappear:(UIViewController *)viewController;


@end

@interface ZJHorizontalFeedPageAdLoader : ZJTierAdLoader

@property (nonatomic, weak) id <ZJHorizontalFeedPageAdLoaderStateDelegate> stateDelegate;

@property (nonatomic, weak) id <ZJHorizontalFeedPageAdLoaderVideoStateDelegate>videoStateDelegate;

@end

NS_ASSUME_NONNULL_END
