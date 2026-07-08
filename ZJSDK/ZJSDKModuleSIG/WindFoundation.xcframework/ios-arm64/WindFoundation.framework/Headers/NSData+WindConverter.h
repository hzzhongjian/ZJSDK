//
//  NSData+WindConverter.h
//  CryptDevTool
//
//  Created by Codi on 2021/9/6.
//

#import <Foundation/Foundation.h>

@interface NSData (WindConverter)

- (NSData *)wind_gzip;

- (NSData *)wind_gunzip;

/// NSData计算base64
- (NSString *)wind_base64;

/*
 对NSData做异或
 @return 计算结果
 */
//- (NSData *)wind_xor:(Byte)xorByte;

#pragma - AES-ECB-PKCS5
//
/// Default key
- (NSData *)wind_AESEncrypt;
/// custom key
- (NSData *)wind_AESEncryptedDataUsingKey:(id)key;
/// Default key
- (NSData *)wind_AESDecrypt;
/// custom key
- (NSData *)wind_AESDecryptedDataUsingKey:(id)key;






@end
