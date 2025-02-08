//
//  ZJTubePageTierLoader.h
//  ZJSDK
//
//  Created by 麻明康 on 2025/1/8.
//  Copyright © 2025 zj. All rights reserved.
//

#import <ZJSDK/ZJSDK.h>

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


@interface ZJTubePageTierLoader : ZJTierAdLoader

@property (nonatomic, weak) id <ZJTubePageTierLoaderStateDelegate> stateDelegate;

@property (nonatomic, weak) id <ZJTubePageTierLoaderVideoStateDelegate> videoStateDelegate;


@end

NS_ASSUME_NONNULL_END
