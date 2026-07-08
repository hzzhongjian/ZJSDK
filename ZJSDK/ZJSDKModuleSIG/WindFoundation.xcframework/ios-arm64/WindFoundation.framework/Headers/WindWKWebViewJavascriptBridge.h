#import <Foundation/Foundation.h>
#import <WindFoundation/WindWebViewJavascriptBridgeBase.h>
#import <WebKit/WebKit.h>

@interface WindWKWebViewJavascriptBridge : NSObject<WKNavigationDelegate, WindWebViewJavascriptBridgeBaseDelegate,WKScriptMessageHandler>

+ (instancetype)bridgeForWebView:(WKWebView*)webView;
+ (void)enableLogging;

- (void)registerHandler:(NSString*)handlerName handler:(WVJBHandler)handler;
- (void)removeHandler:(NSString*)handlerName;
- (void)callHandler:(NSString*)handlerName;
- (void)callHandler:(NSString*)handlerName data:(id)data;
- (void)callHandler:(NSString*)handlerName data:(id)data responseCallback:(WVJBResponseCallback)responseCallback;
- (void)reset;
- (void)disableJavscriptAlertBoxSafetyTimeout;
- (void)removeScriptHandle;

@end

