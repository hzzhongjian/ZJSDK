//
//  ZJCJBannerAd.h
//  ZJ_CJAdSDK
//
//  Created by coderqi on 2025/11/13.
//

#import <UIKit/UIKit.h>
#import <ZJ_CJAdSDK/ZJ_CJ_BannerSlot.h>
#import <ZJ_CJAdSDK/ZJ_CJ_BannerView.h>
#import <ZJ_CJAdSDK/ZJ_CJ_BaseAd.h>

NS_ASSUME_NONNULL_BEGIN

@class ZJ_CJ_BannerSlot;
@class ZJ_CJ_BannerAd;

@protocol ZJ_CJ_BannerAdDelegate <NSObject>

/**
 *  广告加载成功
 * @param bannerAd  广告对象
 */
- (void)zjcj_BannerAdLoadSuccess:(ZJ_CJ_BannerAd *)bannerAd;

/**
 *  广告加载失败
 * @param bannerAd  广告对象
 * @param error  错误信息
 */
- (void)zjcj_BannerAdLoadFail:(ZJ_CJ_BannerAd *)bannerAd withError:(NSError *)error;


/**
 * 广告展示成功
 * @param bannerAd  广告对象
 */
- (void)zjcj_BannerAdShowSuccess:(ZJ_CJ_BannerAd *)bannerAd;

/**
 * 广告展示失败
 * @param bannerAd  广告对象
 */
- (void)zjcj_BannerAdShowFail:(ZJ_CJ_BannerAd *)bannerAd withError:(NSError *)error;

/**
 * 广告点击
 * @param bannerAd  广告数据
 */
- (void)zjcj_BannerAdDidClicked:(ZJ_CJ_BannerAd *)bannerAd;

/**
 * 广告关闭
 * @param bannerAd  广告数据
 */
- (void)zjcj_BannerAdDidClosed:(ZJ_CJ_BannerAd *)bannerAd;

/**
 * sdk广告跳转落地页关闭回调
 * @param bannerAd  广告对象
 */
- (void)zjcj_BannerAdWebPageClose:(ZJ_CJ_BannerAd *)bannerAd;

@end

@interface ZJ_CJ_BannerAd : ZJ_CJ_BaseAd

/// 广告请求参数
@property (nonatomic, strong, readonly) ZJ_CJ_BannerSlot *adSlot;

@property (nonatomic, weak) id <ZJ_CJ_BannerAdDelegate> delegate;

/**
 * @brief 初始化view
 */
- (instancetype)initWithSlot:(ZJ_CJ_BannerSlot *)slot;

/**
 *  加载广告
 */
- (void)loadAd;

/**
 *   获取广告View
 */
- (ZJ_CJ_BannerView *)getBannerViewError:(NSError **)error;

/**
 * 销毁广告
 */
- (void)destoryAd;

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
