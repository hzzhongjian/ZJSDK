//
//  WindNativeAdsManager.h
//  WindSDK
//
//  Created by Codi on 2021/11/2.
//

#import <Foundation/Foundation.h>
#import "WindBiddingProtocol.h"

@class WindAdRequest;
@class WindNativeAd;
@class WindNativeAdsManager;

NS_ASSUME_NONNULL_BEGIN

@protocol WindNativeAdsManagerDelegate <NSObject>

@optional

/// 广告加载成功回调
/// - Parameters:
///   - adsManager: WindNativeAdsManager 示例对象
///   - nativeAdDataArray: 返回的广告数组
- (void)nativeAdsManagerSuccessToLoad:(WindNativeAdsManager *)adsManager
                            nativeAds:(NSArray<WindNativeAd *> *)nativeAdDataArray;

/// 广告加载出错回调
/// - Parameters:
///   - adsManager: WindNativeAdsManager 示例对象
///   - error: 具体错误信息
- (void)nativeAdsManager:(WindNativeAdsManager *)adsManager
        didFailWithError:(NSError *)error;

@end


@interface WindNativeAdsManager : NSObject <WindBiddingProtocol>

/// 广告代理对象
@property (nonatomic, weak) id<WindNativeAdsManagerDelegate> delegate;

/// 广告位ID
@property (nonatomic, strong, readonly) NSString *placementId;

/// 构造器
/// - Parameter request: 广告请求模型，可以设置广告位ID等参数
- (instancetype)initWithRequest:(WindAdRequest *)request;

/// 加载广告
/// @param count 加载广告的个数，推荐一次性不要超过3条，默认1条
- (void)loadAdDataWithCount:(NSInteger)count;

/// 加载Bidding广告
/// @param bitToken bidding广告的唯一标识
/// @param count 加载广告的个数，推荐一次性不要超过3条，默认1条
- (void)loadAdDataWithBitToken:(NSString *)bitToken
                       adCount:(NSInteger)count;


@end

NS_ASSUME_NONNULL_END
