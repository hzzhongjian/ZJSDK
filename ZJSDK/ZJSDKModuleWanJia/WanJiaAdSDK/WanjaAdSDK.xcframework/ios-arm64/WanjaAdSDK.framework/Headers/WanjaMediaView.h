//
//  WanjaMediaView.h
//  WanjaAdSDK
//
//  Created by hongji cai on 2024/4/13.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    WanjaVedioShowModelResize,
    WanjaVedioShowModelResizeAspect,
    WanjaVedioShowModelResizeFill,
} WanjaVedioShowModel;

@protocol WanjaAdMediaViewDelegate;
@class WanjaSpaceInfoModel;

@interface WanjaMediaView : UIView
//视频的显示模式，默认WanjaVedioShowModelResizeAspect
@property (nonatomic, assign) WanjaVedioShowModel showModel;
//声音控制视图, 外部可以改变frame。 width / height = 1 / 1
@property (nonatomic, strong, readonly) UIView *voiceControlView;
/**控制视频的音量控制按钮是否展示（默认显示）*/
@property (nonatomic, assign) BOOL isHiddenVoiceButton;
//是否正在播放
@property (nonatomic, readonly) BOOL isPlaying;
//是否静音了
@property (nonatomic, readonly) BOOL isMuted;
//
@property (nonatomic, weak) id<WanjaAdMediaViewDelegate> delegate;

- (instancetype)initWithFrame:(CGRect)frame spaceInfo:(WanjaSpaceInfoModel*)spaceInfo;
//恢复播放
- (void)resume;
//暂停播放
- (void)pause;
//设置播放器的背景色
- (void)setPlayerBackgroundColor:(UIColor *)backgroundColor;
//设置静音
- (void)voiceMute:(BOOL)mute;
//销毁
- (void)destroyMediaView;
//
@end

@protocol WanjaAdMediaViewDelegate <NSObject>

//准备播放
- (void)wanjaad_mediaReady:(WanjaMediaView *)mediaView;
- (void)wanjaad_mediaStart:(WanjaMediaView *)mediaView;
- (void)wanjaad_mediaPause:(WanjaMediaView *)mediaView;
- (void)wanjaad_mediaResume:(WanjaMediaView *)mediaView;
- (void)wanjaad_mediaError:(WanjaMediaView *)mediaView error:(NSError*)error;
- (void)wanjaad_mediaCompleted:(WanjaMediaView *)mediaView;

@end


NS_ASSUME_NONNULL_END
