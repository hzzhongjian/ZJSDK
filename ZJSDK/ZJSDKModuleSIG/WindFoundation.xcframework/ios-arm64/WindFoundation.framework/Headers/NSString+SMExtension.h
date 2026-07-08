//
//  NSString+SMExtension.h
//  SMExtensionExample
//
//  Created by SM Lee on 15/6/7.
//  Copyright (c) 2015年 小码哥. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WindFoundation/SMExtensionConst.h>

@interface NSString (SMExtension)
/**
 *  驼峰转下划线（loveYou -> love_you）
 */
- (NSString *)sm_underlineFromCamel;
/**
 *  下划线转驼峰（love_you -> loveYou）
 */
- (NSString *)sm_camelFromUnderline;
/**
 * 首字母变大写
 */
- (NSString *)sm_firstCharUpper;
/**
 * 首字母变小写
 */
- (NSString *)sm_firstCharLower;

- (BOOL)sm_isPureInt;

- (NSURL *)sm_url;
@end
