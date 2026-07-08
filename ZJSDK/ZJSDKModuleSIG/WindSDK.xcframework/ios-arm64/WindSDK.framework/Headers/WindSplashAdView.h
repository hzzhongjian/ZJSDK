//
//  WindSplashAdView.h
//  WindSDK
//
//  Created by Codi on 2021/11/4.
//

#import <UIKit/UIKit.h>
#import "WindBiddingProtocol.h"
#import "WindAdMetaData.h"

@class WindAdRequest;
@class WindSplashAdView;

NS_ASSUME_NONNULL_BEGIN

@protocol WindSplashAdViewDelegate <NSObject>

@optional

/// 开屏广告价值成功回调
/// - Parameter splashAdView: WindSplashAdView 实例对象
- (void)onSplashAdDidLoad:(WindSplashAdView *)splashAdView;

/// 开屏广告加载出错回调
/// - Parameters:
///   - splashAdView: WindSplashAdView 实例对象
///   - error: 具体错误信息
-(void)onSplashAdLoadFail:(WindSplashAdView *)splashAdView error:(NSError *)error;

/// 开屏广告曝光回调
/// - Parameter splashAdView: WindSplashAdView 实例对象
-(void)onSplashAdSuccessPresentScreen:(WindSplashAdView *)splashAdView;

/// 开屏广告展示失败回调
/// - Parameter splashAdView: WindSplashAdView 实例对象
/// - Parameter error: 具体错误信息
-(void)onSplashAdFailToPresent:(WindSplashAdView *)splashAdView withError:(NSError *)error;

/// 开屏广告点击回调
/// - Parameter splashAdView: WindSplashAdView 实例对象
- (void)onSplashAdClicked:(WindSplashAdView *)splashAdView;

/// 开屏广告跳过回调
/// - Parameter splashAdView: WindSplashAdView 实例对象
- (void)onSplashAdSkiped:(WindSplashAdView *)splashAdView;

/// 开屏广告关闭回调
/// - Parameter splashAdView: WindSplashAdView 实例对象
- (void)onSplashAdClosed:(WindSplashAdView *)splashAdView;

@end

@interface WindSplashAdView : UIView<WindBiddingProtocol>

/// 广告代理对象
@property (nonatomic,weak) id<WindSplashAdViewDelegate> delegate;

/// 广告位ID
@property (nonatomic,strong, readonly) NSString *placementId;

/// 广告点击依赖的ViewControoler
@property (nonatomic, weak) UIViewController *rootViewController;

/// 拉取广告超时时间，默认为5秒
@property (nonatomic, assign) int fetchDelay;

/// 广告是否有效
@property (nonatomic, getter=isAdValid, readonly) BOOL adValid;

/// 广告元数据
@property (nonatomic, strong, readonly) WindAdMetaData *metaData;


/// 构造器
/// - Parameter request: 广告请求模型，可以设置广告位ID等参数
- (instancetype)initWithRequest:(WindAdRequest *)request;

/// 加载广告
- (void)loadAdData;

/// 加载Bidding广告
/// @param bidToken bidding广告的唯一标识
- (void)loadAdDataWithBidToken:(NSString *)bidToken;

@end

NS_ASSUME_NONNULL_END
