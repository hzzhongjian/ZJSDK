//
//  UIView+WanjaFrame.h
//  WanjaCore
//
//  Created by ZY on 2019/6/6.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIView (WanjaFrame)

@property (nonatomic ,assign) CGFloat wanja_x;
@property (nonatomic ,assign) CGFloat wanja_y;
@property (nonatomic ,assign) CGFloat wanja_width;
@property (nonatomic ,assign) CGFloat wanja_height;
@property (nonatomic ,assign) CGFloat wanja_centerX;
@property (nonatomic ,assign) CGFloat wanja_centerY;
@property (nonatomic ,assign) CGSize wanja_size;
@property (nonatomic, assign) CGFloat wanja_right;
@property (nonatomic, assign) CGFloat wanja_bottom;

@end

NS_ASSUME_NONNULL_END
