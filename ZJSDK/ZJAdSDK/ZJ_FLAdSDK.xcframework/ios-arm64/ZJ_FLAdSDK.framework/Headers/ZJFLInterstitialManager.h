//
//  ZJFLInterstitialManager.h
//  ZJ_FLAdSDK
//
//  Created by lurich on 2021/9/17.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <ZJ_FLAdSDK/ZJFLBaseAdManager.h>

NS_ASSUME_NONNULL_BEGIN
@protocol ZJFLInterstitialDelegate <NSObject>

@optional
//回调已全部转为主线程
/**
 * 广告数据：加载成功
 */
- (void)interstitialAdDidLoad;
/**
 * 广告数据：加载失败
 * @param error : 错误信息
 */
- (void)interstitialAdDidFailed:(NSError *)error;
/**
 * 广告视图：展示
 */
- (void)interstitialAdDidVisible;
/**
 * 广告视图：点击
 */
- (void)interstitialAdDidClick;
/**
 * 落地页或者appstoe返回事件
 */
- (void)interstitialAdDidCloseOtherController;
/**
 * 广告视图：关闭
 */
- (void)interstitialAdDidClose DEPRECATED_MSG_ATTRIBUTE("使用 interstitialAdDidAutoClose: 替代");
- (void)interstitialAdDidAutoClose:(BOOL)autoClose;

@end

@interface ZJFLInterstitialManager : ZJFLBaseAdManager

/// 广告回调的代理
@property(nonatomic, weak) id<ZJFLInterstitialDelegate> delegate;

/// 广告大小尺寸
@property (nonatomic) CGSize size DEPRECATED_MSG_ATTRIBUTE("已弃用，设置无效");

/// 用来弹出目标页的ViewController，一般为当前ViewController或root控制器
@property (nonatomic, weak) UIViewController *showAdController;

/// 定时自动关闭插屏，默认由后台控制
@property (nonatomic) double autoCloseTime;

/// 展示插屏广告
- (void)showInterstitialAd;

/// 自定义广告主时，需要进行注册
/// @param adv_id 广告主在Mediatom平台对应的adv_id
/// @param className 自定义Adapter的类名
- (void)registerADVId:(NSString *)adv_id ClassName:(NSString *)className;

@end

NS_ASSUME_NONNULL_END
