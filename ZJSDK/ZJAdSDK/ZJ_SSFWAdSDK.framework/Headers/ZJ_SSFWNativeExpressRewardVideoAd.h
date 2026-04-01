//
//  ZJ_SSFWNativeExpressRewardVideoAd.h
//  lottie-ios_Oc
//
//  Created by admin on 2021/1/26.
//

#import <UIKit/UIkit.h>
#import <ZJ_SSFWAdSDK/ZJ_SSFWSourceAdType.h>
#import <ZJ_SSFWAdSDK/ZJ_SSFWBidReason.h>
#import <ZJ_SSFWAdSDK/ZJ_SSFWAdMaterial.h>
#import <ZJ_SSFWAdSDK/ZJ_SSFWRewardedVideoModel.h>
@class ZJ_SSFWNativeExpressRewardVideoAd;

NS_ASSUME_NONNULL_BEGIN

@protocol ZJ_SSFWRewardVideoDelegate <NSObject>
@optional
/// 激励广告加载成功
- (void)zj_SSFW_rewardVideoAdDidLoad:(ZJ_SSFWNativeExpressRewardVideoAd *)rewardVideoAd;

/// 激励广告失败 加载失败 播放失败 渲染失败
- (void)zj_SSFW_rewardVideoAd:(ZJ_SSFWNativeExpressRewardVideoAd *)rewardVideoAd didFailWithError:(NSError *)error;

/// 激励广告将要展示
- (void)zj_SSFW_rewardVideoAdWillVisible:(ZJ_SSFWNativeExpressRewardVideoAd *)rewardVideoAd;

/// 激励广告曝光
- (void)zj_SSFW_rewardVideoAdDidExposed:(ZJ_SSFWNativeExpressRewardVideoAd *)rewardVideoAd;

/// 激励广告曝光失败
- (void)zj_SSFW_rewardVideoAdExposedFail:(ZJ_SSFWNativeExpressRewardVideoAd *)rewardVideoAd error:(NSError *)error;;

/// 激励广告关闭
- (void)zj_SSFW_rewardVideoAdDidClose:(ZJ_SSFWNativeExpressRewardVideoAd *)rewardVideoAd;

/// 激励广告被点击
- (void)zj_SSFW_rewardVideoAdDidClicked:(ZJ_SSFWNativeExpressRewardVideoAd *)rewardVideoAd;

/// 激励广告播放完成
- (void)zj_SSFW_rewardVideoAdDidPlayFinish:(ZJ_SSFWNativeExpressRewardVideoAd *)rewardVideoAd;

/// 达到激励条件
- (void)zj_SSFW_rewardVideoAdDidRewardEffective:(ZJ_SSFWNativeExpressRewardVideoAd *)rewardedVideoAd isVerify:(BOOL)isVerify;

@end

@interface ZJ_SSFWNativeExpressRewardVideoAd : NSObject

/// 广告id
@property(nonatomic,copy,readonly)NSString *placementId;

/// 激励广告代理
@property(nonatomic,weak)id<ZJ_SSFWRewardVideoDelegate> delegate;

/// 消耗方类型
@property(nonatomic,assign)ZJ_SSFWAdSourceType sourceType;

/// 广告ecpm 单位分
@property(nonatomic,assign,readonly)NSInteger ecpm;

@property(nonatomic,assign,readonly)BOOL isReady;

@property(nonatomic,strong,readonly)ZJ_SSFWRewardedVideoModel *rewardedVideoModel;

/// 广告素材 可能为空
@property(nullable,nonatomic,strong)ZJ_SSFWAdMaterial *adMaterial;

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
/// @param model rewarded video model. 可传空 
- (instancetype)initWithPlacementId:(nonnull NSString *)placementId rewardedVideoModel:(nullable ZJ_SSFWRewardedVideoModel *)model NS_DESIGNATED_INITIALIZER;

/// 加载广告
- (void)loadAd;

/// 展示激励广告
/// @param controller 控制器 一般为当前控制器 或者栈顶控制器
- (void)showAdFromRootViewController:(UIViewController *)controller;

/// 通知广告平台的广告竞胜
///  @param costPrice 竞胜价格
///  @param secondPrice 二价
- (void)notifyBidWin:(double)costPrice secondPrice:(double)secondPrice;
/// 通知广告平台的广告竞败
/// @param bidLossReason 竞败原因
- (void)notifyBidLoss:(ZJ_SSFWBidReason *)bidLossReason;

@end

NS_ASSUME_NONNULL_END
