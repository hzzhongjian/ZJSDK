//
//  ZJNativeInterstitialAdVC.h
//  ZJSDKCore
//
//  Created by 麻明康 on 2025/10/31.
//

#import <UIKit/UIKit.h>
#import <ZJSDKCore/ZJCommon.h>


NS_ASSUME_NONNULL_BEGIN

// 自渲染填充插屏的视图

@class ZJNativeInterstitialAdVC;

@protocol ZJNativeInterstitialAdVCDelegate <NSObject>

/**
 *  广告曝光成功
 */
- (void)nativeAdExposure:(ZJNativeInterstitialAdVC *)nativeAdVC;

/**
 *  广告曝光失败
 */
- (void)nativeAdExposureFail:(ZJNativeInterstitialAdVC *)nativeAdVC;

/**
 *  广告点击
 */
- (void)nativeAdClicked:(ZJNativeInterstitialAdVC *)nativeAdVC;

/**
 *  广告详情页关闭
 */
- (void)didDismissLandingPage:(ZJNativeInterstitialAdVC *)nativeAdVC;

/**
 *  联盟官网点击跳转
 */
- (void)unionAdClicked:(ZJNativeInterstitialAdVC *)nativeAdVC;

/**
 *  关闭按钮点击
 */
- (void)nativeAdCloseClick:(ZJNativeInterstitialAdVC *)nativeAdVC;

/**
 * BaiduMobAdExpressNativeView组件渲染成功
 */
- (void)nativeAdExpressSuccessRender:(ZJNativeInterstitialAdVC *)nativeAdVC;

@end

@interface ZJNativeInterstitialAdVC : UIViewController

@property (nonatomic, weak) id <ZJNativeInterstitialAdVCDelegate> delegate;

@property (nonatomic, strong) UIButton *muteButton;

@property (nonatomic, strong) UIButton *closeButton;

@property (nonatomic, strong) UIView *backgroundView;

@property (nonatomic, strong) UIImageView *backgroundImageView;

@property (nonatomic, strong) UIImageView *iconImageView;

@property (nonatomic, strong) UILabel *titleLabel;

@property (nonatomic, strong) UILabel *descLabel;

@property (nonatomic, strong) UIButton *view_detail_button;

@property (nonatomic, strong) UIButton *click_jump_button;

- (void)buildView;

// 半屏幕
- (void)halfScreen;

// 全屏
- (void)fullScreen;

// 静音按钮点击事件，默认静音
- (void)muteButtonDidClick:(UIButton *)sender;

// 关闭按钮点击事件
- (void)closeButtonDidClick:(UIButton *)sender;

@end

NS_ASSUME_NONNULL_END
