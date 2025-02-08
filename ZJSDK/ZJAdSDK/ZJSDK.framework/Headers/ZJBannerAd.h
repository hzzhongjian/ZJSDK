//
//  ZJBannerAd.h
//  ZJSDK
//
//  Created by 麻明康 on 2025/1/3.
//  Copyright © 2025 zj. All rights reserved.
//

#import <ZJSDK/ZJSDK.h>
#import <ZJSDKCore/ZJBannerAdAdapter.h>
#import <ZJSDKCore/ZJBannerAdProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@class ZJBannerAd;

@protocol ZJBannerAdDelegate <NSObject>

/**
 banner广告加载成功
 */
- (void)zj_bannerAdDidLoad:(ZJBannerAd *)bannerAd;

/**
 banner广告加载失败
 */
- (void)zj_bannerAd:(ZJBannerAd *)bannerAd didLoadFailWithError:(NSError * _Nullable)error;

/**
 bannerAdView曝光回调
 */
- (void)zj_bannerAdWillBecomVisible:(ZJBannerAd *)bannerAd;

/**
 关闭banner广告回调
 */
- (void)zj_bannerAdDislike:(ZJBannerAd *)bannerAd;

/**
 点击banner广告回调
 */
- (void)zj_bannerAdDidClick:(ZJBannerAd *)bannerAd;

/**
 关闭banner广告详情页回调
 */
- (void)zj_bannerAdDidCloseOtherController:(ZJBannerAd *)bannerAd;

@end

@interface ZJBannerAd : ZJTierAd

/// interval  广告刷新间隔，范围 [30, 120] 秒，默认值 30 秒。设 0 则不刷新。
@property (nonatomic, assign) CGFloat interval;

@property (nonatomic, strong) UIViewController *rootViewController;

@property (nonatomic, weak) id <ZJBannerAdDelegate> delegate;

@property (nonatomic, strong,nullable) ZJBannerAdAdapter *currentAdapter;

@property (nonatomic, assign) CGSize adSize;

- (instancetype)initWithPlacementId:(NSString *)placementId
                 rootViewController:(UIViewController *)rootViewController
                             adSize:(CGSize)adSize;

// 需要展示的bannerView
- (UIView *)bannerView;

@end

NS_ASSUME_NONNULL_END
