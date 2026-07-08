//
//  NSObject+SMCoder.h
//  SMCoder
//
//  Created by happyelements on 2019/5/30.
//  Copyright © 2019 Codi. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSObject (SMCoder)

- (void)sm_modelEncodeWithCoder:(NSCoder *)aCoder;

- (id)sm_modelInitWithCoder:(NSCoder *)aDecoder;

- (id)sm_modelCopy;

@end

@protocol SMCoder <NSObject>
@optional

+ (nullable NSDictionary<NSString *, id> *)modelCustomPropertyMapper;

+ (nullable NSDictionary<NSString *, id> *)modelContainerPropertyGenericClass;

+ (nullable Class)modelCustomClassForDictionary:(NSDictionary *)dictionary;

+ (nullable NSArray<NSString *> *)modelPropertyBlacklist;

+ (nullable NSArray<NSString *> *)modelPropertyWhitelist;

- (NSDictionary *)modelCustomWillTransformFromDictionary:(NSDictionary *)dic;

- (BOOL)modelCustomTransformFromDictionary:(NSDictionary *)dic;

- (BOOL)modelCustomTransformToDictionary:(NSMutableDictionary *)dic;

@end

NS_ASSUME_NONNULL_END
