//
//  ZJFLNativeManager.h
//  ZJ_FLAdSDK
//
//  Created by Lurich on 2023/5/26.
//

#import <ZJ_FLAdSDK/ZJ_FLAdSDK.h>
#import <ZJ_FLAdSDK/ZJFLNativeAdRenderProtocol.h>

NS_ASSUME_NONNULL_BEGIN
@protocol ZJFLNativeDelegate <NSObject>

@optional
//回调已全部转为主线程
/**
 * 广告数据：加载成功
 */
- (void)nativeAdDidLoadDatas:(NSArray<__kindof ZJFLFeedAdData *> *)datas;
/**
 * 广告数据：加载失败
 * @param error : 错误信息
 */
- (void)nativeAdDidFailed:(NSError *)error;
/**
 * 广告视图：展示
 */
- (void)nativeAdDidVisible;
/**
 * 广告视图：点击
 */
- (void)nativeAdDidClicked;
/**
 * 落地页或者appstoe返回事件
 */
- (void)nativeAdDidCloseOtherController;

/// !!!: 当为模板广告时有以下回调
/**
 * 广告视图：渲染成功
 */
- (void)nativeAdDidRenderSuccessWithADView:(UIView *)nativeAdView;
/**
 * 广告视图：渲染失败
 */
- (void)nativeAdDidRenderFailedWithError:(NSError *)error;
/**
 * 广告视图：关闭
 */
- (void)nativeAdDidCloseWithADView:(UIView *)nativeAdView;

@end

/// !!!: ZJFLNativeManager 为 ZJFLFeedManager 和 ZJFLTemplateManager 和 ZJFLDrawVideoManager 的聚合使用
///
/// 原生混合接入类
@interface ZJFLNativeManager : ZJFLBaseAdManager

/**
 * 广告回调的代理
 */
@property(nonatomic, weak) id<ZJFLNativeDelegate> delegate;

/**
 * 开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
 */
@property (nonatomic, weak) UIViewController *showAdController;

/**
 * 最多返回的广告数量 ,默认为1
 */
@property (nonatomic) NSInteger adCount DEPRECATED_MSG_ATTRIBUTE("已弃用 只支持返回1个广告");

/**
 * 请求广告时间间隔，无需间隔请传0
 */
@property (nonatomic, assign) NSInteger intervalTime;

/// !!!:  必须在确保视图成功显示在屏幕上之后再调用注册点击，确保广告进行有效曝光
/**
 绑定展示的图片视图和点击视图，行为由SDK控制
 @param view 展示的图片视图
 @param adData 广告数据
 @param views 可点击的视图
 */
- (void)registerAdViewForBindImage:(UIImageView *)view adData:(ZJFLFeedAdData *)adData clickableViews:(NSArray *)views DEPRECATED_MSG_ATTRIBUTE("已弃用，使用 registerAdForView:adData: 替代");

// 海外广告必须使用此方法注册
- (void)registerAdForView:(UIView<ZJFLNativeAdRenderProtocol> *)view adData:(ZJFLFeedAdData *)adData;

/**
 注销数据对象，在 tableView、collectionView 等场景需要复用 GDTUnifiedNativeAdView 时，
 需要在合适的时机，例如 cell 的 prepareForReuse 方法内执行 unregisterDataObject 方法，
 将广告对象与 NativeAdView 解绑
 */
- (void)unregisterAdData:(ZJFLFeedAdData *)adData;

- (void)deallocAllFeedProperty;

// **************************** 当为模板广告时，以下属性可用 **************************** 
/**
 * 广告view大小尺寸,高度为0时，将自适应高度（推荐高度传0进行自适应高度）
 */
@property (nonatomic) CGSize size;
/**
 * 针对部分联盟广告主有效
 */
@property (nonatomic, assign) ZJFLTemplateExpressNativeTheme theme;

@end

NS_ASSUME_NONNULL_END
