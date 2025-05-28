//
//  WanjaAdIntersitital.h
//  FBSnapshotTestCase
//
//  Created by guantou on 2023/11/20.
//

#import "WanjaopusBaseAd.h"

NS_ASSUME_NONNULL_BEGIN

@protocol WanjaAdIntersititalDelegate;

@interface WanjaAdIntersitital : WanjaopusBaseAd

// 设置广告的代理
@property (nonatomic, weak)id<WanjaAdIntersititalDelegate> delegate;

//从落地页回到广告页时， 如果此时倒计时还未结束，是否关闭广告
@property (nonatomic, assign) BOOL isCloseAfterBackToAdvert;

// 插屏初始化
- (instancetype)initWithSlotId:(NSString *)slotId;

// 加载广告
- (void)loadAd;

// 获取广告返回价格(价格单位：分)
- (int)getPrice;

// 获取广告时效(单位：毫秒)
- (NSInteger)getValidTime;

// 广告是否加载成功
- (BOOL)isLoaded;

// 展示广告
- (void)showAdsInViewController:(UIViewController *)viewController;

@end

@protocol WanjaAdIntersititalDelegate <NSObject>

// 加载成功
- (void)wanjaad_intersititalSuccessToLoad:(WanjaAdIntersitital *)intersititalAd;

// 加载失败
- (void)wanjaad_intersitital:(WanjaAdIntersitital *)intersititalAd didFailWithError:(NSError * _Nullable)error;

// 广告曝光
- (void)wanjaad_intersititalDidVisible:(WanjaAdIntersitital *)intersititalAd;

// 广告点击
- (void)wanjaad_intersititalAdViewDidClick:(WanjaAdIntersitital *)intersititalAd;

// 广告关闭
- (void)wanjaad_intersititalDidClose:(WanjaAdIntersitital *)intersititalAd;

// 广告落地页关闭
- (void)wanjaad_intersititalWillCloseOtherView:(WanjaAdIntersitital *)intersititalAd;

// 图片/视频资源预加载 YES: 预加载成功；NO：预加载失败
- (void)wanjaad_intersititalResourcePreLoadState:(WanjaAdIntersitital *)intersititalAd preLoadState:(BOOL)isSuccess;

@end

NS_ASSUME_NONNULL_END
