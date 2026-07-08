//
//  WindRewardVideoAd.h
//  WindSDK
//
//  Created by Codi on 2021/11/1.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "WindBiddingProtocol.h"
#import "WindAdMetaData.h"

@class WindAdRequest;
@class WindRewardInfo;
@class WindRewardVideoAd;

NS_ASSUME_NONNULL_BEGIN

@protocol WindRewardVideoAdDelegate<NSObject>

@required

/// 广告获得激励时回调
/// - Parameters:
///   - rewardVideoAd: WindRewardVideoAd 实例对象
///   - reward: 激励信息
- (void)rewardVideoAd:(WindRewardVideoAd *)rewardVideoAd reward:(WindRewardInfo *)reward;

@optional

/// 广告加载成功回调
/// - Parameter rewardVideoAd: WindRewardVideoAd 实例对象
- (void)rewardVideoAdDidLoad:(WindRewardVideoAd *)rewardVideoAd;

/// 广告加载错误回调
/// - Parameters:
///   - rewardVideoAd: WindRewardVideoAd 实例对象
///   - error: 具体的错误信息
- (void)rewardVideoAdDidLoad:(WindRewardVideoAd *)rewardVideoAd didFailWithError:(NSError *)error;

/// 广告将要曝光回调
/// - Parameter rewardVideoAd: WindRewardVideoAd 实例对象
- (void)rewardVideoAdWillVisible:(WindRewardVideoAd *)rewardVideoAd;

/// 广告曝光回调
/// - Parameter rewardVideoAd: WindRewardVideoAd 实例对象
- (void)rewardVideoAdDidVisible:(WindRewardVideoAd *)rewardVideoAd;

/// 广告展示失败回调
/// - Parameters:
///   - rewardVideoAd: WindRewardVideoAd 实例对象
///   - error: 具体错误信息
- (void)rewardVideoAdDidShowFailed:(WindRewardVideoAd *)rewardVideoAd error:(NSError *)error;

/// 广告点击回调
/// - Parameter rewardVideoAd: WindRewardVideoAd 实例对象
- (void)rewardVideoAdDidClick:(WindRewardVideoAd *)rewardVideoAd;

/// 广告点击跳过回调
/// - Parameter rewardVideoAd: WindRewardVideoAd 实例对象
- (void)rewardVideoAdDidClickSkip:(WindRewardVideoAd *)rewardVideoAd;

/// 广告闭关回调
/// - Parameter rewardVideoAd: WindRewardVideoAd 实例对象
- (void)rewardVideoAdDidClose:(WindRewardVideoAd *)rewardVideoAd;

/// 广告视频播放完成或者视频播放出错
/// - Parameters:
///   - rewardVideoAd: WindRewardVideoAd 实例对象
///   - error: 具体错误信息
- (void)rewardVideoAdDidPlayFinish:(WindRewardVideoAd *)rewardVideoAd didFailWithError:(NSError * _Nullable)error;

/// 广告数据返回回调
/// - Parameters:
///   - rewardVideoAd: WindRewardVideoAd 实例对象
///   - isFillAd: ture: 填充， false: 无广告数据
- (void)rewardVideoAdServerResponse:(WindRewardVideoAd *)rewardVideoAd isFillAd:(BOOL)isFillAd;



@end

@interface WindRewardVideoAd : NSObject<WindBiddingProtocol>

/// 广告代理对象
@property (nonatomic, weak) id<WindRewardVideoAdDelegate> delegate;

/// 广告位ID
@property (nonatomic, strong, readonly) NSString *placementId;

/// 广告是否有效
@property (nonatomic, getter=isAdReady, readonly) BOOL ready;

/// 广告元数据
@property (nonatomic, strong, readonly) WindAdMetaData *metaData;

/// 构造器
/// - Parameter request: 广告请求模型，可以设置广告位ID等参数
- (instancetype)initWithRequest:(WindAdRequest *)request;

/// 加载广告
- (void)loadAdData;

/// 加载Bidding广告
/// @param bidToken bidding广告的唯一标识
- (void)loadAdDataWithBidToken:(NSString *)bidToken;

/// 播放广告
/// @param rootViewController 播放广告所需要的ViewController
/// @param extras 扩展参数，用于设置播放时的代码位场景
- (void)showAdFromRootViewController:(UIViewController *)rootViewController
                             options:(NSDictionary<NSString *, NSString *> * _Nullable)extras;

@end

NS_ASSUME_NONNULL_END
