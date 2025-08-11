//
//  JYSplashAd.h
//  JYAdSDK
//
//  Created by jyad110 on 2021/4/20.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <JYAdSDK/JYAdSDKConfig.h>

NS_ASSUME_NONNULL_BEGIN

@class JYSplashAd;

@protocol JYSplashAdDelegate <NSObject>

@optional

- (void)jy_splashAdDidLoad:(JYSplashAd *)splashAd;
- (void)jy_splashAdDidFailToLoad:(JYSplashAd *)splashAd error:(NSError *)error;
- (void)jy_splashAdDidPresent:(JYSplashAd *)splashAd;
- (void)jy_splashAdDidExpose:(JYSplashAd *)splashAd;
- (void)jy_splashAdDidClick:(JYSplashAd *)splashAd;
- (void)jy_splashAdWillClose:(JYSplashAd *)splashAd;
- (void)jy_splashAdDidClose:(JYSplashAd *)splashAd;
- (void)jy_splashAdLifeTime:(JYSplashAd *)splashAd time:(NSUInteger)time;
- (void)jy_splashAdDidCloseOtherController:(JYSplashAd *)splashAd;
- (void)jy_splashAdDidPresentFullScreenModal:(JYSplashAd *)splashAd;

@end

@interface JYSplashAd : NSObject <JYAdProtocol>

@property (nonatomic, weak, nullable) id<JYSplashAdDelegate> delegate;
@property (nonatomic, assign) BOOL videoMuted;
@property (nonatomic, assign) BOOL legacyH5;/// 临时开关：是否浏览器打开落地页
@property (nonatomic, assign, readonly) JYAdSdkUnionType unionType;
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
- (NSDictionary * _Nullable)extraInfo;
- (void)sendWinNotificationWithInfo:(NSDictionary *)winInfo;
- (void)sendLossNotificationWithInfo:(NSDictionary *)lossInfo;

@end

NS_ASSUME_NONNULL_END
