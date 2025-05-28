//
//  WanjaGTMBase64.h
//  TestView
//
//  Created by guantou on 2019/12/20.
//  Copyright © 2019 北京市吕俊学. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WanjaGTMDefines.h"

NS_ASSUME_NONNULL_BEGIN

@interface WanjaGTMBase64 : NSObject

+ (NSData *)encodeData:(NSData *)data;

+ (NSData *)decodeData:(NSData *)data;

+ (NSData *)encodeBytes:(const void *)bytes length:(NSUInteger)length;

+ (NSData *)decodeBytes:(const void *)bytes length:(NSUInteger)length;

+ (NSString *)stringByEncodingData:(NSData *)data;

+ (NSString *)stringByEncodingBytes:(const void *)bytes length:(NSUInteger)length;

+ (NSData *)decodeString:(NSString *)string;

+ (NSData *)webSafeEncodeData:(NSData *)data padded:(BOOL)padded;

+ (NSData *)webSafeDecodeData:(NSData *)data;

+ (NSData *)webSafeEncodeBytes:(const void *)bytes length:(NSUInteger)length padded:(BOOL)padded;

+ (NSData *)webSafeDecodeBytes:(const void *)bytes length:(NSUInteger)length;

+ (NSString *)stringByWebSafeEncodingData:(NSData *)data padded:(BOOL)padded;

+ (NSString *)stringByWebSafeEncodingBytes:(const void *)bytes length:(NSUInteger)length padded:(BOOL)padded;

+ (NSData *)webSafeDecodeString:(NSString *)string;

@end

NS_ASSUME_NONNULL_END
