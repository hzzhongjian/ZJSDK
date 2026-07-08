//
//  WindWebView.h
//  WebViewDemo
//
//  Created by Codi on 2021/11/19.
//

#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>
#import <WindFoundation/WindWKProcessPool.h>

typedef void (^WindWebViewJavascriptEvaluationCompletionHandler)(id result, NSError *error);

typedef NS_ENUM(NSInteger, WindWKNavigationActionPolicy) {
    WindWKNavigationActionPolicyCancel,
    WindWKNavigationActionPolicyAllow,
};


@class WindWebView;

@protocol WindWebViewDelegate <NSObject>

@optional
- (void)webViewDidStartLoad:(WindWebView *)webView;
- (void)webViewDidFinishLoad:(WindWebView *)webView;
- (void)webViewDidClose:(WindWebView *)webView;
- (void)webView:(WindWebView *)webView didFailLoadWithError:(NSError *)error;
- (WindWKNavigationActionPolicy)webView:(WindWebView *)webView decidePolicyForNavigationAction:(NSURLRequest *)request;
- (NSString *)webView:(WindWebView *)webView runJavaScriptTextInputPanelWithPrompt:(NSString *)prompt defaultText:(NSString *)defaultText;

- (void)webViewDidClicked:(WindWebView *)webView params:(NSDictionary *)params;
@end


@interface WindWebView : UIView

@property (nonatomic, weak) id<WindWebViewDelegate> delegate;

@property (nonatomic, strong, readonly) WKWebView *webView;

/// 拦截网络会走缓存策略
- (instancetype)initWithFrame:(CGRect)frame interceptEnable:(BOOL)enable;

/// 预加载html,开启网络拦截，预加载才会生效
- (void)preloadWebViewWithRequest:(NSURLRequest *)request;

- (void)webViewEnterReusedPool;

- (void)stopLoading;

- (void)reload;

/// 加载
- (void)loadRequest:(NSURLRequest *)request;

/// 加载
- (void)loadHTMLString:(NSString *)string;

- (void)injectionWithScripts:(NSArray<NSString *> *)scripts;

- (void)stringByEvaluatingJavaScriptFromString:(NSString *)javaScriptString;

- (void)stringByEvaluatingJavaScript:(NSString *)javaScriptString
                   completionHandler:(WindWebViewJavascriptEvaluationCompletionHandler)completionHandler;

- (void)removeScriptMessageHandlerForName:(NSString *)name;

- (void)addScriptMessageHandler:(id <WKScriptMessageHandler>)scriptMessageHandler name:(NSString *)name;

- (void)addTapGestureRecongnier;

@end
