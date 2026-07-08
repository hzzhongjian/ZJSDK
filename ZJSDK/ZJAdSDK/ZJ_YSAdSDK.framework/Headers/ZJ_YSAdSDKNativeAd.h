//
//  ZJ_YSAdSDKNativeAd.h
//  ZJ_YSAdSDK
//
//  Created by yanchao on 2026/3/24.
//
//  单条广告数据 + 交互绑定层
//  使用方：
//    1. 从 ZJ_YSAdSDKNativeAdsManager 回调中拿到 ZJ_YSAdSDKNativeAd 数组
//    2. 用 data（ZJ_YSAdSDKMaterialMeta）填充自定义 Cell UI
//    3. 调用 registerContainer:withClickableViews: 绑定容器和可点击区域
//    4. SDK 自动处理曝光上报；点击由 SDK 触发跳转并回调 delegate

#import <UIKit/UIKit.h>
#import "ZJ_YSAdSDKMaterialMeta.h"

NS_ASSUME_NONNULL_BEGIN

@class ZJ_YSAdSDKNativeAd;

@protocol ZJ_YSAdSDKNativeAdDelegate <NSObject>

@optional

/// 广告曝光
- (void)nativeAdDidExpose:(ZJ_YSAdSDKNativeAd *)nativeAd;

/// 广告被点击
- (void)nativeAdDidClick:(ZJ_YSAdSDKNativeAd *)nativeAd;

/// 广告关闭（用户点击不喜欢等）
- (void)nativeAdDidClose:(ZJ_YSAdSDKNativeAd *)nativeAd;

/// 广告关闭了另一个控制器（落地页返回）
- (void)nativeAdDidCloseOtherController:(ZJ_YSAdSDKNativeAd *)nativeAd;

@end


@interface ZJ_YSAdSDKNativeAd : NSObject

/// 广告素材数据，用于填充自定义 UI
@property (nonatomic, strong, readonly) ZJ_YSAdSDKMaterialMeta *data;

/// 代理
@property (nonatomic, weak, nullable) id<ZJ_YSAdSDKNativeAdDelegate> delegate;

/// 展示所在的控制器（用于落地页跳转）
@property (nonatomic, weak) UIViewController *rootViewController;

/**
 * 绑定广告容器视图和可点击区域
 * 调用后 SDK 开始监听曝光，点击 clickableViews 中的视图触发跳转
 *
 * @param containerView   承载广告的自定义 View（如 Cell 的 contentView）
 * @param clickableViews  可点击的子视图数组（如图片、按钮），传 nil 则整个容器可点击
 * @param closeButton     接入方自定义的关闭按钮，SDK 负责绑定点击事件并触发 nativeAdDidClose: 回调
 *                        传 nil 则不绑定关闭逻辑
 */
- (void)registerContainer:(__kindof UIView *)containerView
       withClickableViews:(nullable NSArray<__kindof UIView *> *)clickableViews
              closeButton:(nullable UIButton *)closeButton;

/**
 * 解绑，在 Cell 复用或广告销毁时调用
 */
- (void)unregisterView;

@end

NS_ASSUME_NONNULL_END
