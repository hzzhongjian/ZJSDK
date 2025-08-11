//
//  JYBannerAdView.h
//  JYAdSDK
//
//  Created by jyad110 on 2021/4/15.
//

#import <UIKit/UIKit.h>
#import <JYAdSDK/JYAdSDKConfig.h>

NS_ASSUME_NONNULL_BEGIN

@class JYBannerAdView;

@protocol JYBannerAdViewDelegate <NSObject>

@optional

- (void)jy_bannerAdViewDidLoad:(JYBannerAdView *)bannerAd;
- (void)jy_bannerAdViewDidFailToLoad:(JYBannerAdView *)bannerAd error:(NSError *)error;
- (void)jy_bannerAdViewDidExpose:(JYBannerAdView *)bannerAd;
- (void)jy_bannerAdViewDidClick:(JYBannerAdView *)bannerAd;
- (void)jy_bannerAdViewDidClose:(JYBannerAdView *)bannerAd;
- (void)jy_bannerAdViewDidCloseOtherController:(JYBannerAdView *)bannerAd;
- (void)jy_bannerAdViewDidPresentFullScreenModal:(JYBannerAdView *)bannerAd;

@end

@interface JYBannerAdView : UIView <JYAdProtocol>

@property (nonatomic, weak, nullable) id<JYBannerAdViewDelegate> delegate;
@property (nonatomic, assign) BOOL videoMuted;
@property (nonatomic, assign, readonly) JYAdSdkUnionType unionType;

/// 广告刷新间隔，范围 [30, 120] 秒，默认值 30 秒。设 0 则不刷新。 [可选，只对广点通、穿山甲有效]
@property (nonatomic, assign) NSInteger autoSwitchInterval;

- (instancetype)initWithFrame:(CGRect)frame slotId:(NSString *)slotId viewController:(UIViewController *)viewController;

- (void)loadAd;
- (NSInteger)eCPM;
- (NSDictionary * _Nullable)extraInfo;
- (void)sendWinNotificationWithInfo:(NSDictionary *)winInfo;
- (void)sendLossNotificationWithInfo:(NSDictionary *)lossInfo;

@end

NS_ASSUME_NONNULL_END
