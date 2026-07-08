//
//  NSData+WindPadding.h
//  WindSDK
//
//  Created by Codi on 2021/8/2.
//  Copyright © 2021 Codi. All rights reserved.
//


#import <Foundation/Foundation.h>
#import <WindFoundation/WindCryptDefines.h>

/**
 补位和除补位
 */
@interface NSData (WindPadding)

/**
 padding function,根据填充模式，补位数据
 @param padding padding type
 @param blockSize block size
 @return padded data
 */
- (NSData*)WindPaddingWithMode:(WindPaddingMode)padding blockSize:(uint8_t)blockSize;

/**
 unpadding function,根据填充模式，除去填充的数据
 @param padding padding type
 @return padded data
 */
- (NSData*)WindUnPaddingWithMode:(WindPaddingMode)padding;

@end
