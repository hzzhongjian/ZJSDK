//
//  NSObject+WanjaModel.h
//  TestView
//
//  Created by guantou on 2020/1/6.
//  Copyright © 2020 北京市吕俊学. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSObject (WanjaModel)

+ (nullable instancetype)wanja_modelWithJSON:(id)json;

+ (nullable instancetype)wanja_modelWithDictionary:(NSDictionary *)dictionary;

- (BOOL)wanja_modelSetWithJSON:(id)json;

- (BOOL)wanja_modelSetWithDictionary:(NSDictionary *)dic;

- (nullable id)wanja_modelToJSONObject;

- (nullable NSData *)wanja_modelToJSONData;

- (nullable NSString *)wanja_modelToJSONString;

- (nullable id)wanja_modelCopy;

- (void)wanja_modelEncodeWithCoder:(NSCoder *)aCoder;

- (id)wanja_modelInitWithCoder:(NSCoder *)aDecoder;

- (NSUInteger)wanja_modelHash;

- (BOOL)wanja_modelIsEqual:(id)model;

- (NSString *)wanja_modelDescription;

@end

@interface NSArray (WanjaModel)

+ (nullable NSArray *)wanja_modelArrayWithClass:(Class)cls json:(id)json;

@end

@interface NSDictionary (WanjaModel)

+ (nullable NSDictionary *)wanja_modelDictionaryWithClass:(Class)cls json:(id)json;

@end

@protocol WanjaModel <NSObject>
@optional

+ (nullable NSDictionary<NSString *, id> *)wanja_modelCustomPropertyMapper;

+ (nullable NSDictionary<NSString *, id> *)wanja_modelContainerPropertyGenericClass;

+ (nullable Class)wanja_modelCustomClassForDictionary:(NSDictionary *)dictionary;

+ (nullable NSArray<NSString *> *)wanja_modelPropertyBlacklist;

+ (nullable NSArray<NSString *> *)wanja_modelPropertyWhitelist;

- (NSDictionary *)wanja_modelCustomWillTransformFromDictionary:(NSDictionary *)dic;

- (BOOL)wanja_modelCustomTransformFromDictionary:(NSDictionary *)dic;

- (BOOL)wanja_modelCustomTransformToDictionary:(NSMutableDictionary *)dic;

@end

NS_ASSUME_NONNULL_END

