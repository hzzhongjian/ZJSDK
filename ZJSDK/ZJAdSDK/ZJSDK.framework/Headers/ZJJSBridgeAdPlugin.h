//
//  ZJJSBridgeAdPlugin.h
//  ZJSDK
//
//  Created by 麻明康 on 2025/8/22.
//  Copyright © 2025 zj. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>
#import "ZJJSBridgeAdLoaderDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface ZJJSBridgeAdPlugin : NSObject

@property (nonatomic, copy, readonly) NSString *pluginName;

@property (nonatomic, strong) WKWebView *webView;

@property (nonatomic, strong) UIViewController *rootViewController;

@property (nonatomic, strong) id <ZJJSBridgeAdLoaderDelegate> adLoader;

- (void)registerAdLoader:(id<ZJJSBridgeAdLoaderDelegate>)adLoader;

- (void)initWithWebView:(WKWebView *)webView
     rootViewController:(UIViewController *)rootViewController;

- (void)onJSEvent:(NSInteger)method data:(NSDictionary *)data;

/**
 * 生成回传事件的消息
 */
- (NSDictionary *)generateMsg:(NSInteger)action;

/**
 * 生成回传事件的消息
 */
- (NSDictionary *)generateMsg:(NSInteger)action ecpm:(NSInteger)ecpm;

/**
 * 生成回传事件的消息
 */
- (NSDictionary *)generateMsg:(NSInteger)action error:(NSError * _Nullable)error;

/**
 * 生成回传事件的消息
 */
- (NSDictionary *)generateMsg:(NSInteger)action code:(NSInteger)code msg:(NSString * _Nullable)msg;

/**
 * 生成回传事件的消息
 */
- (NSDictionary *)generateMsg:(NSInteger)action code:(NSInteger)code msg:(NSString * _Nullable)msg ecpm:(NSInteger)ecpm;


- (void)builderRelease;

@end

NS_ASSUME_NONNULL_END
