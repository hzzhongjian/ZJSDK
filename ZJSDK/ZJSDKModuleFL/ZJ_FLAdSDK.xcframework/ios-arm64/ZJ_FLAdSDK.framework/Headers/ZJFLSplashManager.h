//
//  ZJFLSplashManager.h
//  ZJ_FLAdSDK
//
//  Created by lurich on 2021/9/17.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <ZJ_FLAdSDK/ZJFLBaseAdManager.h>

NS_ASSUME_NONNULL_BEGIN
@protocol ZJFLSplashDelegate <NSObject>

@optional
//回调已全部转为主线程
/**
 * 广告数据：加载成功
 */
- (void)splashAdDidLoad;
/**
 * 广告数据：加载失败
 * @param error : 错误信息
 */
- (void)splashAdDidFailed:(NSError *)error;
/**
 * 广告成功展示
 */
- (void)splashAdDidVisible;
/**
 * 广告展示失败
 */
- (void)splashAdFailToVisible:(NSError *)error;
/**
 * 广告视图：点击
 * @param urlStr 媒体自定义广告时，返回的落地页链接
 */
- (void)splashAdDidClickedWithUrlStr:(NSString *_Nullable)urlStr;
/**
 * 落地页或者appstoe返回事件
 */
-(void)splashAdDidCloseOtherController;
/**
 * 广告视图：关闭
 */
- (void)splashAdDidShowFinish;
/**
 * 广告成功渲染
 */
- (void)splashAdDidRender;

@end

@interface ZJFLSplashManager : ZJFLBaseAdManager

/// 广告回调的代理
@property(nonatomic, weak) id<ZJFLSplashDelegate> delegate;

/// 是否强制竖版开屏，默认为 NO
@property (nonatomic, assign) BOOL portrait;

/// 1. 全屏接入：bottomView 不传入
/// 2. 半屏接入：bottomView 传入logo的view, 竖版状态下推荐大小为 CGSizeMake(开屏宽, 开屏高 - (开屏宽 * 16.0 / 9.0))
/// 设置半屏广告的所含 logo 的 view
@property (nonatomic, strong) UIView * _Nullable bottomView;

/// 设置开屏广告的停留时间default 5s
@property (nonatomic, assign) NSInteger duration DEPRECATED_MSG_ATTRIBUTE("已弃用，固定5秒");

/// 设置开屏广告的超时时间 default 5s
@property (nonatomic, assign) NSInteger waitDataDuration DEPRECATED_MSG_ATTRIBUTE("已弃用，用 timeout 替代");

/// 用来弹出目标页的ViewController，一般为当前ViewController或root控制器
@property (nonatomic, weak) UIViewController *showAdController;

/// 发起广告请求并展示在Window中
- (void)loadAndShowSplashAdWithWindow:(UIWindow * _Nullable)window;

/// 展示开屏广告,在广告成功回调 - (void)splashAdDidLoad; 中调用
- (void)showSplashAdWithWindow:(UIWindow * _Nullable)window;

/// 自定义广告主时，需要进行注册
/// @param adv_id 广告主在Mediatom平台对应的adv_id
/// @param className 自定义Adapter的类名
- (void)registerADVId:(NSString *)adv_id ClassName:(NSString *)className;

/// API广告视频播放静音开关
/// @param isMute 是否静音
- (void)videoMute:(BOOL)isMute;

/// 主动销毁开屏广告 目前仅对自有广告
-(void) destorySplashAdView;

//开屏广告的背景图片  可以设置背景图片作为开屏加载时的默认背景
@property (nonatomic, strong) UIImage *backgroundImage;

@end

NS_ASSUME_NONNULL_END
