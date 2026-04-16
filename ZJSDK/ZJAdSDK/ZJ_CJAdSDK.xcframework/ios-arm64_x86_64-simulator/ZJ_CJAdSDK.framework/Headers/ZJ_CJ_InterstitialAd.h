//
//  ZJ_CJ_InterstitialAd.h
//  ZJ_CJAdSDK
//
//  Created by coderqi on 2025/11/14.
//

#import <Foundation/Foundation.h>
#import <ZJ_CJAdSDK/ZJ_CJ_InterstitialSlot.h>
#import <ZJ_CJAdSDK/ZJ_CJ_BaseAd.h>

NS_ASSUME_NONNULL_BEGIN

@class ZJ_CJ_InterstitialAd;

@protocol ZJ_CJ_InterstitialAdDelegate <NSObject>

@optional
/**
 *  广告加载成功
 * @param interstititalAd  广告对象
 */
- (void)zjcj_InterAdLoadSuccess:(ZJ_CJ_InterstitialAd *)interstititalAd;

/**
 *  广告加载失败
 * @param interstititalAd  广告对象
 * @param error  错误信息
 */
- (void)zjcj_InterAdLoadFail:(ZJ_CJ_InterstitialAd *)interstititalAd withError:(NSError *)error;


/**
 * 广告展示成功
 * @param interstititalAd  广告对象
 */
- (void)zjcj_InterAdShowSuccess:(ZJ_CJ_InterstitialAd *)interstititalAd;

/**
 * 广告展示失败
 * @param interstititalAd  广告对象
 */
- (void)zjcj_InterAdShowFail:(ZJ_CJ_InterstitialAd *)interstititalAd withError:(NSError *)error;

/**
 * 广告点击
 * @param interstititalAd  广告数据
 */
- (void)zjcj_InterAdDidClicked:(ZJ_CJ_InterstitialAd *)interstititalAd;

/**
 * 广告关闭
 * @param interstititalAd  广告数据
 */
- (void)zjcj_InterAdDidClosed:(ZJ_CJ_InterstitialAd *)interstititalAd;

/**
 * sdk广告跳转落地页关闭回调
 * @param interstititalAd  广告对象
 */
- (void)zjcj_InterAdWebPageClose:(ZJ_CJ_InterstitialAd *)interstititalAd;

@end

@interface ZJ_CJ_InterstitialAd : ZJ_CJ_BaseAd

/// 广告请求参数
@property (nonatomic, strong, readonly) ZJ_CJ_InterstitialSlot *adSlot;

@property (nonatomic, weak) id <ZJ_CJ_InterstitialAdDelegate> delegate;

/**
 * @brief 初始化view
 */
- (instancetype)initWithSlot:(ZJ_CJ_InterstitialSlot *)slot;

/**
 *  加载广告
 */
- (void)loadAd;

/**
 *  展示开屏广告
 *  @param rootViewController 展示开屏广告的UIViewController
 *  曝光时，请确保rootViewController无presentedVC，否则影响广告展示、点击、落地页打开
 */
- (void)showAdFromRootViewController:(UIViewController *)rootViewController;

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
