//
//  ZJ_XAdRewardedVideoDelegate.h
//  ZJ_AdWangMaiSDK
//
//  Created by 周泽浩 on 2023/3/1.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZJ_XAdRewardedVideoDelegate <NSObject>

@optional
/// 发起请求
- (void)rewardVideoOnAdRequest;

/// 请求成功
- (void)rewardVideoOnAdReady;

/// 请求失败
/// - Parameter error: 错误信息
- (void)rewardVideoOnError:(NSError *)error;

/// 展示
- (void)rewardVideoOnExposure;

/// 点击
- (void)rewardVideoOnClick;

/// 关闭
- (void)rewardVideoOnAdClose;

/// 播放失败
/// - Parameter error: 错误信息
- (void)rewardVideoPlayError:(NSError *)error;

/// 播放完成
- (void)rewardVideoOnVideoComplete;

/// 奖励回调
/// - Parameter rewards: 奖励
- (void)rewardVideoOnRewarded:(NSDictionary *)rewards;

@end

NS_ASSUME_NONNULL_END
