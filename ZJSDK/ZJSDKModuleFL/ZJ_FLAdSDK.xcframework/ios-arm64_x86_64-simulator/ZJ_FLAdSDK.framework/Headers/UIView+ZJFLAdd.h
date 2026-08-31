//
//  UIView+ZJFLAdd.h
//  TestAdA
//
//  Created by lurich on 2021/4/12.
//  Copyright © 2021 . All rights reserved.
//

#import <UIKit/UIKit.h>

typedef struct ZJFLLayoutAnchor {
    NSLayoutYAxisAnchor *top;
    NSLayoutXAxisAnchor *left;
    NSLayoutYAxisAnchor *bottom;
    NSLayoutXAxisAnchor *right;
} ZJFLLayoutAnchor;

@interface UIView (ZJFLAdd)

@property (assign, nonatomic) CGFloat zjfl_x;
@property (assign, nonatomic) CGFloat zjfl_y;
@property (assign, nonatomic, readonly) CGFloat zjfl_midX;
@property (assign, nonatomic, readonly) CGFloat zjfl_midY;
@property (assign, nonatomic, readonly) CGFloat zjfl_maxX;
@property (assign, nonatomic, readonly) CGFloat zjfl_maxY;
@property (assign, nonatomic) CGFloat zjfl_width;
@property (assign, nonatomic) CGFloat zjfl_height;
@property (assign, nonatomic) CGFloat zjfl_centerX;
@property (assign, nonatomic) CGFloat zjfl_centerY;
@property (assign, nonatomic) CGSize  zjfl_size;
@property (assign, nonatomic) CGPoint zjfl_origin;

- (void)zjfl_fillSuperView;
- (void)zjfl_anchorWithView:(UIView *)supview Padding:(UIEdgeInsets)padding;
- (void)zjfl_anchorWithTop:(NSLayoutYAxisAnchor *)top Left:(NSLayoutXAxisAnchor *)left Bottom:(NSLayoutYAxisAnchor *)bottom Right:(NSLayoutXAxisAnchor *)right;
- (void)zjfl_anchorWithTop:(NSLayoutYAxisAnchor *)top Left:(NSLayoutXAxisAnchor *)left Bottom:(NSLayoutYAxisAnchor *)bottom Right:(NSLayoutXAxisAnchor *)right Padding:(UIEdgeInsets)padding;
- (void)zjfl_anchorWithTop:(NSLayoutYAxisAnchor *)top Left:(NSLayoutXAxisAnchor *)left Bottom:(NSLayoutYAxisAnchor *)bottom Right:(NSLayoutXAxisAnchor *)right Padding:(UIEdgeInsets)padding Size:(CGSize)size;
- (void)zjfl_anchorWithTop:(NSLayoutYAxisAnchor *)top Left:(NSLayoutXAxisAnchor *)left Bottom:(NSLayoutYAxisAnchor *)bottom Right:(NSLayoutXAxisAnchor *)right Padding:(UIEdgeInsets)padding Ratio:(CGFloat)ratio;
- (void)zjfl_anchorWithSize:(CGSize)size;
- (void)zjfl_anchorWithLessThanSize:(CGSize)size;
- (void)zjfl_anchorWithGreaterThanSize:(CGSize)size;
- (void)zjfl_anchorAnimateChangeWithX:(NSLayoutXAxisAnchor *)centerX Y:(NSLayoutYAxisAnchor *)centerY;
- (void)zjfl_anchorGreaterThanWithTop:(NSLayoutYAxisAnchor *)top Left:(NSLayoutXAxisAnchor *)left Bottom:(NSLayoutYAxisAnchor *)bottom Right:(NSLayoutXAxisAnchor *)right Padding:(UIEdgeInsets)padding;
- (void)zjfl_anchorLessThanWithTop:(NSLayoutYAxisAnchor *)top Left:(NSLayoutXAxisAnchor *)left Bottom:(NSLayoutYAxisAnchor *)bottom Right:(NSLayoutXAxisAnchor *)right Padding:(UIEdgeInsets)padding;
- (void)zjfl_anchorWithMultiplier:(CGFloat)multiplier;
- (void)zjfl_anchorWithCenterX:(NSLayoutXAxisAnchor *)centerX CenterY:(NSLayoutYAxisAnchor *)centerY Constant:(CGFloat)constant;
/** 获取当前View的控制器对象 */
- (UIViewController *)zjfl_getCurrentViewController;
// 判断View是否显示在屏幕上
- (BOOL)zjfl_isDisplayedInScreen;
- (BOOL)isViewCompletelyCoveredBySampling;
- (UIScrollView *)zjfl_enclosingScrollView;
@end
