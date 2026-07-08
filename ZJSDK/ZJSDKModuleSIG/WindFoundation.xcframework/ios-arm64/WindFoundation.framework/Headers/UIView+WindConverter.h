//
//  UIView+WindConverter.h
//  WindSDK
//
//  Created by Codi on 2021/9/6.
//  Copyright © 2021 Codi. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <objc/runtime.h>


@interface UIView (WindConverter)

@property (nonatomic, assign) BOOL windRender;


/// 计算当前View在屏幕中的比例
- (int32_t)wind_showPercentDisplayInScreen;

- (void)wind_removeAllGestureRecognizers;

- (BOOL)wind_isVisible;

- (UIViewController *)wind_viewController;

/// 修改锚点
- (void)wind_anchorPoint:(CGPoint)anchorPoint;


@end
