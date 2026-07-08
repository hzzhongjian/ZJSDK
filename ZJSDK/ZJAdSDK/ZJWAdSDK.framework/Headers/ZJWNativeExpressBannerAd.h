//
//  ZJWNativeExpressBannerAd.h
//  ZJWAdSDK
//
//  Created by admin on 2021/1/25.
//

#import <UIKit/UIKit.h>
#import <ZJWAdSDK/ZJWSourceAdType.h>
#import <ZJWAdSDK/ZJWBidReason.h>
#import <ZJWAdSDK/ZJWAdMaterial.h>
#import <ZJWAdSDK/ZJWAdSlot.h>

@class ZJWNativeExpressBannerAd;

NS_ASSUME_NONNULL_BEGIN

@protocol ZJWNativeExpressBannerAdDelegate <NSObject>
@optional

///  广告加载成功
///  在此方法中调用 showAdFromView:frame 方法
- (void)zjW_nativeExpressBannerAdDidLoad:(ZJWNativeExpressBannerAd *)bannerAd;

/// 广告加载失败
- (void)zjW_nativeExpressBannerAd:(ZJWNativeExpressBannerAd *)bannerAd didLoadFailWithError:(NSError *_Nullable)error;

/// 广告将要曝光
- (void)zjW_nativeExpressBannerAdWillBecomVisible:(ZJWNativeExpressBannerAd *)bannerAd;

/// 广告曝光失败
- (void)zjW_nativeExpressBannerAdBecomVisibleFail:(ZJWNativeExpressBannerAd *)bannerAd error:(NSError *_Nullable)error;

/// 广告被点击
- (void)zjW_nativeExpressBannerAdDidClick:(ZJWNativeExpressBannerAd *)bannerAd;
 
/// 广告被关闭
- (void)zjW_nativeExpressBannerAdClosed:(ZJWNativeExpressBannerAd *)bannerAd;

/// 广告详情页给关闭
- (void)zjW_nativeExpressBannerAdViewDidCloseOtherController:(ZJWNativeExpressBannerAd *)bannerAd;

@end

@interface ZJWNativeExpressBannerAd : NSObject

/// 广告id
@property(nonatomic,copy,readonly)NSString *placementId;

/// 广告的实际size 
@property(nonatomic,assign,readonly)CGSize realSize;

/// 【必选参数】 广告的代理
@property(nonatomic,weak)id<ZJWNativeExpressBannerAdDelegate> delegate;

/// 【必选参数】根控制器 一般为当前控制器
@property(nonatomic,weak)UIViewController *rootViewController;

/// 消耗方类型
@property(nonatomic,assign)ZJWAdSourceType sourceType;

/// ecpm 单位分
@property(nonatomic,assign,readonly)NSInteger ecpm;

/// 广告是否有效（展示前请务必判断）
/// 如不严格按照此方法对接，将导致因曝光延迟时间造成的双方消耗gap过大，请开发人员谨慎对接
@property(nonatomic,assign,readonly)BOOL isReady;

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
/// 支持的广告位宽高比：2:1、3:2、6:5、30:13、20:3、4:1、6.4:1、345:194、161 : 70共9个尺寸，开发者按照展示场景进行勾选。创建好的尺寸不支持修改
- (instancetype)initWithPlacementId:(nonnull NSString *)placementId size:(CGSize)size NS_DESIGNATED_INITIALIZER;

/// 加载广告
- (void)loadAd;

/// 展示广告 此处传入的frame 此处frame的size 应该与初始化时传入的size一致
- (void)showAdFromView:(UIView *)view frame:(CGRect)frame;

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
- (instancetype)initWithSlot:(ZJWAdSlot *)slot size:(CGSize)size NS_DESIGNATED_INITIALIZER;

/// 获取bidging token
/// 通过initWithSlot方法构造后，获取biddingToken 并请求adx 获取adm
- (nullable NSString *)biddingToken;

///  获取到adm数据后调用，Adm赋值调⽤后⽆需调⽤load⽅法，直接在相关回调⾥等候响应即可
- (void)setMopubAdMarkUp:(NSString *)adm;

@end

NS_ASSUME_NONNULL_END
