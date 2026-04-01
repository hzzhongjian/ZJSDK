//
//  ZJ_SSFWSplashAd.h
//  ZJ_SSFWAdSDK
//
//  Created by admin on 2021/1/13.
//

#import <UIKit/UIKit.h>
#import <ZJ_SSFWAdSDK/ZJ_SSFWSourceAdType.h>
#import <ZJ_SSFWAdSDK/ZJ_SSFWBidReason.h>
#import <ZJ_SSFWAdSDK/ZJ_SSFWAdMaterial.h>
@class ZJ_SSFWSplashAd;

NS_ASSUME_NONNULL_BEGIN

@protocol ZJ_SSFWSplashAdDelegate <NSObject>
@optional
/// 开屏加载成功
- (void)zj_SSFW_splashAdDidLoad:(ZJ_SSFWSplashAd *)splashAd;

/// 开屏加载失败
- (void)zj_SSFW_splashAd:(ZJ_SSFWSplashAd *)splashAd didFailWithError:(NSError * _Nullable)error;

/// 开屏素材加载成功
- (void)zj_SSFW_splashAdMaterialDidLoad:(ZJ_SSFWSplashAd *)splashAd;

/// 开屏素材加载失败
- (void)zj_SSFW_splashAdMaterial:(ZJ_SSFWSplashAd *)splashAd didFailWithError:(NSError * _Nullable)error;

/// 开屏广告被点击了
- (void)zj_SSFW_splashAdDidClick:(ZJ_SSFWSplashAd *)splashAd;

/// 开屏广告关闭了
- (void)zj_SSFW_splashAdDidClose:(ZJ_SSFWSplashAd *)splashAd;

/// 开屏广告详情页关闭 落地页关闭
- (void)zj_SSFW_splashAdDetailDidClose:(ZJ_SSFWSplashAd *)splashAd;
 
/// 开屏广告详情页展示
- (void)zj_SSFW_splashAdDetailShow:(ZJ_SSFWSplashAd *)splashAd;

///  开屏广告将要展示
- (void)zj_SSFW_splashAdWillVisible:(ZJ_SSFWSplashAd *)splashAd;

///  开屏广告展示失败
- (void)zj_SSFW_splashAdVisibleError:(ZJ_SSFWSplashAd *)splashAd error:(NSError * _Nullable)error;

@end

@interface ZJ_SSFWSplashAd : NSObject

/// buttomView  底部视图 可为空
@property(nonatomic,strong)UIView *bottomView;

/// 是否隐藏跳过按钮 默认NO
@property(nonatomic,assign)BOOL hideSkipButton;

/// 根控制器 广告加载的根控制器 需要传入当前的栈顶可见的控制器
@property(nonatomic, weak)UIViewController *rootViewController;

/// 广告id
@property(nonatomic,copy,readonly)NSString *placementId;

/// 开屏广告代理
@property(nonatomic,weak)id<ZJ_SSFWSplashAdDelegate> delegate;

/// 消耗方类型
@property(nonatomic,assign)ZJ_SSFWAdSourceType sourceType;

/// 广告素材 可能为空
@property(nullable,nonatomic,strong)ZJ_SSFWAdMaterial *adMaterial;

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
- (void)notifyBidLoss:(ZJ_SSFWBidReason *)bidLossReason;

@end

NS_ASSUME_NONNULL_END
