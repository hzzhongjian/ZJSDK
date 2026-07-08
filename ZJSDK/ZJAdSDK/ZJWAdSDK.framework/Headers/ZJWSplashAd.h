//
//  ZJWSplashAd.h
//  ZJWAdSDK
//
//  Created by admin on 2021/1/13.
//

#import <UIKit/UIKit.h>
#import <ZJWAdSDK/ZJWSourceAdType.h>
#import <ZJWAdSDK/ZJWBidReason.h>
#import <ZJWAdSDK/ZJWAdMaterial.h>
#import <ZJWAdSDK/ZJWAdSlot.h>


@class ZJWSplashAd;

NS_ASSUME_NONNULL_BEGIN

@protocol ZJWSplashAdDelegate <NSObject>
@optional
/// 开屏加载成功
- (void)zjW_splashAdDidLoad:(ZJWSplashAd *)splashAd;

/// 开屏加载失败
- (void)zjW_splashAd:(ZJWSplashAd *)splashAd didFailWithError:(NSError * _Nullable)error;

/// 开屏素材加载成功
- (void)zjW_splashAdMaterialDidLoad:(ZJWSplashAd *)splashAd;

/// 开屏素材加载失败
- (void)zjW_splashAdMaterial:(ZJWSplashAd *)splashAd didFailWithError:(NSError * _Nullable)error;

/// 开屏广告被点击了
- (void)zjW_splashAdDidClick:(ZJWSplashAd *)splashAd;

/// 开屏广告关闭了
- (void)zjW_splashAdDidClose:(ZJWSplashAd *)splashAd;

/// 开屏广告详情页关闭 落地页关闭
- (void)zjW_splashAdDetailDidClose:(ZJWSplashAd *)splashAd;
 
/// 开屏广告详情页展示
- (void)zjW_splashAdDetailShow:(ZJWSplashAd *)splashAd;

///  开屏广告将要展示
- (void)zjW_splashAdWillVisible:(ZJWSplashAd *)splashAd;

///  开屏广告展示失败
- (void)zjW_splashAdVisibleError:(ZJWSplashAd *)splashAd error:(NSError * _Nullable)error;

@end

@interface ZJWSplashAd : NSObject

/// buttomView  底部视图 可为空
@property(nonatomic,strong)UIView *bottomView;

/// 是否隐藏跳过按钮 默认NO
@property(nonatomic,assign)BOOL hideSkipButton;

/// 根控制器 广告加载的根控制器 需要传入当前的栈顶可见的控制器
@property(nonatomic, weak)UIViewController *rootViewController;

/// 广告id
@property(nonatomic,copy,readonly)NSString *placementId;

/// 开屏广告代理
@property(nonatomic,weak)id<ZJWSplashAdDelegate> delegate;

/// 消耗方类型
@property(nonatomic,assign)ZJWAdSourceType sourceType;

/// 广告素材 可能为空
@property(nullable,nonatomic,strong)ZJWAdMaterial *adMaterial;

/// 广告是否有效（展示前请务必判断）
/// 如不严格按照此方法对接，将导致因曝光延迟时间造成的双方消耗gap过大，请开发人员谨慎对接
@property(nonatomic,assign,readonly)BOOL isReady;

///  素材是否加载成功
@property(nonatomic,assign,readonly)BOOL isMaterialLoaded;

/// 广告ecpm 单位分
@property(nonatomic,assign,readonly)NSInteger ecpm;

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

/// 展示广告
- (void)showAdWithViewController:(UIViewController *)viewController;

/// 展示广告并传入bottomview  传入的bottomiview 会覆盖 bottomView 属性的值
- (void)showAdWithViewController:(UIViewController *)viewController bottomView:(UIView *)bottomView;

/// 销毁广告
- (void)destory;

/// 通知广告平台的广告竞胜
///  @param costPrice 竞胜价格
///  @param secondPrice 二价
- (void)notifyBidWin:(double)costPrice secondPrice:(double)secondPrice;
/// 通知广告平台的广告竞败
/// @param bidLossReason 竞败原因
- (void)notifyBidLoss:(ZJWBidReason *)bidLossReason;

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
