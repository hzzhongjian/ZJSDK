//
//  ZJ_YSAdSDKBannerView.h
//  ZJ_YSAdSDK
//  banner广告
//  Created by yanchao on 2024/3/27.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class ZJ_YSAdSDKBannerView;

@protocol ZJ_YSAdSDKBannerAdDelegate <NSObject>

@optional

/**
 广告加载成功
 @param bannerView 展示的视图
 */
- (void)zj_ysBannerAdLoadSuccess:(ZJ_YSAdSDKBannerView *)bannerView;

/**
 广告加载失败
 @param errorCode 错误码
 @param errorMessage 错误信息
 */
- (void)zj_ysBannerAdLoadFail:(NSInteger)errorCode andErrorMessage:(NSString *)errorMessage;

/**
 广告曝光成功
 */
- (void)zj_ysBannerAdExposedSuccess;

/**
 广告展示失败
 @param errorMessage 错误信息
 */
- (void)zj_ysBannerAdShowFail:(NSString *)errorMessage;

/**
 广告被点击
 */
- (void)zj_ysBannerAdDidClicked;

/**
 广告点击了关闭
 */
- (void)zj_ysBannerAdDidClosed;

/**
 广告关闭了另一个控制器
 */
- (void)zj_ysBannerAdDidCloseOtherController;
@end


@interface ZJ_YSAdSDKBannerView : UIView<ZJ_YSAdSDKBannerAdDelegate>
/**
 *  委托对象
 */
@property (nonatomic, weak) id<ZJ_YSAdSDKBannerAdDelegate> delegate;

/**
 *  Banner广告展示的控制器
 */
@property (nonatomic, strong) UIViewController *rootViewController;

// 广告位尺寸 所有广告位必须要传
// 注: adSize 就是 广告view 的Size
@property (nonatomic, assign) CGSize adSize;

/**
 *  媒体用来获取部分信息的字典（含 requestId、redirectUrl 等）
 */
@property (nonatomic, readonly) NSDictionary *mediaExtraInfo;

/**
 *  返回的竞价价格
 */
- (double)salePrice;

#pragma mark -bidding
/**
 获取 buyerId 用于 Server Bidding 请求获取 token, 建议每次请求前调用一次, 并使用最新值请求
 */
- (NSString *)getBuyerIdWithContext:(NSDictionary *)info;

/**
 获取用于 Server Bidding 请求SDK侧相关请求参数信息（异步版本）
 @param placementId 广告位ID
 @param completion 回调，sdkInfo 为请求参数信息字符串
 */
- (void)getSDKInfoWithPlacementId:(NSInteger)placementId completion:(void(^)(NSString *sdkInfo))completion;

/**
 *  发送竞胜
 *  @param price 竞胜价格
 */
- (void)sendWinNotificationWithPrice:(NSInteger)price;

/**
 *  发送竞败
 *  @param price 竞败价格
 */
- (void)sendWinFailNotificationWithPrice:(NSInteger)price;

#pragma mark -初始化Banner广告
/**
 初始化Banner广告
 @param placementId  广告位id
 */
- (instancetype)initWithPlacementId:(NSInteger)placementId;

#pragma mark -加载并展示Banner广告
/**
 *  加载Banner广告
 */
- (void)loadAndShowBannerAd;


/**
 *  加载Banner广告 S2S bidding 后获取到 token 再调用此方法
 *  @param token  通过 Server Bidding 请求回来的 token
 */
- (void)loadAndShowBannerAdWithToken:(NSString *)token;

@end

NS_ASSUME_NONNULL_END
