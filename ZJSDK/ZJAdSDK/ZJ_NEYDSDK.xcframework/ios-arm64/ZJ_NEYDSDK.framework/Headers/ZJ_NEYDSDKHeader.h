//
//  ZJ_NEYD_SDK_VERSION    3.0.1
//  Created by lilu on 2021/1/18.
//  Copyright © 2021 Zj_neyd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import <WebKit/WebKit.h>
#import "ZJ_NEYDAdLogoView.h"


extern const CGFloat zj_neyd_kUniversalStarRatingScale;
extern const CGFloat zj_neyd_kStarRatingMaxValue;
extern const CGFloat zj_neyd_kStarRatingMinValue;
extern const NSTimeInterval zj_neyd_kDefaultRequiredSecondsForImpression;
extern NSString *const zj_neyd_kAdTitleKey;
extern NSString *const zj_neyd_kAdTextKey;
extern NSString *const zj_neyd_kAdIconImageKey;
extern NSString *const zj_neyd_kAdMainImageKey;
extern NSString *const zj_neyd_kAdCTATextKey;
extern NSString *const zj_neyd_kAdStarRatingKey;
extern NSString *const zj_neyd_kVideoConfigKey;
extern NSString *const zj_neyd_kVASTVideoKey;
extern NSString *const zj_neyd_kVideoKey;
extern NSString *const zj_neyd_kStyleNameKey;
extern NSString *const zj_neyd_kNativeVideoAdConfigKey;
extern NSString *const zj_neyd_kAdDAAIconImageKey;
extern NSString *const zj_neyd_kDAAIconImageName;
extern NSString *const zj_neyd_kDAAIconTapDestinationURL;
extern NSString *const zj_neyd_kImpressionTrackerURLsKey;
extern NSString *const zj_neyd_kDefaultActionURLKey;
extern NSString *const zj_neyd_kClickTrackerURLKey;
extern NSString *const zj_neyd_kCtaTrackerURLKey;
extern NSString *const zj_neyd_kAdZJ_NEYDEXTTextKey;
extern NSString *const zj_neyd_kLogEventRequestPropertiesKey;
extern NSString *const zj_neyd_kBrandAdTypeHeaderKey;
extern NSString *const zj_neyd_kDeeplinkURLKey;
extern NSString *const zj_neyd_kDeeplinkTrackerURLsKey;

UIInterfaceOrientation ZJ_NEYDInterfaceOrientation(void);
UIWindow *ZJ_NEYDKeyWindow(void);
CGFloat ZJ_NEYDStatusBarHeight(void);
CGRect ZJ_NEYDApplicationFrame(void);
CGRect ZJ_NEYDScreenBounds(void);
CGSize ZJ_NEYDScreenResolution(void);
CGFloat ZJ_NEYDDeviceScaleFactor(void);
NSDictionary *ZJ_NEYDDictionaryFromQueryString(NSString *query);
NSString *ZJ_NEYDSHA1Digest(NSString *string);
BOOL ZJ_NEYDViewIsVisible(UIView *view);
BOOL ZJ_NEYDViewIntersectsParentWindowWithPercent(UIView *view, CGFloat percentVisible);
NSString *ZJ_NEYDResourcePathForResource(NSString *resourceName);
NSArray *ZJ_NEYDConvertStringArrayToURLArray(NSArray *strArray);

typedef void(^ZJ_NEYDNativeAdBatchProviderHandler)(NSArray *responses,
                                              NSError *error);

typedef NS_ENUM(NSInteger, ZJ_NEYDHostDomain){
    ZJ_NEYDHostDomainDefault,  //默认域名gorgon
    ZJ_NEYDHostDomainHongKong  //香港域名gorgon
};

@interface ZJ_NEYDAdManager : NSObject
/// 广告请求host地址
@property (nonatomic, assign) ZJ_NEYDHostDomain  hostDomain;
/// 广告请求超时时间，以秒为单位，默认10.0
@property (nonatomic, assign) NSTimeInterval  hostTimeoutInterval;
/// 广告请求是否允许下载资源，全局配置，默认YES
@property (nonatomic, assign) BOOL allowDownloadResource;
/// 允许获取时区参数,默认为YES
@property (nonatomic, assign) BOOL  isTimeZoneParamsEnabled;
/// 允许获取反作弊参数,默认为YES
@property (nonatomic, assign) BOOL  isAntiCheatingParamsEnabled;
/// 允许获取设备信息,默认为YES
@property (nonatomic, assign) BOOL  isDeviceParamsEnabled;
/**
 * 是否强制要求响应广告链接为https，No 非强制， YES 为强制
 * 默认为 No
 */
@property (nonatomic, assign) BOOL isSecure;

/**
 * 是否允许 SDK 获取应用安装信息
 * 默认为YES
 */
@property (nonatomic, assign) BOOL checkAppsInfo;
/// 获取单例
+ (ZJ_NEYDAdManager *)sharedInstance;
/// 获取广告前的准备工作，必须在request广告前先调用这个接口
- (void)prepareForLoadAd;

/// 获取服务器下发的广告配置（存储的data字段的值）
- (NSDictionary * _Nullable)adConfig;

/// 获取 SDK 版本号，如 @"3.0.1"
+ (NSString *)sdkVersion;

@end

@interface ZJ_NEYDNativeAdUtils : NSObject
+ (BOOL)isDeeplinkURL:(NSURL *)URL;
@end

@interface ZJ_NEYDIdentityProvider : NSObject
+ (NSString *)identifier;
+ (NSString *)obfuscatedIdentifier;
+ (BOOL)advertisingTrackingEnabled;
+ (NSString *)getCallBackUserIdentifier;
+ (void)storeCallBackUserIdentifier:(NSString *)callBackIdentifier;
@end

/// 交互类型
typedef NS_ENUM(NSUInteger, ZJ_NEYDAdInteractionType) {
    
    /// 点击
    ZJ_NEYDAdInteractionTypeClick = 0,
    
    /// 滑动点击
    ZJ_NEYDAdInteractionTypeSlide = 1,
    
    /// 摇一摇
    ZJ_NEYDAdInteractionTypeShake = 2,
    
    /// 扭一扭
    ZJ_NEYDAdInteractionTypeTurn = 5,
    
    /// 三合一（点击、滑动点击、扭一扭）
    ZJ_NEYDAdInteractionTypeClick_Slide_Turn = 6,
};

/// 广告点击信息（点击down 或者up传一个就可以，滑动都传）
@interface ZJ_NEYDNativeAdClickInfo : NSObject

@property (nonatomic, assign) ZJ_NEYDAdInteractionType sld;

/// 按下去的位置X（逻辑像素）
@property (nonatomic, assign) CGFloat clickDownX;

/// 按下去的位置Y（逻辑像素）
@property (nonatomic, assign) CGFloat clickDownY;

/// 手指抬起离开的位置X（逻辑像素）
@property (nonatomic, assign) CGFloat clickUpX;

/// 手指抬起离开的位置Y（逻辑像素）
@property (nonatomic, assign) CGFloat clickUpY;

/// （逻辑像素）
@property (nonatomic, assign) CGFloat adWidth;

/// （逻辑像素）
@property (nonatomic, assign) CGFloat adHeight;


/// 摇一摇
@property (nonatomic, assign) CGFloat shakeX;

/// 摇一摇
@property (nonatomic, assign) CGFloat shakeY;

/// 摇一摇
@property (nonatomic, assign) CGFloat shakeZ;

/// 扭一扭
@property (nonatomic, assign) NSInteger turnX;

/// 扭一扭
@property (nonatomic, assign) NSInteger turnY;

/// 扭一扭
@property (nonatomic, assign) NSInteger turnZ;

/// 扭一扭  扭动触发点击时扭动的总时间（单位毫秒）
@property (nonatomic, assign) NSInteger turnTime;

@end

/// 微信小程序跳转字段信息
@interface ZJ_NEYDLaunchWxMiniProgramInfo : NSObject
/// 微信小程序跳转字段所有字段字典
@property (nonatomic, strong) NSDictionary *wxMiniProgramDict;
@property (nonatomic, copy) NSString *appid;
@property (nonatomic, copy) NSString *originid;
@property (nonatomic, copy) NSString *path;
@end

@protocol ZJ_NEYDNativeAdAdapter;
@protocol ZJ_NEYDNativeAdDelegate;
@protocol ZJ_NEYDNativeAdRenderer;
@protocol ZJ_NEYDBrowserViewControllerBuilderDelegate;
@class ZJ_NEYDAdConfiguration;
@class ZJ_NEYDBrowserViewController;
@class ZJ_NEYDNativeAdClickInfo;
typedef void (^ZJ_NEYDNativeAdRenderCompletion)(UIView * _Nullable adView, CGSize renderedSize, NSError * _Nullable error);
@interface ZJ_NEYDNativeAd : NSObject
@property (nonatomic) BOOL hasAttachedToView;
@property (nonatomic, weak) id<ZJ_NEYDNativeAdDelegate> delegate;
@property (nonatomic, strong) id<ZJ_NEYDBrowserViewControllerBuilderDelegate> browserViewControllerBuilderDelegate;
@property (nonatomic, readonly) NSDictionary *properties;
@property (nonatomic, readonly) id<ZJ_NEYDNativeAdAdapter> adAdapter;
/// 素材强类型属性（从 properties 取值，无对应 key 返回 nil）
@property (nonatomic, readonly) NSString * _Nullable requestId;      // ydBid
@property (nonatomic, readonly) NSString * _Nullable bidId;         // ydBid
@property (nonatomic, readonly) double ecpm;                         // eCPM，缺失时为0
@property (nonatomic, readonly) NSString * _Nullable creativeId;     // 兼容NSString/NSNumber
@property (nonatomic, readonly) NSString * _Nullable videoUrl;       // videourl
@property (nonatomic, readonly) NSString * _Nullable imgUrl;         // mainimage
@property (nonatomic, readonly) NSString * _Nullable landingpageUrl; // clk
@property (nonatomic, readonly) NSString * _Nullable deeplinkUrl;    // deeplink
@property (nonatomic, readonly) NSString * _Nullable title;          // title
@property (nonatomic, readonly) NSString * _Nullable packageName;    // 无对应 key 返回 nil
- (instancetype)initWithAdAdapter:(id<ZJ_NEYDNativeAdAdapter>)adAdapter;
/// 返回 SDK 模板渲染 View；渲染失败时返回 nil，并通过 error 返回原因。
/// 固定高度模板可同步返回；高度为 0 的模板请使用 renderAdViewWithCompletion: 等待最终高度。
- (UIView *)retrieveAdViewWithError:(NSError **)error browserViewControllerBuilderDelegate:(id<ZJ_NEYDBrowserViewControllerBuilderDelegate>)browserViewControllerBuilderDelegate;
/// 渲染模板，并在图片或视频素材尺寸及最终模板高度确定后回调。
- (void)renderAdViewWithCompletion:(ZJ_NEYDNativeAdRenderCompletion)completion;
/// 需要自定义落地页控制器时使用。
- (void)renderAdViewWithBrowserDelegate:(id<ZJ_NEYDBrowserViewControllerBuilderDelegate>)browserDelegate
                             completion:(ZJ_NEYDNativeAdRenderCompletion)completion;
- (void)playEndCardVideo;
- (void)startPreFetchVideo;
- (BOOL)verifyVideoInfoValid;
@property (nonatomic, assign) BOOL isBrand;
@property (nonatomic, assign) BOOL isEndCardVideo;
@property (nonatomic, assign) NSTimeInterval timeoutInterval;
/**
 品牌广告点击类型;
 取值为"0"为"跳转落地页";
 取值为"1"为"跳转视频内页";
 取值为"2"为"跳转deeplink";
 取值为"3"为"跳转小程序";
 */
@property (nonatomic, copy) NSString *brandClkType;

/// 微信小程序跳转相关字段
@property (nonatomic, strong) ZJ_NEYDLaunchWxMiniProgramInfo *wxMiniProgramInfo;

/// 获取落地页URL
- (NSURL *)actualActionURL;

/// 获取落地页URL
/// @param clickInfo 点击信息
- (NSURL *)actualActionURLWithClickInfo:(ZJ_NEYDNativeAdClickInfo *)clickInfo;

// 不需要对callback进行encode，监测链接上报时会进行encode
- (void)updateMonitorURLWithCallback:(NSString *)callback;

/// 广告点击上报接口
/// 若开发者自行渲染广告需要上报点击事件的时候调用此接口
/// 广告点击上报接口。有效上报后会触发 nativeAdDidClick: 代理回调。
- (void)trackAdClick;

/// 广告点击上报接口,同trackAdClick
/// @param clickInfo 点击信息
/// 有效上报后会触发 nativeAdDidClick: 代理回调。
- (void)trackAdClickWithClickInfo:(ZJ_NEYDNativeAdClickInfo *)clickInfo;

/// 广告展示上报接口
/// 若开发者自行渲染广告需要上报展示事件的时候调用此接口
/// 广告展示上报接口。有效上报后会触发 nativeAdWillLogImpression: 代理回调。
- (void)trackAdImpression;

/// 广告竞价成功上报
- (void)reportWithWinPrice:(NSString *)winPrice;

/// 广告打开deeplink上报接口
/// 若开发者自行渲染广告需要上报打开deeplink事件的时候调用此接口
/// @param deeplinkUrl 打开的deeplinkUrl
/// @param success 是否打开成功
- (void)trackAdDeeplinkUrl:(NSURL *)deeplinkUrl success:(BOOL)success;
/**
 广告打开微信小程序上报接口
 若开发者自行渲染广告需要上报打开微信小程序事件的时候调用此接口
 @param success 是否打开成功
 */
- (void)trackAdWxMiniProgramSuccess:(BOOL)success;
- (void)openAdDestinationFromViewController:(UIViewController *)viewController
                                  completion:(void (^ _Nullable)(BOOL success, NSError * _Nullable error))completion;

/// 自动完成点击上报并打开广告目标地址，同时透传自渲染点击坐标等信息。
- (void)openAdDestinationFromViewController:(UIViewController *)viewController
                                  clickInfo:(ZJ_NEYDNativeAdClickInfo * _Nullable)clickInfo
                                completion:(void (^ _Nullable)(BOOL success, NSError * _Nullable error))completion;

/// 对url 绑定 点击信息
- (NSString *)getUrlWithClickInfo:(ZJ_NEYDNativeAdClickInfo *)clickInfo urlStr:(NSString *)urlStr;

///构建信息流视频落地页vc
/// @param isPushed 是否是push操作
- (UIViewController *)buildNativeVideoVcWithIsPushed:(BOOL)isPushed;

/// 获取由 SDK 管理的原生视频播放视图，媒体可将其添加到自定义布局中。
/// 仅原生视频广告支持；非视频广告或当前渲染器不支持时返回 nil。
/// 媒体需持有当前 ZJ_NEYDNativeAd，以维持播放器生命周期。
/// 独立模式不展示播放器内部 CTA，也不提供全屏入口。
/// 必须在主线程调用；非主线程调用将返回 nil。
- (UIView * _Nullable)buildNativeVideoView;

/// 设置原生视频是否静音。可在 buildNativeVideoView 前后设置，默认为 YES。
/// 仅对原生视频播放器生效，必须在主线程调用。
@property (nonatomic, assign, getter=isNativeVideoMuted) BOOL nativeVideoMuted;
@end

@interface ZJ_NEYDDAOPlayerViewController : UIViewController
@property (nonatomic) BOOL muted;
@end

@interface ZJ_NEYDDefaultNativeVideoController  : UIViewController
@property (nonatomic) ZJ_NEYDDAOPlayerViewController *playerController;
@end

@interface ZJ_NEYDNativeCache : NSObject
+ (instancetype)sharedCache;
- (BOOL)cachedDataExistsForKey:(NSString *)key;
- (NSData *)retrieveDataForKey:(NSString *)key;
- (NSURL *)retrieveDataUrlForKey:(NSString *)key;
- (void)storeData:(NSData *)data forKey:(NSString *)key;
- (void)removeAllDataFromCache;
- (void)setInMemoryCacheEnabled:(BOOL)enabled;
@end
@protocol ZJ_NEYDNativeAdDelegate <NSObject>
@optional
/// 广告将展示模态内容时回调。
/// 在激励视频中，等价于视频刚刚开始播放时。
/// @param nativeAd 发送该消息的广告对象。
- (void)willPresentModalForNativeAd:(ZJ_NEYDNativeAd *)nativeAd;
/// 广告关闭模态内容后回调，控制权交还给宿主 App。
/// 在激励视频中，等价于关闭 endcard 时。
/// @param nativeAd 发送该消息的广告对象。
- (void)didDismissModalForNativeAd:(ZJ_NEYDNativeAd *)nativeAd;
/// 用户因点击广告而即将离开宿主 App 时回调（如跳转 App Store、外部浏览器等）。
/// @param nativeAd 发送该消息的广告对象。
- (void)willLeaveApplicationFromNativeAd:(ZJ_NEYDNativeAd *)nativeAd;
/// 激励视频独有：视频即将播放时回调。
/// 触发时机与 willPresentModalForNativeAd 相同，推荐使用本回调。
/// @param nativeAd 发送该消息的广告对象。
- (void)videoWillPlayFromNativeAd:(ZJ_NEYDNativeAd *)nativeAd;
/// 激励视频独有：视频即将关闭时回调。
/// 触发时机与 didDismissModalForNativeAd 相同，推荐使用本回调。
/// @param nativeAd 发送该消息的广告对象。
- (void)videoWillCloseFromNativeAd:(ZJ_NEYDNativeAd *)nativeAd;
/// 激励视频独有：endcard 即将展示时回调。
/// 通常在此回调中发放激励，因为此时用户已看完视频。
/// @param nativeAd 发送该消息的广告对象。
- (void)videoWillShowEndCardViewFromNativeAd:(ZJ_NEYDNativeAd *)nativeAd;
/// 激励视频独有：用户点击视频播放器上的静音/取消静音按钮时回调。
/// @param nativeAd 发送该消息的广告对象。
- (void)videoMutedButtonPressedFromNativeAd:(ZJ_NEYDNativeAd *)nativeAd;
/// 激励视频独有：即将开始预取视频素材时回调。
/// 仅在允许预取（服务端下发预取标记）时触发。
/// @param nativeAd 发送该消息的广告对象。
- (void)willStartPreFetchVideoForNativeAd:(ZJ_NEYDNativeAd *)nativeAd;
/// 激励视频独有：视频素材已就绪、可以播放时回调。
/// 预取成功、或未预取时视频内容准备完成，均会触发。通常在此回调中调用播放动作。
/// @param nativeAd 发送该消息的广告对象。
- (void)readyToPlayVideoForNativeAd:(ZJ_NEYDNativeAd *)nativeAd;
/// 激励视频独有：预取视频素材失败时回调。
/// 预取失败不影响后续正常播放（会回退为实时加载），请在回调中做容错处理。
/// @param nativeAd 发送该消息的广告对象。
- (void)failPreFetchVideoForNativeAd:(ZJ_NEYDNativeAd *)nativeAd;
/// 激励视频独有：视频播放过程中出错时回调（如素材损坏、解码失败）。
/// @param nativeAd 发送该消息的广告对象。
- (void)videoPlayErrorForNativeAd:(ZJ_NEYDNativeAd *)nativeAd;
/// 激励视频广告完成播放回调
/// @param isPlayDone 是否播放完成，若用户点击关闭按钮则返回NO，正常播放完成返回YES
/// @param nativeAd Ad
- (void)rewardVideoDidFinish:(BOOL)isPlayDone forNativeAd:(ZJ_NEYDNativeAd *)nativeAd;
/// 广告展示（曝光）上报时回调。
/// @param nativeAd 发送该消息的广告对象。
- (void)nativeAdWillLogImpression:(ZJ_NEYDNativeAd *)nativeAd;
/// 广告被点击时回调。
/// @param nativeAd 发送该消息的广告对象。
- (void)nativeAdDidClick:(ZJ_NEYDNativeAd *)nativeAd;
@required
- (UIViewController *)viewControllerForPresentingModalView;
@end

@protocol ZJ_NEYDNativeAdAdapterDelegate <NSObject>
@required
- (UIViewController *)viewControllerForPresentingModalView;
- (void)nativeAdWillPresentModalForAdapter:(id<ZJ_NEYDNativeAdAdapter>)adapter;
- (void)nativeAdDidDismissModalForAdapter:(id<ZJ_NEYDNativeAdAdapter>)adapter;
- (void)nativeAdWillLeaveApplicationFromAdapter:(id<ZJ_NEYDNativeAdAdapter>)adapter;
@optional
- (void)nativeAdWillLogImpression:(id<ZJ_NEYDNativeAdAdapter>)adAdapter;
- (void)nativeAdDidClick:(id<ZJ_NEYDNativeAdAdapter>)adAdapter;
@end

@protocol ZJ_NEYDNativeAdAdapter <NSObject>
@required
@property (nonatomic, readonly) NSDictionary *properties;
@property (nonatomic, readonly) NSURL *defaultActionURL;
@optional
- (void)displayContentForURL:(NSURL *)URL rootViewController:(UIViewController *)controller withBrowserController:(ZJ_NEYDBrowserViewController *)browserController;
- (BOOL)enableThirdPartyClickTracking;
- (void)trackClick;
@property (nonatomic, weak) id<ZJ_NEYDNativeAdAdapterDelegate> delegate;
- (void)willAttachToView:(UIView *)view;
- (void)displayContentForDAAIconTapWithBrowserController:(ZJ_NEYDBrowserViewController *)browserController;
- (UIView *)privacyInformationIconView;
- (UIView *)mainMediaView;
@end

@class ZJ_NEYDNativeAdRenderingImageLoader;
@protocol ZJ_NEYDNativeAdRendering <NSObject>
@optional
- (void)zj_neyd_setMediaAspectRatio:(CGFloat)mediaAspectRatio;
- (CGSize)zj_neyd_sizeThatFitsWidth:(CGFloat)width;
- (UILabel *)nativeMainTextLabel;
- (UILabel *)nativeTitleTextLabel;
- (UIImageView *)nativeIconImageView;
- (UIImageView *)nativeMainImageView;
- (UIView *)nativeVideoView;
- (UILabel *)nativeCallToActionTextLabel;
- (UIImageView *)nativePrivacyInformationIconImageView;
- (NSMutableDictionary *)nativePropertyTextLabels;
- (NSMutableDictionary *)nativePropertyImageViews;
- (void)layoutStarRating:(NSNumber *)starRating;
/// 开屏广告新增，允许SDK对是否全屏广告做布局调整
- (void)layoutFullScreen:(BOOL)isFullScreen;
- (void)layoutFullScreen:(BOOL)isFullScreen bottomViewHeight:(CGFloat)bottomViewHeight;
- (void)layoutCustomAssetsWithProperties:(NSDictionary *)customProperties imageLoader:(ZJ_NEYDNativeAdRenderingImageLoader *)imageLoader;
+ (UINib *)nibForAd;
@end

@class ZJ_NEYDNativeAdRendererImageHandler;
@interface ZJ_NEYDNativeAdRenderingImageLoader : NSObject
- (instancetype)initWithImageHandler:(ZJ_NEYDNativeAdRendererImageHandler *)imageHandler;
- (void)loadImageForURL:(NSURL *)url intoImageView:(UIImageView *)imageView;
@end


@class ZJ_NEYDNativeAdRequest;
@class ZJ_NEYDNativeAdRequestTargeting;

typedef void(^ZJ_NEYDNativeAdRequestHandler)(ZJ_NEYDNativeAdRequest *request,
                                        ZJ_NEYDNativeAd *response,
                                        NSError *error);
@interface ZJ_NEYDNativeAdRequest : NSObject
@property (nonatomic, strong) ZJ_NEYDNativeAdRequestTargeting *targeting;
/// 广告网络请求超时时间，默认为[ZJ_NEYDAdManager sharedInstance].hostTimeoutInterval
@property (nonatomic, assign) NSTimeInterval requestTimeout;
/// 允许请求广告时下载资源,默认为[ZJ_NEYDAdManager sharedInstance].allowDownloadResource
@property (nonatomic, assign) BOOL allowDownloadResource;
+ (ZJ_NEYDNativeAdRequest *)requestWithAdUnitIdentifier:(NSString *)identifier rendererConfigurations:(NSArray *)rendererConfigurations;
+ (ZJ_NEYDNativeAdRequest *)requestWithAdUnitIdentifier:(NSString *)identifier rendererConfigurations:(NSArray *)rendererConfigurations adNet:(NSString *)adNet;
- (void)startWithCompletionHandler:(ZJ_NEYDNativeAdRequestHandler)handler;
- (void)startWithAdSequence:(NSInteger)adSequence withCompletionHandler:(ZJ_NEYDNativeAdRequestHandler)handler;
@end

@class ZJ_NEYDNativeAdPreloadRequest, ZJ_NEYDNativeAdRequestTargeting;
typedef void(^ZJ_NEYDNativeAdPreloadRequestHandler)(ZJ_NEYDNativeAdPreloadRequest *request,
                                        NSDictionary *response,
                                        NSError *error);
@interface ZJ_NEYDNativeAdPreloadRequest : NSObject
@property (nonatomic, strong) ZJ_NEYDNativeAdRequestTargeting *targeting;
+ (ZJ_NEYDNativeAdPreloadRequest *)requestWithAdUnitIdentifier:(NSString *)identifier;

- (void)preloadWithCompletionHandler:(ZJ_NEYDNativeAdPreloadRequestHandler)handler;
- (void)preloadWithAdSequence:(NSInteger)adSequence withCompletionHandler:(ZJ_NEYDNativeAdPreloadRequestHandler)handler;
@end

// 开屏广告缓存request
@class ZJ_NEYDSplashAdPreloadRequest, ZJ_NEYDNativeAdRequestTargeting;
typedef void(^ZJ_NEYDSplashAdPreloadRequestHandler)(ZJ_NEYDSplashAdPreloadRequest *request, NSDictionary *response, NSError *error);
@interface ZJ_NEYDSplashAdPreloadRequest : NSObject
@property (nonatomic, strong) ZJ_NEYDNativeAdRequestTargeting *targeting;
+ (ZJ_NEYDSplashAdPreloadRequest *)requestWithAdUnitIdentifier:(NSString *)identifier;
- (void)preloadWithCompletionHandler:(ZJ_NEYDSplashAdPreloadRequestHandler)handler;
- (void)preloadWithAdSequence:(NSInteger)adSequence withCompletionHandler:(ZJ_NEYDSplashAdPreloadRequestHandler)handler;
@end

//开屏广告相关
@class ZJ_NEYDSplashAd, ZJ_NEYDSplashAdRequest, ZJ_NEYDNativeAdRequestTargeting;

typedef void(^ZJ_NEYDSplashAdRequestHandler)(ZJ_NEYDSplashAdRequest *request, ZJ_NEYDSplashAd *response, NSError *error);

@interface ZJ_NEYDSplashAdRequest : NSObject
@property (nonatomic, strong) ZJ_NEYDNativeAdRequestTargeting *targeting;
/// 开屏广告请求超时时间，默认0.3s
@property (nonatomic, assign) NSTimeInterval requestTimeout;
+ (ZJ_NEYDSplashAdRequest *)requestWithAdUnitIdentifier:(NSString *)identifier;
- (void)startWithCompletionHandler:(ZJ_NEYDSplashAdRequestHandler)handler;
@end

@interface ZJ_NEYDSplashAdRenderer : NSObject <ZJ_NEYDNativeAdRenderer>
@property (nonatomic, assign) Class renderingViewClass;
@property (nonatomic, assign) CGFloat bottomViewHeight;
@end

@class ZJ_NEYDSplashAd, ZJ_NEYDSplashAdRenderer;
@protocol ZJ_NEYDSplashAdDelegate <NSObject>
- (void)splashAdDidLogImpression:(ZJ_NEYDSplashAd *)splashAd;
- (void)splashAdDidClick:(ZJ_NEYDSplashAd *)splashAd;
- (void)splashAdDidDismiss:(ZJ_NEYDSplashAd *)splashAd;
@end

@interface ZJ_NEYDSplashAd : NSObject
@property (nonatomic, strong) ZJ_NEYDNativeAd *nativeAd;
/// 广告位id
@property (nonatomic, copy) NSString *placementId;
/// 点击交互类型参数，值为"1"表示摇一摇交互，值为"2"表示滑动交互，无值或无参数下发时，默认为普通点击交互类型;
@property (nonatomic, copy) NSString *clickType;
/// 点击前往文案
@property (nonatomic, copy) NSString *clkText;
/// 广告创意id
@property (nonatomic, copy) NSString *creativeId;
@property (nonatomic, readonly) NSString * _Nullable requestId;
@property (nonatomic, readonly) NSString * _Nullable bidId;
@property (nonatomic, readonly) double ecpm;
/// 是否全屏
@property (nonatomic, assign) BOOL fullScreen;
/// 是否可以全屏点击
@property (nonatomic, assign) BOOL fullScreenClick;
/// 是否是滑动交互类型广告
@property (nonatomic, assign) BOOL slideInteract;
/// 广告Id
@property (nonatomic, copy) NSString *adId;
/// 是否为效果广告占位符，效果广告占位符只包含weight和isEffectCarouselPos两个字段
@property (nonatomic, assign) BOOL isEffectCarouselPos;
/// 开屏形态，“0”：开屏回收，“1”：原生广告，”“：普通形态（即原有eadd接口desc字段）
@property (nonatomic, copy) NSString *uiStyle;
/// 是否是首刷广告
@property (nonatomic, assign) BOOL isFirstShot;
/// 是否支持摇一摇，1：是，2：否
@property (nonatomic, copy) NSString *shakable;
/// 开屏展示时间，单位为秒
@property (nonatomic, assign) NSInteger showInterval;
/// 轮播权重
@property (nonatomic, assign) NSInteger weight;
/// 开始结束时间单位毫秒
@property (nonatomic, assign) NSTimeInterval startTime;
@property (nonatomic, assign) NSTimeInterval endTime;

/// 此广告对象所属的推广组id，整型，i.e：300132
@property (nonatomic, strong) NSNumber *groupId;

/// 最后修改时间
@property (nonatomic, assign) NSTimeInterval modTime;
/// 所有字段
@property (nonatomic, strong) NSDictionary *jsonDict;

@property (nonatomic, weak)  id<ZJ_NEYDSplashAdDelegate> delegate;

@property (nonatomic, strong) ZJ_NEYDSplashAdRenderer *render;
- (UIView *)renderAdView;
- (UIView *)renderAdViewWithBottomView:(UIView * _Nullable)bottomView;

- (instancetype)initWithDict:(NSDictionary *)jsonDict;
/// 是否是今天的排期广告
- (BOOL)isTodayAdValid;
/// 是否已缓存全部素材
- (BOOL)isCached;
/// 是否是效果广告位占位
- (BOOL)isEffectCarousel;
/// 广告点击上报接口
- (void)trackSplashAdClick;

/// 广告点击上报接口,同 trackSplashAdClick
/// @param clickInfo 点击信息
- (void)trackSplashAdClickWithClickInfo:(ZJ_NEYDNativeAdClickInfo *)clickInfo;

/// 广告展示上报接口
- (void)trackSplashAdImpression;

/// 对url 绑定点击信息
- (NSString *)getUrlWithClickInfo:(ZJ_NEYDNativeAdClickInfo *)clickInfo urlStr:(NSString *)urlStr;
@end

@class ZJ_NEYDSplashAd, ZJ_NEYDSplashAdLoader, ZJ_NEYDNativeAdRequestTargeting;

typedef void(^ZJ_NEYDSplashAdLoaderHandler)(ZJ_NEYDSplashAdLoader *request, ZJ_NEYDSplashAd *response, NSError *error);

@interface ZJ_NEYDSplashAdLoader : NSObject
@property (nonatomic, strong) ZJ_NEYDNativeAdRequestTargeting *targeting;
@property (nonatomic, copy) NSString *adUnitIdentifier;
/// 开屏广告请求超时时间，默认0.3s
@property (nonatomic, assign) NSTimeInterval requestTimeout;

// 白包默认冷启动实时请求；设置为 NO 仅用于兼容旧的热启动缓存场景。
@property (nonatomic, assign) BOOL isCoolStart;

/// 是否在冷启动实时请求的同时查询预取缓存，默认 NO；仅用于兼容旧接入流程。
@property (nonatomic, assign) BOOL enablePrefetch;

+ (ZJ_NEYDSplashAdLoader *)loaderWithAdUnitIdentifier:(NSString *)identifier;
- (void)loadWithCompletionHandler:(ZJ_NEYDSplashAdLoaderHandler)handler;
@end

@class ZJ_NEYDSplashAdPreloader, ZJ_NEYDNativeAdRequestTargeting;

typedef void(^ZJ_NEYDSplashAdPreloaderHandler)(ZJ_NEYDSplashAdPreloader *request, NSDictionary *response, NSError *error);

@interface ZJ_NEYDSplashAdPreloader : NSObject
@property (nonatomic, strong) ZJ_NEYDNativeAdRequestTargeting *targeting;
/// 广告网络请求超时时间，默认为[ZJ_NEYDAdManager sharedInstance].hostTimeoutInterval
@property (nonatomic, assign) NSTimeInterval requestTimeout;
/// 允许4G网络缓存图片资源,默认为YES
@property (nonatomic, assign) BOOL allowDownloadImageResourceVia4G;
/// 允许4G网络缓存视频资源,默认为YES
@property (nonatomic, assign) BOOL allowDownloadVideoResourceVia4G;

+ (ZJ_NEYDSplashAdPreloader *)loaderWithAdUnitIdentifier:(NSString *)identifier;
- (void)preloadWithCompletionHandler:(ZJ_NEYDSplashAdPreloaderHandler)handler;
@end

@interface ZJ_NEYDNativeAdBatchProvider : NSObject
/// 广告网络请求超时时间，默认为[ZJ_NEYDAdManager sharedInstance].hostTimeoutInterval
@property (nonatomic, assign) NSTimeInterval requestTimeout;
/// 允许请求广告时下载资源,默认为[ZJ_NEYDAdManager sharedInstance].allowDownloadResource
@property (nonatomic, assign) BOOL allowDownloadResource;
+ (ZJ_NEYDNativeAdBatchProvider *)requestWithAdUnitIdentifier:(NSString *)identifier rendererConfigurations:(NSArray *)rendererConfigurations;
- (void)getAdsWithTargeting:(ZJ_NEYDNativeAdRequestTargeting *)targeting withAmount:(NSInteger)amount afterComplete:(ZJ_NEYDNativeAdBatchProviderHandler)customHandler;
- (void)cleanRecievedIds;
@end


@protocol ZJ_NEYDNativeAdAdapter;
@protocol ZJ_NEYDNativeAdRendererSettings;
@interface ZJ_NEYDNativeAdRendererConfiguration : NSObject

/// The settings that inform the ad renderer about how it should render the ad.
@property (nonatomic, strong) id<ZJ_NEYDNativeAdRendererSettings> rendererSettings;

/// The renderer class used to render supported custom events.
@property (nonatomic, assign) Class rendererClass;

/// An array of custom event class names (as strings) that the renderClass can render.
@property (nonatomic, strong) NSArray *supportedCustomEvents;
/// The styleName setted on the app web-site used to be selected to render the ad.
@property (nonatomic, readwrite, strong) NSString *styleName;
@end

typedef CGSize (^ZJ_NEYDNativeViewSizeHandler)(CGFloat maximumWidth);
typedef void (^ZJ_NEYDNativeAdAutomaticSizeCompletion)(CGSize size, NSError *error);
@protocol ZJ_NEYDNativeAdRenderer <NSObject>
@required
+ (ZJ_NEYDNativeAdRendererConfiguration *)rendererConfigurationWithRendererSettings:(id<ZJ_NEYDNativeAdRendererSettings>)rendererSettings;
- (instancetype)initWithRendererSettings:(id<ZJ_NEYDNativeAdRendererSettings>)rendererSettings;
- (UIView *)retrieveViewWithAdapter:(id<ZJ_NEYDNativeAdAdapter>)adapter error:(NSError **)error;
@optional
- (void)resolveAutomaticSizeForWidth:(CGFloat)width completion:(ZJ_NEYDNativeAdAutomaticSizeCompletion)completion;
@property (nonatomic, readonly) ZJ_NEYDNativeViewSizeHandler viewSizeHandler;
- (void)adViewWillMoveToSuperview:(UIView *)superview;
- (void)nativeAdTapped;
@end

@protocol ZJ_NEYDNativeAdRendererSettings <NSObject>
@optional
@property (nonatomic, readwrite, strong) NSString* styleName;
@property (nonatomic, readwrite, copy) ZJ_NEYDNativeViewSizeHandler viewSizeHandler;
@end

@interface ZJ_NEYDStaticNativeAdRendererSettings : NSObject <ZJ_NEYDNativeAdRendererSettings>
@property (nonatomic, assign) Class renderingViewClass;
@property (nonatomic, readwrite, copy) ZJ_NEYDNativeViewSizeHandler viewSizeHandler;
@end

@interface ZJ_NEYDDAONativeVideoAdRendererSettings : NSObject <ZJ_NEYDNativeAdRendererSettings>
@property (nonatomic, assign) Class renderingViewClass;
@property (nonatomic, readwrite, copy) ZJ_NEYDNativeViewSizeHandler viewSizeHandler;
/// 是否在wifi网络下自动播放信息流视频广告,默认为YES
@property (nonatomic, assign) BOOL autoPlay;
/// 是否显示激励视频广告的关闭按钮,默认为YES
@property (nonatomic, assign) BOOL showCloseBtnForRewardVideo;
@end

//@class ZJ_NEYDStaticNativeAdRendererSettings;
@interface ZJ_NEYDStaticNativeAdRenderer : NSObject <ZJ_NEYDNativeAdRenderer>
@property (nonatomic, readonly) ZJ_NEYDNativeViewSizeHandler viewSizeHandler;
+ (ZJ_NEYDNativeAdRendererConfiguration *)rendererConfigurationWithRendererSettings:(id<ZJ_NEYDNativeAdRendererSettings>)rendererSettings andStyleName:(NSString*) styleName;
@end

@interface ZJ_NEYDDAONativeVideoAdRenderer : NSObject
@property (nonatomic, readonly) ZJ_NEYDNativeViewSizeHandler viewSizeHandler;
+ (ZJ_NEYDNativeAdRendererConfiguration *)rendererConfigurationWithRendererSettings:(id<ZJ_NEYDNativeAdRendererSettings>)rendererSettings andStyleName:(NSString*) styleName;
@end

@class CLLocation;
@interface ZJ_NEYDNativeAdRequestTargeting : NSObject
+ (ZJ_NEYDNativeAdRequestTargeting *)targeting;
@property (nonatomic, copy) NSString *keywords;
@property (nonatomic, copy) CLLocation *location;
@property (nonatomic, strong) NSSet *desiredAssets;
/// 是否上报最近展示的广告CreativeIds,默认为NO
@property (nonatomic, assign) BOOL uploadLastCreativeIds;
/// 是否支持个性化推荐广告,默认为YES
@property (nonatomic, assign) BOOL supportTargetedAd;
/// 开屏广告logo高度
@property (nonatomic, assign) CGFloat splashLogoHeight;
/// 额外参数
@property (nonatomic, strong)  NSMutableDictionary *extraParams;
@end

@class ZJ_NEYDBrowserViewController;
@protocol ZJ_NEYDBrowserViewControllerBuilderDelegate <NSObject>
- (ZJ_NEYDBrowserViewController*) buildBrowserViewControllerWithZJ_NEYDNativeAd:(ZJ_NEYDNativeAd *)ad;
@end

@protocol ZJ_NEYDBrowserControllerDelegate;
@interface ZJ_NEYDBrowserViewController : UIViewController
@property (nonatomic, copy) NSURL *landingPageURL;
@property (nonatomic, copy) NSString *HTMLString;
@property (nonatomic, weak) id<ZJ_NEYDBrowserControllerDelegate> delegate;
@end

@interface ZJ_NEYDConvTracker : NSObject
+ (instancetype) convTrackerForAd:(ZJ_NEYDNativeAd *)ad;
- (void) startLoadAdWithWebView:(WKWebView *)webView;
- (void) finishLoadAdWithWebView:(WKWebView *)webView;
- (void) sendTrackerData:(NSURLRequest *)request;
- (void) closeWebView;
@end

@protocol ZJ_NEYDBrowserControllerDelegate <NSObject>
- (void)dismissBrowserController:(ZJ_NEYDBrowserViewController *)browserController animated:(BOOL)animated;
@end
@class ZJ_NEYDNativeAdRequestTargeting;
@protocol ZJ_NEYDTableViewAdPlacerDelegate;
@protocol ZJ_NEYDBrowserViewControllerBuilderDelegate;

@interface ZJ_NEYDAdPositioning : NSObject <NSCopying>
@property (nonatomic, assign) NSUInteger repeatingInterval;
@property (nonatomic, strong, readonly) NSMutableOrderedSet *fixedPositions;
@end

@interface ZJ_NEYDClientAdPositioning : ZJ_NEYDAdPositioning
+ (instancetype)positioning;
- (void)addFixedIndexPath:(NSIndexPath *)indexPath;
- (void)enableRepeatingPositionsWithInterval:(NSUInteger)interval;
@end

@interface ZJ_NEYDServerAdPositioning : ZJ_NEYDAdPositioning
+ (instancetype)positioning;
@end

@interface ZJ_NEYDTableViewAdPlacer : NSObject
@property (nonatomic, weak) id<ZJ_NEYDTableViewAdPlacerDelegate> delegate;
+ (instancetype)placerWithTableView:(UITableView *)tableView viewController:(UIViewController *)controller rendererConfigurations:(NSArray *)rendererConfigurations withBrowserViewControllerBuilderDelegate:(id<ZJ_NEYDBrowserViewControllerBuilderDelegate>)browserViewControllerBuilderDelegate;
+ (instancetype)placerWithTableView:(UITableView *)tableView viewController:(UIViewController *)controller adPositioning:(ZJ_NEYDAdPositioning *)positioning rendererConfigurations:(NSArray *)rendererConfigurations withBrowserViewControllerBuilderDelegate:(id<ZJ_NEYDBrowserViewControllerBuilderDelegate>)browserViewControllerBuilderDelegate;
- (void)loadAdsForAdUnitID:(NSString *)adUnitID;
- (void)loadAdsForAdUnitID:(NSString *)adUnitID targeting:(ZJ_NEYDNativeAdRequestTargeting *)targeting;
- (void)loadAdsForAdUnitID:(NSString *)adUnitID targeting:(ZJ_NEYDNativeAdRequestTargeting *)targeting adNet:(NSString *)adNet;
@end

@interface UITableView (ZJ_NEYDTableViewAdPlacer)
- (void)zj_neyd_setAdPlacer:(ZJ_NEYDTableViewAdPlacer *)placer;
- (ZJ_NEYDTableViewAdPlacer *)zj_neyd_adPlacer;
- (void)zj_neyd_setDataSource:(id<UITableViewDataSource>)dataSource;
- (id<UITableViewDataSource>)zj_neyd_dataSource;
- (void)zj_neyd_setDelegate:(id<UITableViewDelegate>)delegate;
- (id<UITableViewDelegate>)zj_neyd_delegate;
- (void)zj_neyd_beginUpdates;
- (void)zj_neyd_endUpdates;
- (void)zj_neyd_reloadData;
- (void)zj_neyd_insertRowsAtIndexPaths:(NSArray *)indexPaths withRowAnimation:(UITableViewRowAnimation)animation;
- (void)zj_neyd_deleteRowsAtIndexPaths:(NSArray *)indexPaths withRowAnimation:(UITableViewRowAnimation)animation;
- (void)zj_neyd_reloadRowsAtIndexPaths:(NSArray *)indexPaths withRowAnimation:(UITableViewRowAnimation)animation;
- (void)zj_neyd_moveRowAtIndexPath:(NSIndexPath *)indexPath toIndexPath:(NSIndexPath *)newIndexPath;
- (void)zj_neyd_insertSections:(NSIndexSet *)sections withRowAnimation:(UITableViewRowAnimation)animation;
- (void)zj_neyd_deleteSections:(NSIndexSet *)sections withRowAnimation:(UITableViewRowAnimation)animation;
- (void)zj_neyd_reloadSections:(NSIndexSet *)sections withRowAnimation:(UITableViewRowAnimation)animation;
- (void)zj_neyd_moveSection:(NSInteger)section toSection:(NSInteger)newSection;
- (UITableViewCell *)zj_neyd_cellForRowAtIndexPath:(NSIndexPath *)indexPath;
- (id)zj_neyd_dequeueReusableCellWithIdentifier:(NSString *)identifier forIndexPath:(NSIndexPath *)indexPath;
- (void)zj_neyd_deselectRowAtIndexPath:(NSIndexPath *)indexPath animated:(BOOL)animated;
- (NSIndexPath *)zj_neyd_indexPathForCell:(UITableViewCell *)cell;
- (NSIndexPath *)zj_neyd_indexPathForRowAtPoint:(CGPoint)point;
- (NSIndexPath *)zj_neyd_indexPathForSelectedRow;
- (NSArray *)zj_neyd_indexPathsForRowsInRect:(CGRect)rect;
- (NSArray *)zj_neyd_indexPathsForSelectedRows;
- (NSArray *)zj_neyd_indexPathsForVisibleRows;
- (CGRect)zj_neyd_rectForRowAtIndexPath:(NSIndexPath *)indexPath;
- (void)zj_neyd_scrollToRowAtIndexPath:(NSIndexPath *)indexPath atScrollPosition:(UITableViewScrollPosition)scrollPosition animated:(BOOL)animated;
- (void)zj_neyd_selectRowAtIndexPath:(NSIndexPath *)indexPath animated:(BOOL)animated scrollPosition:(UITableViewScrollPosition)scrollPosition;
- (NSArray *)zj_neyd_visibleCells;
@end

@protocol ZJ_NEYDTableViewAdPlacerDelegate <NSObject>
@optional
-(void)nativeAdWillPresentModalForTableViewAdPlacer:(ZJ_NEYDTableViewAdPlacer *)placer;
-(void)nativeAdDidDismissModalForTableViewAdPlacer:(ZJ_NEYDTableViewAdPlacer *)placer;
-(void)nativeAdWillLeaveApplicationFromTableViewAdPlacer:(ZJ_NEYDTableViewAdPlacer *)placer;
@end

@protocol ZJ_NEYDCollectionViewAdPlacerDelegate;

@interface ZJ_NEYDCollectionViewAdPlacer : NSObject
@property (nonatomic, weak) id<ZJ_NEYDCollectionViewAdPlacerDelegate> delegate;
+ (instancetype)placerWithCollectionView:(UICollectionView *)collectionView viewController:(UIViewController *)controller rendererConfigurations:(NSArray *)rendererConfigurations  withBrowserViewControllerBuilderDelegate:(id<ZJ_NEYDBrowserViewControllerBuilderDelegate>)browserViewControllerBuilderDelegate;
+ (instancetype)placerWithCollectionView:(UICollectionView *)collectionView viewController:(UIViewController *)controller adPositioning:(ZJ_NEYDAdPositioning *)positioning rendererConfigurations:(NSArray *)rendererConfigurations  withBrowserViewControllerBuilderDelegate:(id<ZJ_NEYDBrowserViewControllerBuilderDelegate>)browserViewControllerBuilderDelegate;
- (void)loadAdsForAdUnitID:(NSString *)adUnitID;
- (void)loadAdsForAdUnitID:(NSString *)adUnitID targeting:(ZJ_NEYDNativeAdRequestTargeting *)targeting;
- (void)loadAdsForAdUnitID:(NSString *)adUnitID targeting:(ZJ_NEYDNativeAdRequestTargeting *)targeting adNet:(NSString *)adNet;
@end

@interface UICollectionView (ZJ_NEYDCollectionViewAdPlacer)
- (void)zj_neyd_setAdPlacer:(ZJ_NEYDCollectionViewAdPlacer *)placer;
- (ZJ_NEYDCollectionViewAdPlacer *)zj_neyd_adPlacer;
- (void)zj_neyd_setDataSource:(id<UICollectionViewDataSource>)dataSource;
- (id<UICollectionViewDataSource>)zj_neyd_dataSource;
- (void)zj_neyd_setDelegate:(id<UICollectionViewDelegate>)delegate;
- (id<UICollectionViewDelegate>)zj_neyd_delegate;
- (void)zj_neyd_reloadData;
- (void)zj_neyd_insertItemsAtIndexPaths:(NSArray *)indexPaths;
- (void)zj_neyd_deleteItemsAtIndexPaths:(NSArray *)indexPaths;
- (void)zj_neyd_reloadItemsAtIndexPaths:(NSArray *)indexPaths;
- (void)zj_neyd_moveItemAtIndexPath:(NSIndexPath *)indexPath toIndexPath:(NSIndexPath *)newIndexPath;
- (void)zj_neyd_insertSections:(NSIndexSet *)sections;
- (void)zj_neyd_deleteSections:(NSIndexSet *)sections;
- (void)zj_neyd_reloadSections:(NSIndexSet *)sections;
- (void)zj_neyd_moveSection:(NSInteger)section toSection:(NSInteger)newSection;
- (UICollectionViewCell *)zj_neyd_cellForItemAtIndexPath:(NSIndexPath *)indexPath;
- (id)zj_neyd_dequeueReusableCellWithReuseIdentifier:(NSString *)identifier forIndexPath:(NSIndexPath*)indexPath;
- (void)zj_neyd_deselectItemAtIndexPath:(NSIndexPath *)indexPath animated:(BOOL)animated;
- (NSIndexPath *)zj_neyd_indexPathForCell:(UICollectionViewCell *)cell;
- (NSIndexPath *)zj_neyd_indexPathForItemAtPoint:(CGPoint)point;
- (NSArray *)zj_neyd_indexPathsForSelectedItems;
- (NSArray *)zj_neyd_indexPathsForVisibleItems;
- (UICollectionViewLayoutAttributes *)zj_neyd_layoutAttributesForItemAtIndexPath:(NSIndexPath *)indexPath;
- (void)zj_neyd_scrollToItemAtIndexPath:(NSIndexPath *)indexPath atScrollPosition:(UICollectionViewScrollPosition)scrollPosition animated:(BOOL)animated;
- (void)zj_neyd_selectItemAtIndexPath:(NSIndexPath *)indexPath animated:(BOOL)animated scrollPosition:(UICollectionViewScrollPosition)scrollPosition;
- (NSArray *)zj_neyd_visibleCells;
@end

@protocol ZJ_NEYDCollectionViewAdPlacerDelegate <NSObject>
@optional
-(void)nativeAdWillPresentModalForCollectionViewAdPlacer:(ZJ_NEYDCollectionViewAdPlacer *)placer;
-(void)nativeAdDidDismissModalForCollectionViewAdPlacer:(ZJ_NEYDCollectionViewAdPlacer *)placer;
-(void)nativeAdWillLeaveApplicationFromCollectionViewAdPlacer:(ZJ_NEYDCollectionViewAdPlacer *)placer;
@end

@class ZJ_NEYDNativeCustomEvent;

@protocol ZJ_NEYDNativeCustomEventDelegate <NSObject>
- (void)nativeCustomEvent:(ZJ_NEYDNativeCustomEvent *)event didLoadAd:(ZJ_NEYDNativeAd *)adObject;
- (void)nativeCustomEvent:(ZJ_NEYDNativeCustomEvent *)event didFailToLoadAdWithError:(NSError *)error;
@end

@interface ZJ_NEYDNativeCustomEvent : NSObject
- (void)requestAdWithCustomEventInfo:(NSDictionary *)info;
- (void)precacheImagesWithURLs:(NSArray *)imageURLs completionBlock:(void (^)(NSArray *errors))completionBlock;
@property (nonatomic, weak) id<ZJ_NEYDNativeCustomEventDelegate> delegate;
@end

@interface ZJ_NEYDAdBrowserConversionTracker : NSObject
typedef NS_ENUM(int, ZJ_NEYDCollectType){
    zj_neyd_adRequest = 0,
    zj_neyd_adRequestSuc = 1,
    zj_neyd_adRequestFail = 2,
    zj_neyd_adImpTrack = 3,
    zj_neyd_adClkTrack = 4,
};
@property (nonatomic, copy) NSString *url;
@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *creativeId;
@property (nonatomic, copy) NSString *slotId;
@property (nonatomic, copy) NSString *thirdSlotId;
@property (nonatomic, copy) NSString *idfa;
@property (nonatomic, assign) NSInteger errorCode;
@property (nonatomic, copy) NSString *errorMessage;
@property (nonatomic, copy) NSString *thirdName;
@property (nonatomic, assign) long seq;
@property (nonatomic, copy) NSString *formData;
@property (nonatomic, assign) NSTimeInterval hoverTime;
@property (nonatomic, copy) NSString *bidId;
@property (nonatomic, assign) NSTimeInterval loadingTime;
@property (nonatomic, assign) NSTimeInterval prepareTime;
@property (nonatomic, assign) NSTimeInterval startProgressTime;
- (id)initWithSlotId:(NSString *)slotId title:(NSString *)title thirdSlotId:(NSString *)thirdSlotId;
- (id)initWithCid:(NSString *)cid;
- (void) sendCollectDataWithType:(int)ZJ_NEYDCollectType;
- (void) sendConversionData;
- (void) sendVideoConversionDataType:(int)type pd:(int)pdTime dura:(int)duraTime videoUrl:(NSURL *)url ld:(int)ld full:(int)full;
@end

@interface ZJ_NEYDAdTestMode : NSObject
+ (BOOL)isTesting;
+ (void)turnOn;
+ (void)turnOff;
+ (void)useEncryption;
+ (void)disableEncryption;
@end

@interface ZJ_NEYDSplashAdCheckValiadRequest : NSObject

@property (nonatomic, copy) NSArray *groupIds;

@property (nonatomic, copy) NSString *urlStr;

- (void)requestWithSuccessBlock:(void (^)(NSArray * _Nullable groupIds))successBlock failBlock:(dispatch_block_t)failBlock;
@end

typedef enum
{
    ZJ_NEYDLogLevelAll = 0,
    ZJ_NEYDLogLevelTrace = 10,
    ZJ_NEYDLogLevelDebug = 20,
    ZJ_NEYDLogLevelInfo = 30,
    ZJ_NEYDLogLevelWarn = 40,
    ZJ_NEYDLogLevelError = 50,
    ZJ_NEYDLogLevelFatal = 60,
    ZJ_NEYDLogLevelOff = 70
} ZJ_NEYDLogLevel;

ZJ_NEYDLogLevel ZJ_NEYDLogGetLevel(void);
void ZJ_NEYDLogSetLevel(ZJ_NEYDLogLevel level);
void _ZJ_NEYDLogTrace(NSString *format, ...);
void _ZJ_NEYDLogDebug(NSString *format, ...);
void _ZJ_NEYDLogInfo(NSString *format, ...);
void _ZJ_NEYDLogWarn(NSString *format, ...);
void _ZJ_NEYDLogError(NSString *format, ...);
void _ZJ_NEYDLogFatal(NSString *format, ...);
#if ZJ_NEYD_DEBUG_MODE && !SPECS

#define ZJ_NEYDLogTrace(...) _ZJ_NEYDLogTrace(__VA_ARGS__)
#define ZJ_NEYDLogDebug(...) _ZJ_NEYDLogDebug(__VA_ARGS__)
#define ZJ_NEYDLogInfo(...) _ZJ_NEYDLogInfo(__VA_ARGS__)
#define ZJ_NEYDLogWarn(...) _ZJ_NEYDLogWarn(__VA_ARGS__)
#define ZJ_NEYDLogError(...) _ZJ_NEYDLogError(__VA_ARGS__)
#define ZJ_NEYDLogFatal(...) _ZJ_NEYDLogFatal(__VA_ARGS__)

#else

#define ZJ_NEYDLogTrace(...) {}
#define ZJ_NEYDLogDebug(...) {}
#define ZJ_NEYDLogInfo(...) {}
#define ZJ_NEYDLogWarn(...) {}
#define ZJ_NEYDLogError(...) {}
#define ZJ_NEYDLogFatal(...) {}

#endif

typedef enum ZJ_NEYDNativeAdErrorCode {
    ZJ_NEYDNativeAdErrorUnknown = -1,
    ZJ_NEYDNativeAdErrorHTTPError = -1000,
    ZJ_NEYDNativeAdErrorInvalidServerResponse = -1001,
    ZJ_NEYDNativeAdErrorNoInventory = -1002,
    ZJ_NEYDNativeAdErrorImageDownloadFailed = -1003,
    ZJ_NEYDNativeAdErrorAdUnitWarmingUp = -1004,
    ZJ_NEYDNativeAdErrorVASTParsingFailed = -1005,
    ZJ_NEYDNativeAdErrorVideoConfigInvalid = -1006,
    ZJ_NEYDNativeAdErrorFacebookAdError = -1007,
    ZJ_NEYDNativeAdErrorContentDisplayError = -1100,
    ZJ_NEYDNativeAdErrorRenderError = -1200
} ZJ_NEYDNativeAdErrorCode;

extern NSString * const Zj_neydDaoNativeAdsSDKDomain;

NSError *ZJ_NEYDNativeAdNSErrorForInvalidAdServerResponse(NSString *reason);
NSError *ZJ_NEYDNativeAdNSErrorForAdUnitWarmingUp();
NSError *ZJ_NEYDNativeAdNSErrorForNoInventory();
NSError *ZJ_NEYDNativeAdNSErrorForNetworkConnectionError();
NSError *ZJ_NEYDNativeAdNSErrorForInvalidImageURL();
NSError *ZJ_NEYDNativeAdNSErrorForImageDownloadFailure();
NSError *ZJ_NEYDNativeAdNSErrorForContentDisplayErrorMissingRootController();
NSError *ZJ_NEYDNativeAdNSErrorForContentDisplayErrorInvalidURL();
NSError *ZJ_NEYDNativeAdNSErrorForVASTParsingFailure();
NSError *ZJ_NEYDNativeAdNSErrorForVideoConfigInvalid();
NSError *ZJ_NEYDNativeAdNSErrorForRenderValueTypeError();
NSError *ZJ_NEYDNativeAdNSErrorForFacebookAdError(NSString *fbErrorDesc);


/// 广告不能展示原因
typedef enum : NSUInteger {
    /// 未知错误
    ZJ_NEYDSplashAdShowFailTypeUnknown = 0,
    
    /// 跳转异常
    ZJ_NEYDSplashAdShowFailTypeUnjump,
    
    /// 展示异常
    ZJ_NEYDSplashAdShowFailTypeUnshow,
    
    /// 下载异常
    ZJ_NEYDSplashAdShowFailTypeUndownload,
} ZJ_NEYDSplashAdShowFailType;

@interface ZJ_NEYDSplashAdShowFailInfo : NSObject

@property (nonatomic, copy) NSString *slotId;  //required - 广告位id
@property (nonatomic, copy) NSString *advId;  //required - 广告变体id
@property (nonatomic, copy) NSString *url;  //required - 异常链接
@property (nonatomic, assign) ZJ_NEYDSplashAdShowFailType abnormalType;   //required - 异常类型

- (instancetype)initWithSlotId:(NSString *)slotId advId:(NSString *)advId url:(NSString *)url abnormalType:(ZJ_NEYDSplashAdShowFailType)abnormalType;

@end

@interface ZJ_NEYDSplashAdShowFailReport : NSObject

/// 展示失败的异常上报
+ (void)trackSplashAdShowFailWithInfoArray:(NSArray <ZJ_NEYDSplashAdShowFailInfo *> *)infoArray;

@end
