//
//  WanjaAdFullScreenVedio.h
//  FBSnapshotTestCase
//
//  Created by guantou on 2023/11/20.
//

#import "WanjaopusBaseAd.h"

NS_ASSUME_NONNULL_BEGIN

@protocol WanjaAdFullScreenVedioDelegate;

@interface WanjaAdFullScreenVedio : WanjaopusBaseAd

// 设置广告的代理
@property (nonatomic, weak)id<WanjaAdFullScreenVedioDelegate> delegate;

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

@protocol WanjaAdFullScreenVedioDelegate <NSObject>

// 加载成功
- (void)wanjaad_fullScreenVedioSuccessToLoad:(WanjaAdFullScreenVedio *)fullScreenVedioAd;

// 加载失败
- (void)wanjaad_fullScreenVedio:(WanjaAdFullScreenVedio *)fullScreenVedioAd didFailWithError:(NSError * _Nullable)error;

// 广告曝光
- (void)wanjaad_fullScreenVedioDidVisible:(WanjaAdFullScreenVedio *)fullScreenVedioAd;

// 广告点击
- (void)wanjaad_fullScreenVedioAdViewDidClick:(WanjaAdFullScreenVedio *)fullScreenVedioAd;

// 广告关闭
- (void)wanjaad_fullScreenVedioDidClose:(WanjaAdFullScreenVedio *)fullScreenVedioAd;

// 广告落地页关闭
- (void)wanjaad_fullScreenVedioWillCloseOtherView:(WanjaAdFullScreenVedio *)fullScreenVedioAd;

// 视频资源预加载 YES: 预加载成功；NO：预加载失败
- (void)wanjaad_fullScreenVedioResourcePreLoadState:(WanjaAdFullScreenVedio *)fullScreenVedioAd preLoadState:(BOOL)isSuccess;

@end

NS_ASSUME_NONNULL_END
