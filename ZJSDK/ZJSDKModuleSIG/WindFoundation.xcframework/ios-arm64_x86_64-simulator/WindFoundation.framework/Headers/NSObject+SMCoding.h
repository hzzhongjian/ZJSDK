//
//  NSObject+SMCoding.h
//  SMExtension
//
//  Created by mj on 14-1-15.
//  Copyright (c) 2014年 小码哥. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WindFoundation/SMExtensionConst.h>

/**
 *  Codeing协议
 */
@protocol SMCoding <NSObject>
@optional
/**
 *  这个数组中的属性名才会进行归档
 */
+ (NSArray *)sm_allowedCodingPropertyNames;
/**
 *  这个数组中的属性名将会被忽略：不进行归档
 */
+ (NSArray *)sm_ignoredCodingPropertyNames;
@end

@interface NSObject (SMCoding) <SMCoding>
/**
 *  解码（从文件中解析对象）
 */
- (void)sm_decode:(NSCoder *)decoder;
/**
 *  编码（将对象写入文件中）
 */
- (void)sm_encode:(NSCoder *)encoder;
@end

/**
 归档的实现
 */
#define SMCodingImplementation \
- (id)initWithCoder:(NSCoder *)decoder \
{ \
if (self = [super init]) { \
[self sm_decode:decoder]; \
} \
return self; \
} \
\
- (void)encodeWithCoder:(NSCoder *)encoder \
{ \
[self sm_encode:encoder]; \
}

#define SMExtensionCodingImplementation SMCodingImplementation
