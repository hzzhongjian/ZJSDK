//
//  ZJ_XAdNativeAd.h
//  ZJ_AdWangMaiSDK
//
//  Created by 周泽浩 on 2023/3/10.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@protocol ZJ_XAdNativeDelegete;

@interface ZJ_XAdNativeAd : NSObject

/// 代理
@property (weak, nonatomic) id<ZJ_XAdNativeDelegete>delegate;

/// 是否需要满足HTTPS  [可选] 默认为NO
@property (nonatomic,assign) BOOL secure;

/// 视频物料是否静音  [可选]  默认为NO
@property (nonatomic,assign) BOOL videoMuted;

/// 是否自动播放  [可选] 默认为YES
@property (nonatomic,assign) BOOL automaticallyPlay;

/// [必选]开发者需传入用来弹出目标页的ViewController
@property (nonatomic, weak) UIViewController *controller;

/// 初始化广告
/// - Parameter adSlotId: 广告位ID
- (instancetype)initWithAdSlotId:(NSString *)adSlotId;

/**
 加载广告数据
 */
- (void)loadAdData;

/// 视图注册方法
/// - Parameter clickableViews: 可点击的视图数组，此数组内的广告元素才可以响应广告对应的点击事件
- (void)registerClickableViews:(NSArray<UIView *> *_Nonnull)clickableViews;

/// 广告数据渲染完毕，即将展示时需调用trackImpression方法。
- (void)trackImpression;

/// 播放视频
- (void)play;

/// 暂停视频
- (void)pause;

/// 播放静音开关
/// @param flag 是否静音
- (void)muteEnable:(BOOL)flag;

/// 广告销毁
- (void)onDestroy;

/// 竞价成功上报，脉盟平台竞胜之后调用，需要在广告请求成功之后,展示之前调用，winInfo脉盟平台竞价获胜信息，可为nil。
/// @param winInfo 竞胜信息 字典类型
- (void)sendWinNotificationWithInfo:(NSDictionary *_Nullable)winInfo;

@end

NS_ASSUME_NONNULL_END
