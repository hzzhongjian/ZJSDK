//
//  WanjaAdNative.h
//  WanjaopusAdDemo
//
//  Created by guantou on 2023/11/16.
//
#import "WanjaopusBaseAd.h"
#import "WanjaNativeAdDataModel.h"

NS_ASSUME_NONNULL_BEGIN

@protocol WanjaAdNativeDelegate;

@interface WanjaAdNative : WanjaopusBaseAd

// controller 展示view的控制器或者弹出落地页的需要的控制器，此参数不能为空
@property (nonatomic, weak) UIViewController *controller;

// 设置原生广告的代理
@property (nonatomic, weak)id<WanjaAdNativeDelegate> delegate;

// 原生初始化
- (instancetype)initWithSlotId:(NSString *)slotId;
// isSelfRender：是否是自渲染。 默认为NO； 如果设置为YES， 那么就需要开发者自己渲染视图了， nativeAdViews将无效
- (instancetype)initWithSlotId:(NSString *)slotId isSelfRender:(BOOL)isSelfRender;

// 加载广告
- (void)loadAd;

// 获取广告返回价格(价格单位：分)
- (int)getPrice;

// 获取广告时效(单位：毫秒)
- (NSInteger)getValidTime;

//自渲染时， 用于获取ImageView
- (UIImageView*)getImageViewByUrl:(NSString*)url placeImage:(UIImage*)placeImage;

/**
 销毁广告视图
 */
- (void)destroyAdView;

// 广告加载成功后获得的 原生广告数据模型（使用model数据，自定义View样式）
@property (nonatomic, strong, readonly) NSArray<WanjaNativeAdDataModel *> *adDataModels;

// 广告加载成功后获得的 View广告（数组内部为加载完成的View形式广告，直接add到目标View）
@property (nonatomic, strong, readonly) NSArray *nativeAdViews;

//是否是自渲染。 默认为NO； 如果设置为YES， 那么就需要开发者自己渲染视图了， nativeAdViews将无效
@property (nonatomic, readonly) BOOL isSelfRender;

//是否是摇一摇广告
@property (nonatomic, readonly) BOOL isShakeAd;

@end

@protocol WanjaAdNativeDelegate <NSObject>

// 加载成功
- (void)wanjaad_nativeSuccessToLoad:(WanjaAdNative *)nativeAd;

// 加载失败
- (void)wanjaad_nativeAd:(WanjaAdNative *)nativeAd didFailWithError:(NSError * _Nullable)error;

// 广告曝光
- (void)wanjaad_nativeDidVisible:(WanjaAdNative *)nativeAd;

// 广告点击
- (void)wanjaad_nativeAdViewDidClick:(WanjaAdNative *)nativeAd;

// 广告关闭
- (void)wanjaad_nativeAdViewDidClose:(WanjaAdNative *)nativeAd;

// 广告落地页关闭
- (void)wanjaad_nativeAdViewWillCloseOtherView:(WanjaAdNative *)nativeAd;

@end

NS_ASSUME_NONNULL_END
