//
//  NSObject+SMClass.h
//  SMExtensionExample
//
//  Created by SM Lee on 15/8/11.
//  Copyright (c) 2015年 小码哥. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  遍历所有类的block（父类）
 */
typedef void (^SMClassesEnumeration)(Class c, BOOL *stop);

/** 这个数组中的属性名才会进行字典和模型的转换 */
typedef NSArray * (^SMAllowedPropertyNames)(void);
/** 这个数组中的属性名才会进行归档 */
typedef NSArray * (^SMAllowedCodingPropertyNames)(void);

/** 这个数组中的属性名将会被忽略：不进行字典和模型的转换 */
typedef NSArray * (^SMIgnoredPropertyNames)(void);
/** 这个数组中的属性名将会被忽略：不进行归档 */
typedef NSArray * (^SMIgnoredCodingPropertyNames)(void);

/**
 * 类相关的扩展
 */
@interface NSObject (SMClass)
/**
 *  遍历所有的类
 */
+ (void)sm_enumerateClasses:(SMClassesEnumeration)enumeration;
+ (void)sm_enumerateAllClasses:(SMClassesEnumeration)enumeration;

#pragma mark - 属性白名单配置
/**
 *  这个数组中的属性名才会进行字典和模型的转换
 *
 *  @param allowedPropertyNames          这个数组中的属性名才会进行字典和模型的转换
 */
+ (void)sm_setupAllowedPropertyNames:(SMAllowedPropertyNames)allowedPropertyNames;

/**
 *  这个数组中的属性名才会进行字典和模型的转换
 */
+ (NSMutableArray *)sm_totalAllowedPropertyNames;

#pragma mark - 属性黑名单配置
/**
 *  这个数组中的属性名将会被忽略：不进行字典和模型的转换
 *
 *  @param ignoredPropertyNames          这个数组中的属性名将会被忽略：不进行字典和模型的转换
 */
+ (void)sm_setupIgnoredPropertyNames:(SMIgnoredPropertyNames)ignoredPropertyNames;

/**
 *  这个数组中的属性名将会被忽略：不进行字典和模型的转换
 */
+ (NSMutableArray *)sm_totalIgnoredPropertyNames;

#pragma mark - 归档属性白名单配置
/**
 *  这个数组中的属性名才会进行归档
 *
 *  @param allowedCodingPropertyNames          这个数组中的属性名才会进行归档
 */
+ (void)sm_setupAllowedCodingPropertyNames:(SMAllowedCodingPropertyNames)allowedCodingPropertyNames;

/**
 *  这个数组中的属性名才会进行字典和模型的转换
 */
+ (NSMutableArray *)sm_totalAllowedCodingPropertyNames;

#pragma mark - 归档属性黑名单配置
/**
 *  这个数组中的属性名将会被忽略：不进行归档
 *
 *  @param ignoredCodingPropertyNames          这个数组中的属性名将会被忽略：不进行归档
 */
+ (void)sm_setupIgnoredCodingPropertyNames:(SMIgnoredCodingPropertyNames)ignoredCodingPropertyNames;

/**
 *  这个数组中的属性名将会被忽略：不进行归档
 */
+ (NSMutableArray *)sm_totalIgnoredCodingPropertyNames;

#pragma mark - 内部使用
+ (void)sm_setupBlockReturnValue:(id (^)(void))block key:(const char *)key;
@end
