//
//  WanjaAdRewardVideo.h
//  WanjaAdSDK
//
//  Created by guantou on 2023/11/26.
//

#import "WanjaopusBaseAd.h"

NS_ASSUME_NONNULL_BEGIN

@protocol WanjaAdRewardVideoDelegate;


@interface WanjaAdRewardVideo : WanjaopusBaseAd

// 设置广告的代理
@property (nonatomic, weak)id<WanjaAdRewardVideoDelegate> delegate;

// 设置发放奖励的userId，应用对用户的唯一标识， 可以为nil
@property (nonatomic, copy) NSString *userId;

// 设置发放奖励的扩展参数extra，其他信息， 可以为nil
@property (nonatomic, copy) NSString *extra;

// 激励视频初始化
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

@protocol WanjaAdRewardVideoDelegate <NSObject>

// 加载成功
- (void)wanjaad_rewardVideoSuccessToLoad:(WanjaAdRewardVideo *)rewardVideo;

// 视频资源预加载 YES: 预加载成功；NO：预加载失败
- (void)wanjaad_rewardVideoPreLoadState:(WanjaAdRewardVideo *)rewardVideo preLoadState:(BOOL)isSuccess;

// 加载失败
- (void)wanjaad_rewardVideo:(WanjaAdRewardVideo *)rewardVideo didFailWithError:(NSError * _Nullable)error;

// 广告曝光
- (void)wanjaad_rewardVideoDidVisible:(WanjaAdRewardVideo *)rewardVideo;

// 广告点击
- (void)wanjaad_rewardVideoAdViewDidClick:(WanjaAdRewardVideo *)rewardVideo;

// 广告关闭
- (void)wanjaad_rewardVideoDidClose:(WanjaAdRewardVideo *)rewardVideo;

// 广告播放完成
- (void)wanjaad_rewardVideoDidFinished:(WanjaAdRewardVideo *)rewardVideo;

// 广告发放奖励
- (void)wanjaad_rewardVideoDidReward:(WanjaAdRewardVideo *)rewardVideo;

// 开发者在章鱼后台配置校验回调地址后，当发放奖励时， 如果校验失败，会走这个回调
- (void)wanjaad_rewardVideoCheckFail:(WanjaAdRewardVideo *)rewardVideo;

@end

NS_ASSUME_NONNULL_END
