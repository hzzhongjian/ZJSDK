//
//  WanjaVideoTool.h
//  WanjaCore
//
//  Created by hongji cai on 2024/11/16.
//

#import <UIKit/UIKit.h>
#import "WanjaPlayerView.h"

NS_ASSUME_NONNULL_BEGIN

@interface WanjaVideoTool : UIView
@property (nonatomic, weak) id<WanjaAdvertisingDelegate> delegate;
//该协议仅sdk内部使用
@property (nonatomic, weak) id<WanjaVedioCatchDelegate> catchDelegate;
/**
 视频填充方式, 默认AVLayerVideoGravityResizeAspect
*/
@property (nonatomic, copy) AVLayerVideoGravity videoGravity;

/**
 音量控制 ， YES有音量
*/
@property (nonatomic, assign) BOOL mute;

/**
音量视图
*/
@property (nonatomic, strong, readonly) UIImageView * voiceImageView;


- (instancetype)initWithFrame:(CGRect)frame;

/**
 渲染广告
*/
- (void)loadPlayerWithVideoUrl:(NSString*)videoUrl;

/**
 播放
 */
- (void)play;

/**
 重新播放
 */
- (void)rePlay;
@end

NS_ASSUME_NONNULL_END
