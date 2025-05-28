//
//  NSString+WanjaAddition.h
//  WanjaOPUS
//
//  Created by zwf on 2020/12/8.
//

#import <UIKit/UIKit.h>


NS_ASSUME_NONNULL_BEGIN

@interface NSString (WanjaAddition)

/// 字符串的MD5值 以十六进制标识
/// @param string 字符串
+ (NSString *)wanja_md5HexFromString:(NSString *)string;

+ (NSString *)wanja_hexStringFromString:(NSString *)string;

+ (NSString *)wanja_currentTimeIntervalString;

- (CGFloat)wanja_floatFromString;

- (UIColor *)wanja_colorWithHex:(NSString *)hexColor alpha:(float)alpha;

- (CGSize)caleSizeByWidth:(CGFloat)width fontSize:(CGFloat)fontSize;

@end

NS_ASSUME_NONNULL_END
