//
//  NSObject+WanjaAddition.h
//  WanjaOPUS
//
//  Created by zwf on 2020/12/8.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSObject (WanjaAddition)

/**
 判断
 对象是否 非 nil, NSNull
 数组是否非空
 字典是否非空
 字符串是否非空
 */
- (BOOL)wanja_isNoEmpty;

- (BOOL)wanja_isEmpty;

/**
 判断是否含有特殊字符 （是指 除数字 字母 文字以外的所有字符）
 **/
- (BOOL)wanja_judgeTheillegalCharacter:(NSString *)content;

- (NSDictionary *)wanja_dictionaryWithJsonString:(NSString *)jsonString;

- (NSString *)wanja_stringWithJsonObj:(NSDictionary *)dict;

@end

NS_ASSUME_NONNULL_END
