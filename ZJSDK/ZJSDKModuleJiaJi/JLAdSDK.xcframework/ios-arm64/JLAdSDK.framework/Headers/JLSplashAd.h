//
//  JLSplashAd.h
//  JLAdSDK
//
//  Created by jlad110 on 2021/4/20.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <JLAdSDK/JLAdSDKConfig.h>

NS_ASSUME_NONNULL_BEGIN

@class JLSplashAd;

@protocol JLSplashAdDelegate <NSObject>

@optional

- (void)jl_splashAdDidLoad:(JLSplashAd *)splashAd;
- (void)jl_splashAdDidFailToLoad:(JLSplashAd *)splashAd error:(NSError *)error;
- (void)jl_splashAdDidPresent:(JLSplashAd *)splashAd;
- (void)jl_splashAdDidExpose:(JLSplashAd *)splashAd;
- (void)jl_splashAdDidClick:(JLSplashAd *)splashAd;
- (void)jl_splashAdWillClose:(JLSplashAd *)splashAd;
- (void)jl_splashAdDidClose:(JLSplashAd *)splashAd;
- (void)jl_splashAdLifeTime:(JLSplashAd *)splashAd time:(NSUInteger)time;
- (void)jl_splashAdDidCloseOtherController:(JLSplashAd *)splashAd;
- (void)jl_splashAdDidPresentFullScreenModal:(JLSplashAd *)splashAd;

@end

@interface JLSplashAd : NSObject <JLAdProtocol>

@property (nonatomic, weak, nullable) id<JLSplashAdDelegate> delegate;
@property (nonatomic, assign) BOOL videoMuted;
@property (nonatomic, assign) BOOL legacyH5;/// 临时开关：是否浏览器打开落地页
@property (nonatomic, assign, readonly) JLAdSdkUnionType unionType;
@property (nonatomic, strong, nullable) UIView * customBottomView;
@property (nonatomic, weak, nullable) UIViewController * viewController;
@property (nonatomic, assign) NSTimeInterval tolerateTimeout;

- (instancetype)initWithFrame:(CGRect)frame slotId:(NSString *)slotId;

#pragma mark - Deprecated
- (instancetype)initWithFrame:(CGRect)frame slotId:(NSString *)slotId viewController:(UIViewController *)viewController DEPRECATED_MSG_ATTRIBUTE("replace with initWithFrame:slotId: and setViewController");

- (void)loadAd;

#pragma mark - Deprecated
- (void)showAdInWindow:(UIWindow *)window withBottomView:(UIView *_Nullable)bottomView DEPRECATED_MSG_ATTRIBUTE("This method will not work for GroMore, replace with setCustomBottomView and showAdInWindow:");

- (void)showAdInWindow:(UIWindow *)window;
- (void)dismiss;
- (BOOL)isValid;
- (NSInteger)eCPM;
- (void)sendWinNotificationWithInfo:(NSDictionary *)winInfo;
- (void)sendLossNotificationWithInfo:(NSDictionary *)lossInfo;

@end

NS_ASSUME_NONNULL_END
