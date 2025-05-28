//
//  NSData+WanjaAES.h
//  WanjaCoreSDK
//
//  Created by guantou on 2019/12/30.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSData (WanjaAES)

//加密
- (NSData *)WanjaAES128EncryptWithKey:(NSString *)key iv:(NSString *)iv;


//解密
- (NSData *)WanjaAES128DecryptWithKey:(NSString *)key iv:(NSString *)iv;

@end

NS_ASSUME_NONNULL_END
