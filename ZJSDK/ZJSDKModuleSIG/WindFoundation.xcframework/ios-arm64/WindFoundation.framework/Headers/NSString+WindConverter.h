//
//  NSString+WindConverter.h
//  CryptDevTool
//
//  Created by Codi on 2021/9/6.
//

#import <Foundation/Foundation.h>

@interface NSString (WindConverter)

/**
 转换成NSData，转换前String可以为任意编码格式
 如果String非UTF-8,不能成功转换成UTF-8则返回nil
 @return NSData
 */
- (NSData *)wind_utf8Data;

/// gzip
- (NSData *)wind_gzip;

/// base64 encode
- (NSString *)wind_base64;

/// base64 decode
- (NSString *)wind_dencodeBase64;

- (NSData *)wind_decodeBase64ToData;

/// base64 and url safe
- (NSString *)wind_base64_url_safe;

/// base64 decode and url safe
- (NSString *)wind_decode_base64_url_safe;

/// url encode
- (NSString *)wind_urlEncode;

/// url decode
- (NSString *)wind_decodeURL;

/// md5
- (NSString *)wind_md5;

/// sha-256
- (NSString *)wind_sha256;

/**
 nil, @"", @"  ", @"\n" will Returns NO; otherwise Returns YES.
 */
- (BOOL)wind_isNotBlank;

/**
 Returns YES if the target string is contained within the receiver.
 @param string A string to test the the receiver.
 
 @discussion Apple has implemented this method in iOS8.
 */
- (BOOL)wind_containsString:(NSString *)string;

/**
 Returns a new UUID NSString
 e.g. "D1178E50-2A4D-4F1F-9BD3-F6AAB00E06B1"
 */
+ (NSString *)wind_stringWithUUID;

#pragma mark - 公钥私钥数据
/**
 * 加密方法
 *
 * @param str 需要加密的字符串
 * @param pubKey 公钥字符串
 */
- (NSString *)encryptPlainText:(NSString *)str publicKey:(NSString *)pubKey;


@end
