//
//  ZJ_CJRewardVideoAd.h
//  ZJ_CJAdSDK
//
//  Created by coderqi on 2025/11/14.
//

#import <Foundation/Foundation.h>
#import <ZJ_CJAdSDK/ZJ_CJRewardVideoSlot.h>
#import <ZJ_CJAdSDK/ZJ_CJBaseAd.h>

NS_ASSUME_NONNULL_BEGIN

@class ZJ_CJRewardVideoAd;
@class ZJ_CJRewardVideoSlot;

@protocol ZJ_CJRewardVideoAdDelegate <NSObject>

@optional
/**
 *  广告加载成功
 * @param rewardAd  广告对象
 */
- (void)zjcj_RewardAdLoadSuccess:(ZJ_CJRewardVideoAd *)rewardAd;

/**
 *  广告加载失败
 * @param rewardAd  广告对象
 * @param error  错误信息
 */
- (void)zjcj_RewardAdLoadFail:(ZJ_CJRewardVideoAd *)rewardAd withError:(NSError *)error;


/**
 * 广告展示成功
 * @param rewardAd  广告对象
 */
- (void)zjcj_RewardAdShowSuccess:(ZJ_CJRewardVideoAd *)rewardAd;

/**
 * 广告展示失败
 * @param rewardAd  广告对象
 */
- (void)zjcj_RewardAdShowFail:(ZJ_CJRewardVideoAd *)rewardAd withError:(NSError *)error;

/**
 * 广告播放开始
 * @param rewardAd  广告对象
 */
- (void)zjcj_RewardAdPlayStart:(ZJ_CJRewardVideoAd *)rewardAd;

/**
 * 广告播放结束
 * @param rewardAd  广告对象
 */
- (void)zjcj_RewardAdPlayFinished:(ZJ_CJRewardVideoAd *)rewardAd;

/**·
 * 广告点击
 * @param rewardAd  广告对象
 */
- (void)zjcj_RewardAdDidClicked:(ZJ_CJRewardVideoAd *)rewardAd;

/**
 * 广告关闭
 * @param rewardAd  广告对象
 */
- (void)zjcj_RewardAdDidClosed:(ZJ_CJRewardVideoAd *)rewardAd;

/**
 * 广告点击跳过
 * @param rewardAd  广告对象
 */
- (void)zjcj_RewardAdDidSkiped:(ZJ_CJRewardVideoAd *)rewardAd;

/**
 * sdk广告跳转落地页关闭回调
 * @param rewardAd  广告对象
 */
- (void)zjcj_RewardAdWebPageClose:(ZJ_CJRewardVideoAd *)rewardAd;

/**
 *  广告任务完成
 *  @param rewardAd  广告对象
 */
- (void)zjcj_RewardAdTaskCompleted:(ZJ_CJRewardVideoAd *)rewardAd;

@end

@interface ZJ_CJRewardVideoAd : ZJ_CJBaseAd

/// 广告请求参数
@property (nonatomic, strong, readonly) ZJ_CJRewardVideoSlot *adSlot;

@property (nonatomic, weak) id <ZJ_CJRewardVideoAdDelegate> delegate;

/**
 * @brief 初始化view
 */
- (instancetype)initWithSlot:(ZJ_CJRewardVideoSlot *)slot;

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
