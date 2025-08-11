//
//  JYInterstitialAd.h
//  JYAdSDK
//
//  Created by jyad110 on 2021/4/19.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <JYAdSDK/JYAdSDKConfig.h>

NS_ASSUME_NONNULL_BEGIN

@class JYInterstitialAd;

@protocol JYInterstitialAdDelegate <NSObject>

@optional

- (void)jy_interstitialAdDidLoad:(JYInterstitialAd *)interstitialAd;
- (void)jy_interstitialAdDidFailToLoad:(JYInterstitialAd *)interstitialAd error:(NSError *)error;
- (void)jy_interstitialAdDidExpose:(JYInterstitialAd *)interstitialAd;
- (void)jy_interstitialAdDidClick:(JYInterstitialAd *)interstitialAd;
- (void)jy_interstitialAdDidClose:(JYInterstitialAd *)interstitialAd;
- (void)jy_interstitialAdDidCloseOtherController:(JYInterstitialAd *)interstitialAd;
- (void)jy_interstitialAdDidPresentFullScreenModal:(JYInterstitialAd *)interstitialAd;

@end

@interface JYInterstitialAd : NSObject <JYAdProtocol>

@property (nonatomic, weak, nullable) id<JYInterstitialAdDelegate> delegate;
@property (nonatomic, assign, readonly) JYAdSdkUnionType unionType;

/// 自动播放时，是否静音。默认 YES。loadAd 前设置。
@property (nonatomic, assign) BOOL videoMuted;

- (instancetype)initWithSlotId:(NSString *)slotId adSize:(CGSize)adSize;
- (void)loadAd;
- (void)showAdFromRootViewController:(UIViewController *)viewController;
- (BOOL)isValid;
- (NSInteger)eCPM;
- (NSDictionary * _Nullable)extraInfo;
- (void)sendWinNotificationWithInfo:(NSDictionary *)winInfo;
- (void)sendLossNotificationWithInfo:(NSDictionary *)lossInfo;

@end

NS_ASSUME_NONNULL_END
