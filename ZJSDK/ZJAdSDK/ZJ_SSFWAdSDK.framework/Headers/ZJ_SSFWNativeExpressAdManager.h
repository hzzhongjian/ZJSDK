//
//  ZJ_SSFWNativeExpressAd.h
//  ZJ_SSFWAdSDK
//
//  Created by admin on 2021/1/16.
//

#import <Foundation/Foundation.h>
#import "ZJ_SSFWNativeExpressAd.h"
#import <ZJ_SSFWAdSDK/ZJ_SSFWBidReason.h>
@class ZJ_SSFWNativeExpressAdManager;

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    ZJ_SSFWNativeExpressAdTypeDraw,  // draw视频信息流
    ZJ_SSFWNativeExpressAdTypeSelfRender, // 自渲染
    ZJ_SSFWNativeExpressAdTypeFeed,  // 普通模板信息流
    ZJ_SSFWNativeExpressAdTypeSelfRenderSplash // 自渲染开屏
} ZJ_SSFWNativeExpressAdType;


@protocol ZJ_SSFWNativeExpressAdDelegate <NSObject>
@optional;

/// 原生模版广告获取成功
/// @param manager 广告管理类
/// @param ads 广告数组 一般只会有一条广告数据 使用数组预留扩展
- (void)zj_SSFW_nativeExpressAdSuccessToLoad:(ZJ_SSFWNativeExpressAdManager *)manager ads:(NSArray<__kindof ZJ_SSFWNativeExpressAd *> *)ads;

/// 原生模版广告获取失败
/// @param manager 广告管理类
/// @param error 错误信息
- (void)zj_SSFW_nativeExpressAdFailToLoad:(ZJ_SSFWNativeExpressAdManager *)manager error:(NSError *_Nullable)error;

/// 原生模版渲染成功
/// @param nativeExpressAd 渲染成功的模板广告
- (void)zj_SSFW_nativeExpressAdRenderSuccess:(ZJ_SSFWNativeExpressAd *)nativeExpressAd;

/// 原生模版渲染失败
/// @param nativeExpressAd 渲染失败的模板广告
/// @param error 渲染过程中的错误
- (void)zj_SSFW_nativeExpressAdRenderFail:(ZJ_SSFWNativeExpressAd *)nativeExpressAd error:(NSError *_Nullable)error;

/// 原生模板将要显示
/// @param nativeExpressAd 要显示的模板广告
- (void)zj_SSFW_nativeExpressAdWillShow:(ZJ_SSFWNativeExpressAd *)nativeExpressAd;

/// 广告显示失败
/// @param nativeExpressAd 要显示的广告
- (void)zj_SSFW_nativeExpressAdShowFail:(ZJ_SSFWNativeExpressAd *)nativeExpressAd error:(NSError *_Nullable)error;

/// 原生模板将被点击了
/// @param nativeExpressAd  被点击的模板广告
- (void)zj_SSFW_nativeExpressAdDidClick:(ZJ_SSFWNativeExpressAd *)nativeExpressAd;

///  原生模板广告被关闭了
/// @param nativeExpressAd 要关闭的模板广告
- (void)zj_SSFW_nativeExpressAdViewClosed:(ZJ_SSFWNativeExpressAd *)nativeExpressAd;

/// 原生模板广告将要展示详情页
/// @param nativeExpressAd  广告
- (void)zj_SSFW_nativeExpressAdWillPresentScreen:(ZJ_SSFWNativeExpressAd *)nativeExpressAd;

/// 原生模板广告将要关闭详情页
/// @param nativeExpressAd 广告
- (void)zj_SSFW_nativeExpressAdVDidCloseOtherController:(ZJ_SSFWNativeExpressAd *)nativeExpressAd;

@end

@interface ZJ_SSFWNativeExpressAdManager : NSObject

@property(nonatomic,weak)id<ZJ_SSFWNativeExpressAdDelegate> delegate;

@property(nonatomic,weak)UIViewController *currentViewController;

@property(nonatomic,assign,readonly)ZJ_SSFWNativeExpressAdType type;

/// 最新的一条广告的ecpm
@property(nonatomic,assign,readonly)NSInteger ecpm;

/// 广告底价，单位分，不会返回低于此底价的广告，底价过高可能会没有广告，兜底返回错误提示：广告价格低于底价！
@property(nonatomic,assign)NSInteger basePrice;

/// 广告请求ID,不要在loadAd后立即去取。
@property(nonatomic,copy)NSString *adRequestID;

/// 禁止使用此方法来初始化
+ (instancetype)new NS_UNAVAILABLE;

/// 禁止使用此方法来初始化
- (instancetype)init NS_UNAVAILABLE;

/// 初始化方法
/// @param placementId 广告id
/// @param type 广告type
/// @param adSize 广告尺寸,ZJ_SSFWNativeExpressAdTypeFeed 类型根据宽度自适应，可将高度直接设置为0 ZJ_SSFWNativeExpressAdTypeDraw类型传入屏幕的宽高
- (instancetype)initWithPlacementId:(nonnull NSString *)placementId type:(ZJ_SSFWNativeExpressAdType)type adSize:(CGSize)adSize NS_DESIGNATED_INITIALIZER;

/// 加载广告
- (void)loadAd;

/// 通知广告平台的广告竞胜
///  @param costPrice 竞胜价格
///  @param secondPrice 二价
- (void)notifyBidWin:(double)costPrice secondPrice:(double)secondPrice;
/// 通知广告平台的广告竞败
/// @param bidLossReason 竞败原因
- (void)notifyBidLoss:(ZJ_SSFWBidReason *)bidLossReason;

@end

NS_ASSUME_NONNULL_END
