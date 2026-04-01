#import <UIKit/UIKit.h>

@protocol JTVideoPlayerDelegate <NSObject>

/// 视频播放开始
- (void)jtVideoPlayerStartPlayVideoView:(JTVideoPlayerView *)videoPlayerView;
/// 视频正在播放
- (void)jtVideoPlayerPlayingVideoView:(JTVideoPlayerView *)videoPlayerView
                          currentTime:(float)currentTime
                          totalLength:(float)totalTime;
/// 视频播放暂停
- (void)jtVideoPlayerDidPauseVideoView:(JTVideoPlayerView *)videoPlayerView;
/// 视频播放恢复
- (void)jtVideoPlayerDidResumeVideoView:(JTVideoPlayerView *)videoPlayerView;
/// 视频播放结束
- (void)jtVideoPlayerDidFinishVideoView:(JTVideoPlayerView *)videoPlayerView;
/// 视频播放终止
- (void)jtVideoPlayerDidBreakVideoView:(JTVideoPlayerView *)videoPlayerView error:(NSError *)error;

@end

/// 聚推广告通用的视频播放器View
@interface JTVideoPlayerView : UIView

/// 事件回调
@property (nonatomic, weak) id<JTVideoPlayerDelegate> delegate;

/// 是否静音播放，默认YES，静音播放。
@property (nonatomic, assign) BOOL muted;

/// 是否循环播放，默认YES，循环播放。
@property (nonatomic, assign) BOOL loopPlayback;

/// 开始/继续播放
- (void)play;

/// 暂停
- (void)pause;

/// 停止并重置到开头
- (void)stop;

@end
