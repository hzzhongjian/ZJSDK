//
//  ZJ_CJSlot.h
//  ZJ_CJAdSDK
//
//  Created by coderqi on 2025/11/21.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZJ_CJSlot : NSObject

/// 广告位ID
@property (nonatomic, assign) NSInteger slotId;

/// 设置广告位请求底价, 单位：分
@property (nonatomic, assign) NSInteger bidFloor;

/// 设置跳转web落地页的rootVc，sdk不会强持有，避免出现内存泄漏；需要外部处理保持不释放（如果不设置，sdk则会获取当前topvc）
@property (nonatomic, weak) UIViewController *rootVc;

/// 如果广告支持摇一摇功能，是否开启，默认YES；目前仅开屏、插屏支持摇一摇
@property (nonatomic, assign) BOOL adShakeEnabled;

/// 视频播放器设置，是否静音播放，YES表示静音，NO表示取消静音，默认静音
@property (nonatomic, assign) BOOL videoMute;

/// 视频播放器设置，默认 AVLayerVideoGravityResizeAspect
@property (nonatomic,   copy) AVLayerVideoGravity videoGravity;

/// loadAd 整体超时时长（秒）：含请求与素材预加载；超时未完成则 FailedToLoad（广告请求超时）。
/// 默认 30；开屏 Slot 默认 3；<=0 不限制。初始化下发广告位 timeout>0 时以后台值为准，忽略本字段。
@property (nonatomic, assign) NSTimeInterval tolerateTimeout;

@end

NS_ASSUME_NONNULL_END
