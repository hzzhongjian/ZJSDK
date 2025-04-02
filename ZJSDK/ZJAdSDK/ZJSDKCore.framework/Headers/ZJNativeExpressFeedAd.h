//
//  ZJNativeExpressFeedAd.h
//  ZJSDKCore
//
//  Created by Rare on 2021/3/2.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <ZJSDKCore/ZJAdEventReport.h>
#import <ZJSDKCore/ZJStrategyManager.h>
#import <ZJSDKCore/ZJSDKManager.h>

NS_ASSUME_NONNULL_BEGIN

@class ZJNativeExpressFeedAd;

@protocol ZJNativeExpressFeedAdDelegate <NSObject>

@optional
/**
 * 广告渲染成功
 */
- (void)ZJ_nativeExpressFeedAdRenderSuccess:(ZJNativeExpressFeedAd *)feedAd;
/**
 * 广告渲染失败
 */
- (void)ZJ_nativeExpressFeedAdRenderFail:(ZJNativeExpressFeedAd *)feedAd;

/**
 *广告即将展示
 */
- (void)ZJ_nativeExpressFeedAdViewWillShow:(ZJNativeExpressFeedAd *)feedAd;

/**
 *广告展示错误
 */
- (void)ZJ_nativeExpressFeedAdViewShowError:(ZJNativeExpressFeedAd *)feedAd error:(NSError *)error;

/**
 *广告点击
 */
- (void)ZJ_nativeExpressFeedAdDidClick:(ZJNativeExpressFeedAd *)feedAd;
/**
 *不喜欢该广告
 */
- (void)ZJ_nativeExpressFeedAdDislike:(ZJNativeExpressFeedAd *)feedAd;
/**
 *展示落地页
 */
- (void)ZJ_nativeExpressFeedAdDidShowOtherController:(ZJNativeExpressFeedAd *)nativeAd;
/**
 *关闭落地页
 */
- (void)ZJ_nativeExpressFeedAdDidCloseOtherController:(ZJNativeExpressFeedAd *)nativeAd;

@end


@interface ZJNativeExpressFeedAd : NSObject

@property (nonatomic,strong,readonly) UIView *feedView;

@property (nonatomic)BOOL hasShown;

/**
 * Whether render is ready
 */
@property (nonatomic, assign, readonly) BOOL isReady;

@property (nonatomic, copy) NSString *adId;

@property (nonatomic, copy) NSString *zj_adID;

@property (nonatomic, copy) NSString *platform;

@property (nonatomic, strong) ZJAdUnitModel *config;

@property (nonatomic, assign) ZJAdPlatformType platformType;

@property(nonatomic, weak) id<ZJNativeExpressFeedAdDelegate> delegate;

/*
 *required.[必选]
 * root view controller for handling ad actions.
 * 详解：开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
 */
@property (nonatomic, weak) UIViewController *rootViewController;

/*
 *required [必选]
 *原生模板广告渲染
 */
- (void)render;


- (void)reportErrorEvent:(nonnull NSError *)supplementError;

#pragma mark - 事件上报
- (void)reportWithEvent:(ZJEventString)event supplementMsg:(nullable NSString *)supplementMsg;

/**
 * 返回广告的eCPM，广告加载成功后调用有效，单位：分
 * @return 成功返回一个大于等于0的值，
 */
- (NSInteger)eCPM;


// 广告是否有效，一般广告从加载到展示，默认30分钟的有效期，过了有效期请重新加载广告
- (BOOL)pmAdValid;

@end

NS_ASSUME_NONNULL_END
