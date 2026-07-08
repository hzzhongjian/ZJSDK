//
//  WindWKProcessPool.h
//  WebViewDemo
//
//  Created by Codi on 2021/11/19.
//

#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>


@class WindWebView;

@interface WindWKProcessPool : NSObject

@property (nonatomic, strong) WKProcessPool *processPool;

/// 开启请求拦截， default: NO, 改变拦截状态会清空复用池，
@property (nonatomic, assign) BOOL interceptEnable;

/// 缓存过期时间 单位天
@property (nonatomic, assign) NSUInteger cacheExpirationTime;



+ (instancetype)sharedInstance;
/// 从复用池中取出一个WebView，如果没有就创建
- (WindWebView *)getReusedWebView;
/// 把一个webView扔到复用池
- (void)recycleReusedWebView:(WindWebView *)webView;
/// 从可见池中移除
- (void)removeInVisiblePool:(WindWebView *)webView;

/// 预初始化WebView
- (void)prepareInitWebView;

@end
