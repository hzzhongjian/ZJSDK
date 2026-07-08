//
//  ZJWNativeAdObject.h
//  ZJWAdSDK
//
//  Created by admin on 2024/1/18.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <ZJWAdSDK/ZJWNativeAdData.h>
#import <ZJWAdSDK/ZJWNativeAdRelatedView.h>


NS_ASSUME_NONNULL_BEGIN

@interface ZJWNativeAdObject : NSObject

/// 广告数据
@property (nonatomic, strong, readonly) ZJWNativeAdData *adData;
/// 视频relatedView
@property (nonatomic, strong, readonly)ZJWNativeAdRelatedView *relatedView;


/// 开屏自渲染注册容器和可点击视图
/// @param containerView 容器视图
/// @param clickableViews 可点击视图数组
- (void)setSplashContainer:(UIView *)containerView clickableViews:(NSArray<UIView *> *)clickableViews;

/// 其他广告位置注册容器和可点击视图
/// @param containerView 容器视图
/// @param clickableViews 可点击视图数组
- (void)setContainer:(UIView *)containerView clickableViews:(NSArray<UIView *> *)clickableViews;


@end

NS_ASSUME_NONNULL_END
