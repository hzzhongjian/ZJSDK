#import <Foundation/Foundation.h>

@interface NSData (WindDDData)

- (NSData *)wind_md5Digest;

- (NSData *)wind_sha1Digest;

- (NSString *)wind_hexStringValue;

- (NSString *)wind_base64Encoded;
- (NSData *)wind_base64Decoded;

@end
