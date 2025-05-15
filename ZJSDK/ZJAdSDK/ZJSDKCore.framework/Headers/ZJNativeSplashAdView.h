//
//  ZJNativeSplashAdView.h
//  ZJSDKCore
//
//  Created by 麻明康 on 2025/5/8.
//

#import <UIKit/UIKit.h>
#import <ZJSDKCore/ZJSDKDefines.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZJNativeSplashAdView : UIView

@property (nonatomic, strong) UIViewController *rootViewController;

@property (nonatomic, strong) UIView *customBottomView;

@property (nonatomic, strong) UIImageView *backgroundImageView;

@property (nonatomic, strong) UIButton *skipButton;

@property (nonatomic, strong) dispatch_source_t countdownTimer;

@property (nonatomic, assign) BOOL isTimerPaused;

@property (nonatomic, copy) void (^splashAdClosedBlock)(void);

@property (nonatomic, copy) void (^splashAdShowBlock)(void);

@property (nonatomic, copy) void (^splashAdClickBlock)(void);

@property (nonatomic, copy) void (^splashAdCountdownEndBlock)(void);

- (void)addSplashViewInWindow;

- (void)skipButtonDidClick:(UIButton *)sender;

@end

NS_ASSUME_NONNULL_END
