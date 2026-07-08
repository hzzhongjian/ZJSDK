//
//  NSObject+SMKeyValue.h
//  SMExtension
//
//  Created by mj on 13-8-24.
//  Copyright (c) 2013年 小码哥. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WindFoundation/SMExtensionConst.h>
#import <WindFoundation/SMProperty.h>

/**
 *  KeyValue协议
 */
@protocol SMKeyValue <NSObject>
@optional
/**
 *  只有这个数组中的属性名才允许进行字典和模型的转换
 */
+ (NSArray *)sm_allowedPropertyNames;

/**
 *  这个数组中的属性名将会被忽略：不进行字典和模型的转换
 */
+ (NSArray *)sm_ignoredPropertyNames;

/**
 *  将属性名换为其他key去字典中取值
 *
 *  @return 字典中的key是属性名，value是从字典中取值用的key
 */
+ (NSDictionary *)sm_replacedKeyFromPropertyName;

/**
 *  将属性名换为其他key去字典中取值
 *
 *  @return 从字典中取值用的key
 */
+ (id)sm_replacedKeyFromPropertyName121:(NSString *)propertyName;

/**
 *  数组中需要转换的模型类
 *
 *  @return 字典中的key是数组属性名，value是数组中存放模型的Class（Class类型或者NSString类型）
 */
+ (NSDictionary *)sm_objectClassInArray;


/** 特殊地区在字符串格式化数字时使用 */
+ (NSLocale *)sm_numberLocale;

/**
 *  旧值换新值，用于过滤字典中的值
 *
 *  @param oldValue 旧值
 *
 *  @return 新值
 */
- (id)sm_newValueFromOldValue:(id)oldValue property:(SMProperty *)property;

/**
 *  当字典转模型完毕时调用
 */
- (void)sm_keyValuesDidFinishConvertingToObject SMExtensionDeprecated("请使用`sm_didConvertToObjectWithKeyValues:`替代");
- (void)sm_keyValuesDidFinishConvertingToObject:(NSDictionary *)keyValues SMExtensionDeprecated("请使用`sm_didConvertToObjectWithKeyValues:`替代");
- (void)sm_didConvertToObjectWithKeyValues:(NSDictionary *)keyValues;

/**
 *  当模型转字典完毕时调用
 */
- (void)sm_objectDidFinishConvertingToKeyValues SMExtensionDeprecated("请使用`sm_objectDidConvertToKeyValues:`替代");
- (void)sm_objectDidConvertToKeyValues:(NSMutableDictionary *)keyValues;

@end

@interface NSObject (SMKeyValue) <SMKeyValue>
#pragma mark - 类方法
/**
 * 字典转模型过程中遇到的错误
 */
+ (NSError *)sm_error;

/**
 *  模型转字典时，字典的key是否参考replacedKeyFromPropertyName等方法（父类设置了，子类也会继承下来）
 */
+ (void)sm_referenceReplacedKeyWhenCreatingKeyValues:(BOOL)reference;

#pragma mark - 对象方法
/**
 *  将字典的键值对转成模型属性
 *  @param keyValues 字典(可以是NSDictionary、NSData、NSString)
 */
- (instancetype)sm_setKeyValues:(id)keyValues;


/**
 *  将模型转成字典
 *  @return 字典
 */
- (NSMutableDictionary *)sm_keyValues;
- (NSMutableDictionary *)sm_keyValuesWithKeys:(NSArray *)keys;
- (NSMutableDictionary *)sm_keyValuesWithIgnoredKeys:(NSArray *)ignoredKeys;

/**
 *  通过模型数组来创建一个字典数组
 *  @param objectArray 模型数组
 *  @return 字典数组
 */
+ (NSMutableArray *)sm_keyValuesArrayWithObjectArray:(NSArray *)objectArray;
+ (NSMutableArray *)sm_keyValuesArrayWithObjectArray:(NSArray *)objectArray keys:(NSArray *)keys;
+ (NSMutableArray *)sm_keyValuesArrayWithObjectArray:(NSArray *)objectArray ignoredKeys:(NSArray *)ignoredKeys;

#pragma mark - 字典转模型
/**
 *  通过字典来创建一个模型
 *  @param keyValues 字典(可以是NSDictionary、NSData、NSString)
 *  @return 新建的对象
 */
+ (instancetype)sm_objectWithKeyValues:(id)keyValues;


/**
 *  通过plist来创建一个模型
 *  @param filename 文件名(仅限于mainBundle中的文件)
 *  @return 新建的对象
 */
+ (instancetype)sm_objectWithFilename:(NSString *)filename;

/**
 *  通过plist来创建一个模型
 *  @param file 文件全路径
 *  @return 新建的对象
 */
+ (instancetype)sm_objectWithFile:(NSString *)file;

#pragma mark - 字典数组转模型数组
/**
 *  通过字典数组来创建一个模型数组
 *  @param keyValuesArray 字典数组(可以是NSDictionary、NSData、NSString)
 *  @return 模型数组
 */
+ (NSMutableArray *)sm_objectArrayWithKeyValuesArray:(id)keyValuesArray;


/**
 *  通过plist来创建一个模型数组
 *  @param filename 文件名(仅限于mainBundle中的文件)
 *  @return 模型数组
 */
+ (NSMutableArray *)sm_objectArrayWithFilename:(NSString *)filename;

/**
 *  通过plist来创建一个模型数组
 *  @param file 文件全路径
 *  @return 模型数组
 */
+ (NSMutableArray *)sm_objectArrayWithFile:(NSString *)file;

#pragma mark - 转换为JSON
/**
 *  转换为JSON Data
 */
- (NSData *)sigmob_JSONData;
/**
 *  转换为字典或者数组
 */
- (id)sigmob_JSONObject;
/**
 *  转换为JSON 字符串
 */
- (NSString *)sigmob_JSONString;
@end
