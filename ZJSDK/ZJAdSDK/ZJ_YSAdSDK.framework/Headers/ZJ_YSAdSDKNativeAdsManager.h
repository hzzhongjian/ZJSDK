//
//  ZJ_YSAdSDKNativeAdsManager.h
//  ZJ_YSAdSDK
//
//  Created by yanchao on 2025/5/28.
//
//  信息流广告管理器（API 自渲染）
//
//  典型使用流程：
//    1. initWithPlacementId: 初始化
//    2. 设置 delegate
//    3. 调用 loadAdData 发起请求
//    4. 在 nativeAdsManagerSuccessToLoad:nativeAds: 回调中拿到 ZJ_YSAdSDKNativeAd 数组
//    5. 用 nativeAd.data 填充自定义 Cell，调用 registerContainer:withClickableViews: 绑定

#import <UIKit/UIKit.h>
#import "ZJ_YSAdSDKNativeAd.h"

NS_ASSUME_NONNULL_BEGIN

@class ZJ_YSAdSDKNativeAdsManager;

@protocol ZJ_YSAdSDKNativeAdsManagerDelegate <NSObject>

@optional

/**
 广告加载成功
 @param adsManager  管理器实例
 @param nativeAdDataArray  广告数组，每条为 ZJ_YSAdSDKNativeAd
 */
- (void)nativeAdsManagerSuccessToLoad:(ZJ_YSAdSDKNativeAdsManager *)adsManager
                            nativeAds:(nullable NSArray<ZJ_YSAdSDKNativeAd *> *)nativeAdDataArray;

/**
 广告加载失败
 */
- (void)nativeAdsManager:(ZJ_YSAdSDKNativeAdsManager *)adsManager
        didFailWithError:(nullable NSError *)error;

@end


@interface ZJ_YSAdSDKNativeAdsManager : NSObject

/// 代理
@property (nonatomic, weak) id<ZJ_YSAdSDKNativeAdsManagerDelegate> delegate;

/// 媒体附加信息（含 requestId 等）
@property (nonatomic, readonly) NSDictionary *mediaExtraInfo;

/// 竞价价格
- (double)salePrice;

#pragma mark - Bidding

/// 获取 buyerId，用于 Server Bidding 请求
- (NSString *)getBuyerIdWithContext:(nullable NSDictionary *)info;

/**
 获取用于 Server Bidding 请求SDK侧相关请求参数信息
 不阻塞主线程，token 获取和广告预请求完成后通过 completion 回调 sdkInfo
 */
- (void)getSDKInfoWithPlacementId:(NSInteger)placementId completion:(void(^)(NSString *sdkInfo))completion;

/// 发送竞胜通知
- (void)sendWinNotificationWithPrice:(NSInteger)price;

/// 发送竞败通知
- (void)sendWinFailNotificationWithPrice:(NSInteger)price;

#pragma mark - 初始化

/**
 初始化信息流广告管理器
 @param placementId 广告位 ID
 */
- (instancetype)initWithPlacementId:(NSInteger)placementId;

#pragma mark - 加载

/// 加载信息流广告
- (void)loadAdData;

/**
 S2S Bidding 模式：拿到 token 后调用
 @param token  Server Bidding 返回的 token
 */
- (void)loadAdDataWithToken:(NSString *)token;

@end

NS_ASSUME_NONNULL_END
