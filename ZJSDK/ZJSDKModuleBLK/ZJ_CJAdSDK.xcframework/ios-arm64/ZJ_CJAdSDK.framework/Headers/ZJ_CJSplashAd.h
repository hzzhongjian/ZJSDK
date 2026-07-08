//
//  ZJCJSplashAd.h
//  ZJ_CJAdSDK
//
//  Created by coderqi on 2025/11/13.
//

#import <UIKit/UIKit.h>
#import <ZJ_CJAdSDK/ZJ_CJBaseAd.h>
#import <ZJ_CJAdSDK/ZJ_CJSplashAdSlot.h>



NS_ASSUME_NONNULL_BEGIN

@class ZJ_CJSplashAd;
@protocol ZJ_CJSplashAdDelegate <NSObject>
/**
 *  广告请求成功，并且素材加载完成，在此选择调用showAd来展示广告
 */
- (void)zjcj_SplashAdDidLoad:(ZJ_CJSplashAd *)splashAd;

/**
 *  广告请求失败
 *  @param error 失败原因
 */
- (void)zjcj_SplashAdFailedToLoad:(ZJ_CJSplashAd *)splashAd withError:(NSError *)error;

/**
 *  广告素材缓存完毕
 */
- (void)zjcj_SplashAdDidCacheFinished:(ZJ_CJSplashAd *)splashAd;

/**
 *  广告即将展示
 */
- (void)zjcj_SplashAdWillShow:(ZJ_CJSplashAd *)splashAd;

/**
 *  广告展示完毕
 */
- (void)zjcj_SplashAdDidShow:(ZJ_CJSplashAd *)splashAd;

/**
 *  广告展示失败，未能正确显示在屏幕上: 如调用showAd时，window不是keywindow
 *  @param error 失败原因
 */
- (void)zjcj_SplashAdFailedToShow:(ZJ_CJSplashAd *)splashAd withError:(NSError *)error;
/**
 *  广告点击回调
 */
- (void)zjcj_SplashAdDidClick:(ZJ_CJSplashAd *)splashAd;

/**
 *  广告关闭回调：跳过/倒计时结束/点击广告后广告view被移除
 */
- (void)zjcj_SplashAdDidClose:(ZJ_CJSplashAd *)splashAd isSkip:(BOOL)isSkip;

/**
 *  广告转化完成：关闭落地页或者跳转到其他应用
 */
//- (void)apSplashAdDidFinishConversion:(ZJ_CJSplashAd *)splashAd interactionType:(UBiXAdInteractionType)interactionType;

@end

@interface ZJ_CJSplashAd : ZJ_CJBaseAd

/// 广告请求参数
@property (nonatomic, strong, readonly) ZJ_CJSplashAdSlot *adSlot;

/// 回调委托对象
@property (nonatomic, weak) id<ZJ_CJSplashAdDelegate> delegate;

/// @required 用于打开落地页，确保ta当前无presentedVC，否则将无法打开落地页
@property (nonatomic, weak) UIViewController *rootViewController;

/// 设置加载广告超时时长(秒)，默认为5秒
@property (nonatomic, assign) NSTimeInterval tolerateTimeout;

@property (nonatomic, strong) UIView *bottomView;

/**
 *  构造方法
 *  @param slot 广告位请求参数
 */
- (instancetype)initWithSlot:(ZJ_CJSplashAdSlot *)slot;

/**
 *  加载广告
 */
- (void)loadAd;

/**
 *  展示开屏广告
 *  @param window 展示开屏广告的UIWindow
 *  @param bottomView 开发者自定义底部logo，建议高度不超过屏幕高度的1/4
 *  曝光时，请确保window.rootViewController无presentedVC，否则影响广告展示、点击、落地页打开
 */
- (void)showAdToWindow:(UIWindow *)window bottomView:(UIView * _Nullable)bottomView;

/**
 * 获取广告出价
 * 广告加载成功之后，才会有值
 *  单位：分
 */
- (NSInteger)getBidPrice;

/**
 * 聚合竞价结果回传
 */
- (void)sendBidResultNotificationWithInfo:(NSDictionary *)infoDic andResut:(BOOL)isSucc;

@end

NS_ASSUME_NONNULL_END
