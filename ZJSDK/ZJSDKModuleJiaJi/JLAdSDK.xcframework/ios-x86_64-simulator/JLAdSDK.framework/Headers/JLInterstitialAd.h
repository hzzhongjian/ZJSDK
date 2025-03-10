//
//  JLInterstitialAd.h
//  JLAdSDK
//
//  Created by jlad110 on 2021/4/19.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <JLAdSDK/JLAdSDKConfig.h>

NS_ASSUME_NONNULL_BEGIN

@class JLInterstitialAd;

@protocol JLInterstitialAdDelegate <NSObject>

@optional

- (void)jl_interstitialAdDidLoad:(JLInterstitialAd *)interstitialAd;
- (void)jl_interstitialAdDidFailToLoad:(JLInterstitialAd *)interstitialAd error:(NSError *)error;
- (void)jl_interstitialAdDidExpose:(JLInterstitialAd *)interstitialAd;
- (void)jl_interstitialAdDidClick:(JLInterstitialAd *)interstitialAd;
- (void)jl_interstitialAdDidClose:(JLInterstitialAd *)interstitialAd;
- (void)jl_interstitialAdDidCloseOtherController:(JLInterstitialAd *)interstitialAd;
- (void)jl_interstitialAdDidPresentFullScreenModal:(JLInterstitialAd *)interstitialAd;

@end

@interface JLInterstitialAd : NSObject <JLAdProtocol>

@property (nonatomic, weak, nullable) id<JLInterstitialAdDelegate> delegate;
@property (nonatomic, assign, readonly) JLAdSdkUnionType unionType;

/// 自动播放时，是否静音。默认 YES。loadAd 前设置。
@property (nonatomic, assign) BOOL videoMuted;

- (instancetype)initWithSlotId:(NSString *)slotId adSize:(CGSize)adSize;
- (void)loadAd;
- (void)showAdFromRootViewController:(UIViewController *)viewController;
- (BOOL)isValid;
- (NSInteger)eCPM;
- (void)sendWinNotificationWithInfo:(NSDictionary *)winInfo;
- (void)sendLossNotificationWithInfo:(NSDictionary *)lossInfo;

@end

NS_ASSUME_NONNULL_END
