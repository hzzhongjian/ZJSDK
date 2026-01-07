//
//  ZJDecryptionUtils.h
//  ZJSDKCore
//
//  Created by 麻明康 on 2024/12/5.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZJDecryptionUtils : NSObject

+ (NSDictionary *)decryptionZJSDKMediaConfig:(NSString *)dataString;

@end

NS_ASSUME_NONNULL_END
