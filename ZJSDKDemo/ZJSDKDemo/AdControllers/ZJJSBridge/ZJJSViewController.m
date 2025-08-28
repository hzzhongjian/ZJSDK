//
//  ZJJSViewController.m
//  ZJSDKDemo
//
//  Created by 麻明康 on 2025/8/22.
//  Copyright © 2025 zj. All rights reserved.
//

#import "ZJJSViewController.h"
#import <WebKit/WebKit.h>
#import <ZJSDK/ZJJSBridgeAdPlugin.h>
#import <ZJSDK/ZJJSBridgeAdLoaderImpl.h>

@interface ZJJSViewController () <WKNavigationDelegate>

@property (nonatomic, strong) WKWebView *webView;

@property (nonatomic, strong) ZJJSBridgeAdPlugin *adPlugin;

@end

@implementation ZJJSViewController


- (void)viewDidLoad
{
    [super viewDidLoad];
    NSURL *url = [NSURL URLWithString:@"https://static-1318684143.cos.ap-shanghai.myqcloud.com/sdk-downloads/ios/h5app/index.html"];
    NSURLRequest *urlRequest = [NSURLRequest requestWithURL:url];
    [self.webView loadRequest:urlRequest];
    
//    NSString *htmlFile = [[NSBundle mainBundle]pathForResource:@"JSSdkTest" ofType:@"html"];
//    NSURL *baseUrl = [NSURL fileURLWithPath:htmlFile isDirectory: YES];
//    NSString *indexContent = [NSString stringWithContentsOfFile:htmlFile encoding: NSUTF8StringEncoding error:nil];
//    [self.webView loadHTMLString:indexContent baseURL:baseUrl];
    
    [self.view addSubview:self.webView];
    self.adPlugin = [[ZJJSBridgeAdPlugin alloc] init];
    [self.adPlugin initWithWebView:self.webView rootViewController:self];
    [self.adPlugin registerAdLoader:[ZJJSBridgeAdLoaderImpl sharedInstance]];
    
    
}

- (void)dealloc
{
    if (self.webView) {
        [self.adPlugin builderRelease];
    }
}

- (WKWebView *)webView
{
    if (!_webView) {
        WKUserContentController *wkUController = [[WKUserContentController alloc] init];
        //[wkUController addUserScript:wkUScript];
        WKWebViewConfiguration *wkWebConfig = [[WKWebViewConfiguration alloc] init];
        wkWebConfig.preferences=[[WKPreferences alloc] init];
        wkWebConfig.preferences.minimumFontSize=10;
        wkWebConfig.preferences.javaScriptEnabled=YES;
        wkWebConfig.websiteDataStore = [WKWebsiteDataStore defaultDataStore];
        
        [wkWebConfig.preferences setValue:@YES forKey:@"allowFileAccessFromFileURLs"];
        if (@available(iOS 10.0, *)) {
             [wkWebConfig setValue:@YES forKey:@"allowUniversalAccessFromFileURLs"];
        }
        //wkWebConfig.preferences.javaScriptCanOpenWindowsAutomatically=NO;
        wkWebConfig.userContentController = wkUController;
        _webView = [[WKWebView alloc] initWithFrame:self.view.bounds configuration:wkWebConfig];;
        _webView.scrollView.showsVerticalScrollIndicator = NO;
        _webView.autoresizingMask = UIViewAutoresizingFlexibleHeight;
        _webView.navigationDelegate = self;
        
        [_webView sizeToFit];
        [_webView setAutoresizesSubviews:YES];
        [_webView setAllowsBackForwardNavigationGestures:true];
    }
    return _webView;
}

#pragma mark - WKNavigationDelegate
- (void)webView:(WKWebView *)webView didFinishNavigation:(null_unspecified WKNavigation *)navigation
{
    
}


@end
