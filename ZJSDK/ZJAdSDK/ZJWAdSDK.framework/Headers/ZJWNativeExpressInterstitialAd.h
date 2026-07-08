//
//  ZJWNativeExpressInterstitialAd.h
//  ZJWAdSDK
//
//  Created by admin on 2021/1/21.
//

#import <UIKit/UIKit.h>
#import <ZJWAdSDK/ZJWSourceAdType.h>
#import <ZJWAdSDK/ZJWBidReason.h>
#import <ZJWAdSDK/ZJWAdMaterial.h>
#import <ZJWAdSDK/ZJWAdSlot.h>

@class ZJWNativeExpressInterstitialAd;

NS_ASSUME_NONNULL_BEGIN

@protocol ZJWNativeExpressInterstitialAdDelegate <NSObject>

- (void)zjW_nativeExpresInterstitialAdDidLoad:(ZJWNativeExpressInterstitialAd *)interstitialAd;

- (void)zjW_nativeExpresInterstitialAd:(ZJWNativeExpressInterstitialAd *)interstitialAd didFailWithError:(NSError * __nullable)error;

- (void)zjW_nativeExpresInterstitialAdWillVisible:(ZJWNativeExpressInterstitialAd *)interstitialAd;

- (void)zjW_nativeExpresInterstitialAdDidClick:(ZJWNativeExpressInterstitialAd *)interstitialAd;

- (void)zjW_nativeExpresInterstitialAdDidClose:(ZJWNativeExpressInterstitialAd *)interstitialAd;

- (void)zjW_nativeExpresInterstitialAdDidCloseOtherController:(ZJWNativeExpressInterstitialAd *)interstitialAd;

- (void)zjW_nativeExpresInterstitialAdDisplayFail:(ZJWNativeExpressInterstitialAd *)interstitialAd error:(NSError *)error;

@end

@interface ZJWNativeExpressInterstitialAd : NSObject

@property(nonatomic,weak)id<ZJWNativeExpressInterstitialAdDelegate> delegate;

/// 单位分
@property(nonatomic,assign)NSInteger ecpm;

/// 广告id
@property(nonatomic,copy,readonly)NSString *placementId;

/// 消耗方类型
@property(nonatomic,assign)ZJWAdSourceType sourceType;

/// 广告是否有效（展示前请务必判断）
/// 如不严格按照此方法对接，将导致因曝光延迟时间造成的双方消耗gap过大，请开发人员谨慎对接
@property(nonatomic,assign,readonly)BOOL isReady;

/// 点击后是否关闭广告 zjWf 消耗方有效
@property(nonatomic,assign)BOOL closeAfterClick;

/// 广告素材 可能为空
@property(nullable,nonatomic,strong)ZJWAdMaterial *adMaterial;

/// 广告底价，单位分，不会返回低于此底价的广告，底价过高可能会没有广告，兜底返回错误提示：广告价格低于底价！
@property(nonatomic,assign)NSInteger basePrice;

/// 广告请求ID,不要在loadAd后立即去取。
@property(nonatomic,copy)NSString *adRequestID;

/// 禁止使用此方法来初始化
+ (instancetype)new NS_UNAVAILABLE;

/// 禁止使用此方法来初始化
- (instancetype)init NS_UNAVAILABLE;

///  初始化 
/// @param placementId 广告id
- (instancetype)initWithPlacementId:(nonnull NSString *)placementId NS_DESIGNATED_INITIALIZER;

/// 加载广告
- (void)loadAd;

/// 展示插屏广告
/// @param controller 控制器 一般为当前控制器 或者栈顶控制器
- (void)showAdFromRootViewController:(UIViewController *)controller;

/// 主动关闭插屏 当前只支持zjWf 消耗方
- (void)closureInterstitialAd;

/// 通知广告平台的广告竞胜
///  @param costPrice 竞胜价格
///  @param secondPrice 二价
- (void)notifyBidWin:(double)costPrice secondPrice:(double)secondPrice;
/// 通知广告平台的广告竞败
/// @param bidLossReason 竞败原因
- (void)notifyBidLoss:(ZJWBidReason *)bidLossReason;

/// 下面的接口仅用于服务器bidding的初始化
#pragma mark - service bid -
/// 初始化
/// ZJWAdSlot 广告id
- (instancetype)initWithSlot:(ZJWAdSlot *)slot NS_DESIGNATED_INITIALIZER;

/// 获取bidging token
/// 通过initWithSlot方法构造后，获取biddingToken 并请求adx 获取adm
- (nullable NSString *)biddingToken;

///  获取到adm数据后调用，Adm赋值调⽤后⽆需调⽤load⽅法，直接在相关回调⾥等候响应即可
- (void)setMopubAdMarkUp:(NSString *)adm;

@end

NS_ASSUME_NONNULL_END
