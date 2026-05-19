//
//  ZJ_CJ_NativeAd.h
//  ZJ_CJAdSDK
//
//  Created by coderqi on 2025/11/14.
//

#import <Foundation/Foundation.h>
#import <ZJ_CJAdSDK/ZJ_CJ_NativeAdObject.h>
#import <ZJ_CJAdSDK/ZJ_CJ_NativeAdSlot.h>
#import <ZJ_CJAdSDK/ZJ_CJ_BaseAd.h>

NS_ASSUME_NONNULL_BEGIN

@class ZJ_CJ_NativeAdSlot;
@class ZJ_CJ_NativeAd;

@protocol ZJ_CJ_NativeAdDelegate <NSObject>

- (void)zjcj_nativeAdLoadSuccess:(ZJ_CJ_NativeAd *)nativeAd;

- (void)zjcj_nativeAdLoadFail:(ZJ_CJ_NativeAd *)nativeAd withError:(NSError *)error;



@end

@interface ZJ_CJ_NativeAd : ZJ_CJ_BaseAd
/// 广告请求参数
@property (nonatomic, strong, readonly) ZJ_CJ_NativeAdSlot *adSlot;

@property (nonatomic, weak) id <ZJ_CJ_NativeAdDelegate> delegate;

/// 广告对象，在zjcj_nativeAdLoadSuccess回调后有值
@property (nonatomic, strong, readonly, nullable) NSArray <ZJ_CJ_NativeAdObject *> *nativeAdObjects;

/**
 * @brief 初始化view
 */
- (instancetype)initWithSlot:(ZJ_CJ_NativeAdSlot *)slot;

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
- (NSError *)registerWithAdObject:(ZJ_CJ_NativeAdObject *)adObject
                       containerView:(UIView *)containerView
                      clickableViews:(NSArray<UIView *> *_Nullable)clickableViews
                        closeView:(NSArray<UIView *> *_Nullable)closeableViews;

/**
 *  销毁广告
 */
- (void)destory;

@end

NS_ASSUME_NONNULL_END
