//
//  ZJNativeSplashAdView.h
//  ZJSDKCore
//
//  Created by 麻明康 on 2025/10/27.
//

#import <UIKit/UIKit.h>
#import <ZJSDKCore/ZJCommon.h>
#import <ZJSDKCore/ZJShakeActionUtils.h>
#import <ZJSDKCore/ZJNativeButton.h>



NS_ASSUME_NONNULL_BEGIN

// 自渲染填充开屏的视图

@class ZJNativeSplashAdView;

@protocol ZJNativeSplashAdViewDelegate <NSObject>

/// 广告关闭的回调
- (void)nativeSplashAdClosed:(ZJNativeSplashAdView *)nativeSplashAd;

/// 广告曝光的回调
- (void)nativeSplashAdShow:(ZJNativeSplashAdView *)nativeSplashAd;

/// 广告点击跳过按钮
- (void)nativeSplashAdSkipClick:(ZJNativeSplashAdView *)nativeSplashAd;

/// 广告点击的回调
- (void)nativeSplashAdClick:(ZJNativeSplashAdView *)nativeSplashAd;

/// 广告倒计时结束的回调
- (void)nativeSplashAdCountdownEnd:(ZJNativeSplashAdView *)nativeSplashAd;

/// 广告落地页展示的回调
- (void)nativeSplashAdDetailViewShow:(ZJNativeSplashAdView *)nativeSplashAd;

/// 广告落地页关闭的回调
- (void)nativeSplashAdDetailViewCloseBlock:(ZJNativeSplashAdView *)nativeSplashAd;

@end

@interface ZJNativeSplashAdView : UIView


// 自定义底部的LogoView
@property (nonatomic, strong) UIView *customBottomView;

// 背景图片
@property (nonatomic, strong) UIImageView *backgroundImageView;

// 跳过按钮
@property (nonatomic, strong) ZJNativeButton *skipButton;
//@property (nonatomic, strong) UIButton *skipButton;

// ICON图片
@property (nonatomic, strong) UIImageView *iconImageView;

// 标题展示
@property (nonatomic, strong) UILabel *titleLabel;

// 详情描述
@property (nonatomic, strong) UILabel *descLabel;

// 静音按钮
@property (nonatomic, strong) UIButton *muteBtn;

// 点击下载/查看/跳转按钮
@property (nonatomic, strong) UIButton *click_jump_button;

// 是否静音，默认为YES静音，NO为非静音
@property (nonatomic, assign) BOOL mutedIfCan;

// 设置倒计时时长，单位为s，默认为5s
@property (nonatomic, assign) int remainingSeconds;

@property (nonatomic, strong) dispatch_source_t countdownTimer;

@property (nonatomic, assign) BOOL isTimerPaused;

@property (nonatomic, assign) id <ZJNativeSplashAdViewDelegate> delegate;

@property (nonatomic, strong) UIViewController *rootViewController;

//@property (strong, nonatomic) ZJShakeActionUtils *shakeActionUtils;

- (void)buildView;

- (void)addTimer;

- (void)cancelCountdown;

- (void)skipButtonDidClick:(UIButton *)sender;

- (void)muteBtnDidClick:(UIButton *)sender;

//- (void)removeShake;

- (void)clickJumpButtonDidClick:(UIButton *)sender;

@end

NS_ASSUME_NONNULL_END
