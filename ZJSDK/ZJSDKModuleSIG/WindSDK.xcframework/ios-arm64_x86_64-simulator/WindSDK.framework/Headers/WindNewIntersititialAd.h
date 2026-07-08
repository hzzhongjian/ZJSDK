//
//  WindNewIntersititialAd.h
//  WindSDK
//
//  Created by Codi on 2023/04/16.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "WindBiddingProtocol.h"
#import "WindAdMetaData.h"

@class WindAdRequest;
@class WindNewIntersititialAd;

NS_ASSUME_NONNULL_BEGIN

@protocol WindNewIntersititialAdDelegate<NSObject>

@optional

/// 广告加载成功回调
/// - Parameter rewardVideoAd: WindNewIntersititialAd 实例对象
- (void)intersititialAdDidLoad:(WindNewIntersititialAd *)intersititialAd;

/// 广告加载出错
/// - Parameters:
///   - intersititialAd: WindNewIntersititialAd 实例对象
///   - error: 具体错误信息
- (void)intersititialAdDidLoad:(WindNewIntersititialAd *)intersititialAd didFailWithError:(NSError *)error;

/// 广告将要曝光回调
/// - Parameter rewardVideoAd: WindNewIntersititialAd 实例对象
- (void)intersititialAdWillVisible:(WindNewIntersititialAd *)intersititialAd;

/// 广告曝光回调
/// - Parameter rewardVideoAd: WindNewIntersititialAd 实例对象
- (void)intersititialAdDidVisible:(WindNewIntersititialAd *)intersititialAd;

/// 广告展示失败回调
/// - Parameters:
///   - intersititialAd: WindNewIntersititialAd 实例对象
///   - error: 具体错误信息
- (void)intersititialAdDidShowFailed:(WindNewIntersititialAd *)intersititialAd error:(NSError *)error;

/// 广告点击回调
/// - Parameter rewardVideoAd: WindNewIntersititialAd 实例对象
- (void)intersititialAdDidClick:(WindNewIntersititialAd *)intersititialAd;

/// 广告跳过回调
/// - Parameter rewardVideoAd: WindNewIntersititialAd 实例对象
- (void)intersititialAdDidClickSkip:(WindNewIntersititialAd *)intersititialAd;

/// 广告关闭回调
/// - Parameter rewardVideoAd: WindNewIntersititialAd 实例对象
- (void)intersititialAdDidClose:(WindNewIntersititialAd *)intersititialAd;

/// 广告数据返回回调
/// - Parameters:
///   - rewardVideoAd: WindNewIntersititialAd 实例对象
///   - isFillAd: ture: 填充， false: 无广告数据
- (void)intersititialAdServerResponse:(WindNewIntersititialAd *)intersititialAd isFillAd:(BOOL)isFillAd;

@end

@interface WindNewIntersititialAd : NSObject<WindBiddingProtocol>

/// 广告代理对象
@property (nonatomic, weak) id<WindNewIntersititialAdDelegate> delegate;

/// 广告位ID
@property (nonatomic, strong, readonly) NSString *placementId;

/// 检查广告是否有效
@property (nonatomic, getter=isAdReady, readonly) BOOL ready;

/// 广告元数据
@property (nonatomic, strong, readonly) WindAdMetaData *metaData;

/// 构造器 - 全屏插屏
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

