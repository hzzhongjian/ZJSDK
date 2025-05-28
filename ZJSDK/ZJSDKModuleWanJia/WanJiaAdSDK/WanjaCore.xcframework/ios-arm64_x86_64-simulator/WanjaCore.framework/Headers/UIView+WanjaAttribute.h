//
//  UIView+WanjaAttribute.h
//  WanjaCore
//
//  Created by ZY on 2019/1/16.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIView (WanjaAttribute)

/**
 视图透明度
 */
- (CGFloat)wanja_getSuperViewsAlpha:(UIView *)view;

/**
 视图是否可见
 */
- (BOOL)wanja_getSuperViewsVisibility:(UIView *)view;

/**
 视图是否被遮挡
 */
- (BOOL)wanja_getSuperViewsShade:(UIView *)view;

/**
 视图是否被添加到页面
 */
- (BOOL)wanja_isDisplayedInScreen;

@end

NS_ASSUME_NONNULL_END
