//
//  ZJJSBridgeAdLoaderDelegate.h
//  ZJSDK
//
//  Created by 麻明康 on 2025/8/22.
//  Copyright © 2025 zj. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ZJJSAdParams;
@class ZJJSBridgeAdPlugin;

@protocol ZJJSBridgeAdLoaderDelegate <NSObject>

- (NSInteger)load:(ZJJSBridgeAdPlugin *)adPlugin
     method:(NSInteger)method
   adParams:(ZJJSAdParams *)adParams;

@end

NS_ASSUME_NONNULL_END
