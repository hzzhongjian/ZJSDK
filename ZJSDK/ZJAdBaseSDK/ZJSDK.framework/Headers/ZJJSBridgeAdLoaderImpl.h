//
//  ZJJSBridgeAdLoaderImpl.h
//  ZJSDK
//
//  Created by 麻明康 on 2025/8/22.
//  Copyright © 2025 zj. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZJJSBridgeAdLoaderDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface ZJJSBridgeAdLoaderImpl : NSObject <ZJJSBridgeAdLoaderDelegate>

+ (instancetype)sharedInstance;

@end

NS_ASSUME_NONNULL_END
