//
//  ZJ_CJBannerAd.h
//  ZJ_CJAdSDK
//
//  Created by coderqi on 2025/11/13.
//

#import <UIKit/UIKit.h>
#import <ZJ_CJAdSDK/ZJ_CJBannerSlot.h>
#import <ZJ_CJAdSDK/ZJ_CJBannerView.h>
#import <ZJ_CJAdSDK/ZJ_CJBaseAd.h>

NS_ASSUME_NONNULL_BEGIN

@class ZJ_CJBannerSlot;
@class ZJ_CJBannerAd;

@protocol ZJ_CJBannerAdDelegate <NSObject>

/**
 *  广告加载成功
 * @param bannerAd  广告对象
 */
- (void)zj_cj_BannerAdLoadSuccess:(ZJ_CJBannerAd *)bannerAd;

/**
 *  广告加载失败
 * @param bannerAd  广告对象
 * @param error  错误信息
 */
- (void)zj_cj_BannerAdLoadFail:(ZJ_CJBannerAd *)bannerAd withError:(NSError *)error;


/**
 * 广告展示成功
 * @param bannerAd  广告对象
 */
- (void)zj_cj_BannerAdShowSuccess:(ZJ_CJBannerAd *)bannerAd;

/**
 * 广告展示失败
 * @param bannerAd  广告对象
 */
- (void)zj_cj_BannerAdShowFail:(ZJ_CJBannerAd *)bannerAd withError:(NSError *)error;

/**
 * 广告点击
 * @param bannerAd  广告数据
 */
- (void)zj_cj_BannerAdDidClicked:(ZJ_CJBannerAd *)bannerAd;

/**
 * 广告关闭
 * @param bannerAd  广告数据
 */
- (void)zj_cj_BannerAdDidClosed:(ZJ_CJBannerAd *)bannerAd;

/**
 * sdk广告跳转落地页关闭回调
 * @param bannerAd  广告对象
 */
- (void)zj_cj_BannerAdWebPageClose:(ZJ_CJBannerAd *)bannerAd;

@end

@interface ZJ_CJBannerAd : ZJ_CJBaseAd

/// 广告请求参数
@property (nonatomic, strong, readonly) ZJ_CJBannerSlot *adSlot;

@property (nonatomic, weak) id <ZJ_CJBannerAdDelegate> delegate;

/**
 * @brief 初始化view
 */
- (instancetype)initWithSlot:(ZJ_CJBannerSlot *)slot;

/**
 *  加载广告
 */
- (void)loadAd;

/**
 *   获取广告View
 */
- (ZJ_CJBannerView *)getBannerViewError:(NSError **)error;

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

/**
 * 获取图片素材地址
 */
- (NSArray<NSString *> *)getImageFileUrls;

/**
 * 获取视频素材地址
 */
- (NSArray<NSString *> *)getVideoFileUrls;

/**
 * 获取落地页地址
 */
- (NSString *)getLandpageUrl;

@end

NS_ASSUME_NONNULL_END
