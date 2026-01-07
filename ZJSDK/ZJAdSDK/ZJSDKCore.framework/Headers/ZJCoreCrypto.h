//
//  ZJCoreCrypto.h
//  ZJSDKCore
//
//  Created by Rare on 2021/3/1.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZJCoreCrypto : NSObject

// SHA256加密
+ (NSString *)sha256Encrypt:(NSString *)originText;


+ (NSString *)sortedDictionary:(NSDictionary *)dict;


/**AES 256 加密方法 */
+ (NSString *)AES256EncryptWith:(NSString *)dataIn key:(NSString *)key iv:(NSString *)iv;

/**AES 256 解密方法 */
+ (NSString *)AES256DecryptWith:(NSString *)dataIn key:(NSString *)key iv:(NSString *)iv;


+ (NSString *)AES256DecryptWithData:(NSData *)data key:(NSString *)key;

@end

NS_ASSUME_NONNULL_END
