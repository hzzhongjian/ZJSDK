//
//  WanjaSecurityAndGziptTool.h
//  WanjaCoreSDK
//
//  Created by guantou on 2020/1/10.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*
 *  解压缩，加密、解密。
 */
@interface WanjaSecurityAndGziptTool : NSObject

//  Gzipt压缩
+ (NSData *)AdGzipData:(NSData*)uncompressedData;
//  Gzipt解压
+ (NSData *)AdUngzipData:(NSData *)compressedData;

/// wanja加密
/// @param encryptString 需要加密的字符串
+ (NSData *)WanjaEncryptWithString:(NSString *)encryptString aesKey:(NSString*)key aesIV:(NSString*)aesIV;

/// wanja解密
/// @param decryptString 需要解密的字符串
+ (NSData *)WanjaDecryptWithString:(NSString *)decryptString aesKey:(NSString*)key aesIV:(NSString*)aesIV;

+ (NSData *)WanjaAESEncryptWithString:(NSString *)encryptString aesKey:(NSString*)key aesIV:(NSString*)aesIV;
+ (NSData *)WanjaAESDecryptWithString:(NSString *)decryptString aesKey:(NSString*)key aesIV:(NSString*)aesIV;

//可选加解密
+ (NSData *)WanjaOptionEncryptWithString:(NSString *)encryptString aesKey:(NSString*)key aesIV:(NSString*)aesIV;
+ (NSData *)WanjaOptionDecryptWithString:(NSString *)decryptString aesKey:(NSString*)key aesIV:(NSString*)aesIV;

+ (NSData *)WanjaOptionAESEncryptWithString:(NSString *)encryptString aesKey:(NSString*)key aesIV:(NSString*)aesIV;
+ (NSData *)WanjaOptionAESDecryptWithString:(NSString *)decryptString aesKey:(NSString*)key aesIV:(NSString*)aesIV;


@end

NS_ASSUME_NONNULL_END
