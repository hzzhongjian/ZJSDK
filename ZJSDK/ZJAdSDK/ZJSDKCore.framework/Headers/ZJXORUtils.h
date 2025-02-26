//
//  ZJXORUtils.h
//  ZJSDKCore
//
//  Created by 麻明康 on 2025/2/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZJXORUtils : NSObject

// 异或加密/解密函数
+ (NSString *)xorEncryptDecrypt:(NSString *)inputString;

// 解密函数
+ (NSString *)xorDecrypt:(NSString *)encryptedBase64String;


@end

NS_ASSUME_NONNULL_END
