//
//  ZJ_CJNativeAd.h
//  ZJ_CJAdSDK
//
//  Created by coderqi on 2025/11/14.
//

#import <Foundation/Foundation.h>
#import <ZJ_CJAdSDK/ZJ_CJNativeAdObject.h>
#import <ZJ_CJAdSDK/ZJ_CJNativeAdSlot.h>
#import <ZJ_CJAdSDK/ZJ_CJBaseAd.h>

NS_ASSUME_NONNULL_BEGIN

@class ZJ_CJNativeAdSlot;
@class ZJ_CJNativeAd;

@protocol ZJ_CJNativeAdDelegate <NSObject>

- (void)zjcj_nativeAdLoadSuccess:(ZJ_CJNativeAd *)nativeAd;

- (void)zjcj_nativeAdLoadFail:(ZJ_CJNativeAd *)nativeAd withError:(NSError *)error;



@end

@interface ZJ_CJNativeAd : ZJ_CJBaseAd
/// 广告请求参数
@property (nonatomic, strong, readonly) ZJ_CJNativeAdSlot *adSlot;

@property (nonatomic, weak) id <ZJ_CJNativeAdDelegate> delegate;

/// 广告对象，在zjcj_nativeAdLoadSuccess回调后有值
@property (nonatomic, strong, readonly, nullable) NSArray <ZJ_CJNativeAdObject *> *nativeAdObjects;

/**
 * @brief 初始化view
 */
- (instancetype)initWithSlot:(ZJ_CJNativeAdSlot *)slot;

/**
 *  加载广告
 */
- (void)loadAd;

/**
 *  注册自渲染view
 *  @param containerView     广告渲染容器
 *  @param clickableViews   广告可点击的views，不传：默认整个广告可响应点击
 *  @return 返回错误，检查adItem、containerView、clickableViews是否存在问题
 */
- (NSError *)registerWithAdObject:(ZJ_CJNativeAdObject *)adObject
                       containerView:(UIView *)containerView
                      clickableViews:(NSArray<UIView *> *_Nullable)clickableViews
                        closeView:(NSArray<UIView *> *_Nullable)closeableViews;

/**
 *  销毁广告
 */
- (void)destory;

@end

NS_ASSUME_NONNULL_END
