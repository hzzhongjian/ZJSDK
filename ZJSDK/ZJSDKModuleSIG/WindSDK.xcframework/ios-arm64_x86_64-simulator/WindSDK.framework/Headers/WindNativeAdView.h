//
//  WindNativeAdView.h
//  WindSDK
//
//  Created by Codi on 2021/11/2.
//

#import <UIKit/UIKit.h>

@class WindNativeAd;
@class WindDislikeWords;
@class WindNativeAdView;
@class WindMediaView;
@class WindLogoView;

typedef NS_ENUM(NSUInteger, WindMediaPlayerStatus) {
    WindMediaPlayerStatusInitial = 0,         // 初始状态
    WindMediaPlayerStatusLoading = 1,         // 加载中
    WindMediaPlayerStatusStarted = 2,         // 开始播放
    WindMediaPlayerStatusPaused = 3,          // 用户行为导致暂停
    WindMediaPlayerStatusError = 4,           // 播放出错
    WindMediaPlayerStatusStoped = 5,          // 播放停止
};

NS_ASSUME_NONNULL_BEGIN

@protocol WindNativeAdViewDelegate <NSObject>

@optional

/// 广告曝光回调
/// @param nativeAdView WindNativeAdView 实例
- (void)nativeAdViewWillExpose:(WindNativeAdView *)nativeAdView;

/// 广告点击回调
/// @param nativeAdView WindNativeAdView 实例
- (void)nativeAdViewDidClick:(WindNativeAdView *)nativeAdView;

/// 视频广告播放状态更改回调
/// @param nativeAdView WindNativeAdView 实例
/// @param status 视频广告播放状态
/// @param userInfo 视频信息
- (void)nativeAdView:(WindNativeAdView *)nativeAdView
 playerStatusChanged:(WindMediaPlayerStatus)status
            userInfo:(NSDictionary *)userInfo;

/// 广告dislike回调
/// @param nativeAdView WindNativeAdView 实例
/// @param filterWords 选择不喜欢的原因
/// @warning 开发者需要在这个回调中移除视图，否则，会出现用户点击叉无效的情况
- (void)nativeAdView:(WindNativeAdView *)nativeAdView dislikeWithReason:(NSArray<WindDislikeWords *> *)filterWords;

@end


@interface WindNativeAdView : UIView

/// 广告代理对象
@property (nonatomic, weak) id<WindNativeAdViewDelegate> delegate;

/// 广告数据模型
@property (nonatomic, strong, readonly) WindNativeAd *nativeAd;

/// 广告点击时依赖的ViewController
@property (nonatomic, weak) UIViewController *viewController;

/// 视频组件 [模版渲染时位nil]
@property (nonatomic, strong, readonly, nullable) WindMediaView *mediaView;

/// 广告平台logo组件 [模版渲染时位nil]
@property (nonatomic, strong, readonly, nullable) UIView *logoView;

/// 广告dislike组件 [模版渲染时位nil]
@property (nonatomic, strong, readonly, nullable) UIButton *dislikeButton;



/// 刷新广告数据
/// @param nativeAd 广告模型数据
/// @warning 每次获取物料信息后需要刷新调用refreshData:方法
- (void)refreshData:(WindNativeAd *)nativeAd;

/// 绑定展示的图片视图
/// @param imageViews 进行渲染的 imageView
/// @param placeholder 图片加载过程中的占位图
/// @warning 需要在refreshData方法之后绑定，否则数据无法渲染
- (void)bindImageViews:(NSArray<UIImageView *> *)imageViews placeholder:(UIImage *)placeholder;

/// 绑定点击的View
/// @param clickableViews 需要注册点击View的集合
- (void)setClickableViews:(NSArray<UIView *> *)clickableViews;

/// 注销数据对象
/// @warning 在 tableView、collectionView 等场景需要复用 WindNativeAdView 时，需要在合适的时机，例如 cell 的 prepareForReuse 方法内执行 unregisterDataObject 方法，将广告对象与 WindNativeAdView 解绑
- (void)unregisterDataObject;

@end

NS_ASSUME_NONNULL_END
