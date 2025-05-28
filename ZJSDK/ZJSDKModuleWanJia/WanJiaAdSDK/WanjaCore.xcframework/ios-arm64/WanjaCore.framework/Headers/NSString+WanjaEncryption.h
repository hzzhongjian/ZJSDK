//
//  NSString+WanjaEncryption.h
//  WanjaCoreSDK
//
//  Created by guantou on 2018/11/27.
//

#import <Foundation/Foundation.h>

@interface NSString (WanjaEncryption)

- (NSString *)Wanja_MD5String;
//  加密
- (NSString *)Wanja_base64EncodeString;
//  解密
- (NSString *)Wanja_base64DecodeString;

@end
