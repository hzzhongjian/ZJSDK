//
//  WindMediaView.h
//  WindSDK
//
//  Created by Codi on 2021/11/4.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface WindMediaView : UIView

/**
 * 视频广告时长，单位 s
 */
- (CGFloat)totalTime;

/**
 * 视频广告已播放时长，单位 s
 */
- (CGFloat)currentTime;

/**
 播放静音开关
 @param flag 是否静音
 */
- (void)muteEnable:(BOOL)flag;

/**
 播放视频
 */
- (void)play;

/**
 暂停视频，调用 pause 后，需要被暂停的视频广告对象，不会再自动播放，需要调用 play 才能恢复播放。
 */
- (void)pause;

/**
 停止播放
 */
- (void)stop;

/// 获取视频缩略图
- (NSString *)getVideoCoverImageUrl;

@property (nonatomic, copy) void(^ctaCallback)(UIControl *sender, UIEvent *event);

@end

NS_ASSUME_NONNULL_END
