//
//  ZJFeedPageAdLoader.h
//  ZJSDK
//
//  Created by 麻明康 on 2025/1/20.
//  Copyright © 2025 zj. All rights reserved.
//

#import <ZJSDK/ZJSDK.h>

NS_ASSUME_NONNULL_BEGIN


@protocol ZJFeedPageAdLoaderStateDelegate <NSObject>

/**
* 内容展示
* @param content 内容模型
*/
- (void)zj_feedPageLoaderDidFullDisplay:(id<ZJContentInfo>)content;
/**
* 内容隐藏
* @param content 内容模型
*/
- (void)zj_feedPageLoaderDidEndDisplay:(id<ZJContentInfo>)content;
/**
* 内容暂停显示，ViewController disappear或者Application resign active
* @param content 内容模型
*/
- (void)zj_feedPageLoaderDidPause:(id<ZJContentInfo>)content;
/**
* 内容恢复显示，ViewController appear或者Application become active
* @param content 内容模型
*/
- (void)zj_feedPageLoaderDidResume:(id<ZJContentInfo>)content;

/// 任务完成回调
- (void)zj_feedPageLoaderTaskComplete:(id<ZJContentInfo>)content;

@end



@protocol ZJFeedPageAdLoaderVideoStateDelegate <NSObject>

/**
 * 视频开始播放
 * @param videoContent 内容模型
 */
- (void)zj_feedPageLoaderVideoDidStartPlay:(id<ZJContentInfo>)videoContent;
/**
* 视频暂停播放
* @param videoContent 内容模型
*/
- (void)zj_feedPageLoaderVideoDidPause:(id<ZJContentInfo>)videoContent;
/**
* 视频恢复播放
* @param videoContent 内容模型
*/
- (void)zj_feedPageLoaderVideoDidResume:(id<ZJContentInfo>)videoContent;
/**
* 视频停止播放
* @param videoContent 内容模型
* @param finished     是否播放完成
*/
- (void)zj_feedPageLoaderVideoDidEndPlay:(id<ZJContentInfo>)videoContent isFinished:(BOOL)finished;
/**
* 视频播放失败
* @param videoContent 内容模型
* @param error        失败原因
*/
- (void)zj_feedPageLoaderVideoDidFailedToPlay:(id<ZJContentInfo>)videoContent withError:(NSError *)error;

@end

@interface ZJFeedPageAdLoader : ZJTierAdLoader

@property (nonatomic, weak) id <ZJFeedPageAdLoaderStateDelegate> stateDelegate;

@property (nonatomic, weak) id <ZJFeedPageAdLoaderVideoStateDelegate>videoStateDelegate;

@end

NS_ASSUME_NONNULL_END
