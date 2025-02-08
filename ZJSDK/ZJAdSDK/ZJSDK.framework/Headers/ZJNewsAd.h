//
//  ZJNewsAd.h
//  ZJSDK
//
//  Created by 麻明康 on 2025/1/7.
//  Copyright © 2025 zj. All rights reserved.
//

#import <ZJSDK/ZJSDK.h>
#import <ZJSDKCore/ZJNewsAdAdapter.h>
#import <ZJSDKCore/ZJNewsAdProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@class ZJNewsAd;

@protocol ZJNewsAdDelegate <NSObject>

/**
 news广告加载成功
 */
- (void)zj_newsAdDidLoad:(ZJNewsAd *)newsAd;

/**
 news广告加载失败
 */
- (void)zj_newsAd:(ZJNewsAd *)newsAd didLoadFailWithError:(NSError * _Nullable)error;

/**
 newsAdView曝光回调
 */
- (void)zj_newsAdDidShow:(ZJNewsAd *)newsAd;

/**
 关闭news广告回调
 */
- (void)zj_newsAdRewardEffective:(ZJNewsAd *)newsAd;

/**
 点击news广告回调
 */
- (void)zj_newsAdDidClick:(ZJNewsAd *)newsAd;

/**
 canGoBack状态监听
 */
- (void)zj_newsAd:(ZJNewsAd *)newsAd newsAdCanGoBackStateChange:(BOOL)canGoBack;

@end

@interface ZJNewsAd : ZJTierAd <ZJNewsAdProtocol>

@property (nonatomic, copy, readonly) NSString *placementId;

@property (nonatomic, assign) BOOL enableGoBackGesture;

@property (nonatomic, assign) BOOL enableSlide;

@property (nonatomic, strong,nullable) ZJNewsAdAdapter *currentAdapter;

@property (nonatomic, weak, nullable) id <ZJNewsAdDelegate> delegate;

- (instancetype)initWithPlacementId:(NSString *)placementId frame:(CGRect)frame;

- (UIView *)newAdView;

- (BOOL)canGoBack;

- (void)goBack;

- (void)goForward;

- (BOOL)canGoForward;

@end

NS_ASSUME_NONNULL_END
