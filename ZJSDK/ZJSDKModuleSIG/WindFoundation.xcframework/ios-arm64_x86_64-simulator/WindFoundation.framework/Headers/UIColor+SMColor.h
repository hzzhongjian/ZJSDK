//
//  UIColor+SMColor.h
//  WindSDK
//
//  Created by happyelements on 2018/8/31.
//  Copyright © 2018 Codi. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIColor (SMColor)

+ (UIColor *)sm_colorWithIntegerRed:(NSUInteger)red green:(NSUInteger)green blue:(NSUInteger)blue;

+ (UIColor *)sm_colorWithIntegerRed:(NSUInteger)red green:(NSUInteger)green blue:(NSUInteger)blue alpha:(CGFloat)alpha;

+ (UIColor *)sm_colorWithHexString:(NSString *)color alpha:(CGFloat)alpha;

+ (UIColor *)sm_colorWithHexRGB:(NSUInteger)hexRGB;

+ (UIColor *)sm_colorWithHexRGBA:(NSUInteger)hexRGBA;

+ (UIColor *)sm_colorWithHexARGB:(NSUInteger)hexARGB;

+ (UIColor *)sm_progressTintColor;

+ (UIColor *)sm_progressTrackTintColor;

@end
