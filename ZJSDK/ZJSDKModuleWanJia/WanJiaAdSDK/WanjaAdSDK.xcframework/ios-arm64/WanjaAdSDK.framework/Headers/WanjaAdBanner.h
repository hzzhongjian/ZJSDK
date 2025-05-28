//
//  WanjaAdBanner.h
//  FBSnapshotTestCase
//
//  Created by caihongji on 2024/10/26.
//

#import "WanjaopusBaseAd.h"

NS_ASSUME_NONNULL_BEGIN

@protocol WanjaAdBannerDelegate;

@interface WanjaAdBanner : WanjaopusBaseAd

// controller 展示view的控制器或者弹出落地页的需要的控制器，此参数不能为空
@property (nonatomic, weak) UIViewController *controller;

// 设置原生广告的代理
@property (nonatomic, weak)id<WanjaAdBannerDelegate> delegate;

// 原生初始化
- (instancetype)initWithSlotId:(NSString *)slotId;

// 加载广告
- (void)loadAd;

// 获取广告返回价格(价格单位：分)
- (int)getPrice;

// 获取广告时效(单位：毫秒)
- (NSInteger)getValidTime;

// 广告加载成功后获得的 View广告（数组内部为加载完成的View形式广告，直接add到目标View）
@property (nonatomic, strong, readonly) NSArray *bannerAdViews;

@end

@protocol WanjaAdBannerDelegate <NSObject>

// 加载成功
- (void)wanjaad_BannerSuccessToLoad:(WanjaAdBanner *)bannerAd;

// 加载失败
- (void)wanjaad_BannerAd:(WanjaAdBanner *)bannerAd didFailWithError:(NSError * _Nullable)error;

// 广告曝光
- (void)wanjaad_BannerDidVisible:(WanjaAdBanner *)bannerAd;

// 广告点击
- (void)wanjaad_BannerAdViewDidClick:(WanjaAdBanner *)bannerAd;

// 广告关闭
- (void)wanjaad_BannerAdViewDidClose:(WanjaAdBanner *)bannerAd;

// 广告落地页关闭
- (void)wanjaad_BannerAdViewWillCloseOtherView:(WanjaAdBanner *)bannerAd;

@end

NS_ASSUME_NONNULL_END
