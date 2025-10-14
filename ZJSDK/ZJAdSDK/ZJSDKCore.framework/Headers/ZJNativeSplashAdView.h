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

// 详情页跳转的根视图控制器
@property (nonatomic, strong) UIViewController *rootViewController;

// 自定义底部的LogoView
@property (nonatomic, strong) UIView *customBottomView;

// 背景图片
@property (nonatomic, strong) UIImageView *backgroundImageView;

// 跳过按钮
@property (nonatomic, strong) UIButton *skipButton;

// ICON图片
@property (nonatomic, strong) UIImageView *iconImageView;

// 标题展示
@property (nonatomic, strong) UILabel *titleLabel;

// 详情描述
@property (nonatomic, strong) UILabel *descLabel;

@property (nonatomic, strong) dispatch_source_t countdownTimer;

@property (nonatomic, assign) BOOL isTimerPaused;

/// 广告关闭的回调
@property (nonatomic, copy) void (^splashAdClosedBlock)(void);

/// 广告曝光的回调
@property (nonatomic, copy) void (^splashAdShowBlock)(void);

/// 广告点击的回调
@property (nonatomic, copy) void (^splashAdClickBlock)(void);

/// 广告倒计时结束的回调
@property (nonatomic, copy) void (^splashAdCountdownEndBlock)(void);

/// 广告落地页展示的回调
@property (nonatomic, copy) void (^splashAdDetailViewShowBlock)(void);

/// 广告落地页关闭的回调
@property (nonatomic, copy) void (^splashAdDetailViewCloseBlock)(void);

- (void)addSplashViewInWindow;

- (void)skipButtonDidClick:(UIButton *)sender;

@end

NS_ASSUME_NONNULL_END
