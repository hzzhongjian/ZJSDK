//
//  UIView+WanjaAddition.h
//  WanjaOPUS
//
//  Created by zwf on 2020/12/8.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIView (WanjaAddition)

@property (nonatomic, assign) CGPoint wanja_origin;
@property (nonatomic, assign) CGSize wanja_size;

@property (nonatomic, assign) CGFloat wanja_height;
@property (nonatomic, assign) CGFloat wanja_width;

@property (nonatomic, assign) CGFloat wanja_top;
@property (nonatomic, assign) CGFloat wanja_left;
@property (nonatomic, assign) CGFloat wanja_bottom;
@property (nonatomic, assign) CGFloat wanja_right;

@property (nonatomic, readonly) CGPoint wanja_bottomLeft;
@property (nonatomic, readonly) CGPoint wanja_bottomRight;
@property (nonatomic, readonly) CGPoint wanja_topRight;

- (void)wanja_setupCornerRadius:(CGFloat)cornerRadius;
- (void)wanja_setupCornerRadius:(CGFloat)cornerRadius withBorderWidth:(CGFloat)width borderColor:(UIColor *)color;
- (void)wanja_setupCornerRadius:(CGFloat)cornerRadius withType:(UIRectCorner)cornerType;

- (void)wanja_fitWidth;
- (void)wanja_fitHeight;

+ (UIWindow *)wanja_lastWindow;

- (void)addTopShadowLineWithColor:(UIColor *)theColor;

@end

NS_ASSUME_NONNULL_END
