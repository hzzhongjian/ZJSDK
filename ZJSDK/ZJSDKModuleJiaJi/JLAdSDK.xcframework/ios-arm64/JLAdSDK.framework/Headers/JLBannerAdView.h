//
//  JLBannerAdView.h
//  JLAdSDK
//
//  Created by jlad110 on 2021/4/15.
//

#import <UIKit/UIKit.h>
#import <JLAdSDK/JLAdSDKConfig.h>

NS_ASSUME_NONNULL_BEGIN

@class JLBannerAdView;

@protocol JLBannerAdViewDelegate <NSObject>

@optional

- (void)jl_bannerAdViewDidLoad:(JLBannerAdView *)bannerAd;
- (void)jl_bannerAdViewDidFailToLoad:(JLBannerAdView *)bannerAd error:(NSError *)error;
- (void)jl_bannerAdViewDidExpose:(JLBannerAdView *)bannerAd;
- (void)jl_bannerAdViewDidClick:(JLBannerAdView *)bannerAd;
- (void)jl_bannerAdViewDidClose:(JLBannerAdView *)bannerAd;
- (void)jl_bannerAdViewDidCloseOtherController:(JLBannerAdView *)bannerAd;
- (void)jl_bannerAdViewDidPresentFullScreenModal:(JLBannerAdView *)bannerAd;

@end

@interface JLBannerAdView : UIView <JLAdProtocol>

@property (nonatomic, weak, nullable) id<JLBannerAdViewDelegate> delegate;
@property (nonatomic, assign) BOOL videoMuted;
@property (nonatomic, assign, readonly) JLAdSdkUnionType unionType;

/// 广告刷新间隔，范围 [30, 120] 秒，默认值 30 秒。设 0 则不刷新。 [可选，只对广点通、穿山甲有效]
@property (nonatomic, assign) NSInteger autoSwitchInterval;

- (instancetype)initWithFrame:(CGRect)frame slotId:(NSString *)slotId viewController:(UIViewController *)viewController;

- (void)loadAd;
- (NSInteger)eCPM;
- (void)sendWinNotificationWithInfo:(NSDictionary *)winInfo;
- (void)sendLossNotificationWithInfo:(NSDictionary *)lossInfo;

@end

NS_ASSUME_NONNULL_END
