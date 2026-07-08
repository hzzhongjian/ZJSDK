//
//  ZJ_YSAdSDKExpressFullscreenVideoAdManager.h
//  ZJ_YSAdSDKDemo
//
//  Created by yanchao on 2025/5/28.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@class ZJ_YSAdSDKExpressFullscreenVideoAdManager;

@protocol ZJ_YSAdSDKExpressFullscreenVideoAdDelegate <NSObject>

@optional

/**
 广告加载成功
 */
- (void)zj_ysExpressFullscreenVideoAdLoadSuccess;

/**
 广告加载失败
 @param errorCode 错误码
 @param errorMessage 错误信息
 */
- (void)zj_ysExpressFullscreenVideoAdLoadFail:(NSInteger)errorCode andErrorMessage:(NSString *)errorMessage;


/**
 广告渲染失败
 @param errorMessage 错误信息
 */
- (void)zj_ysExpressFullscreenVideoAdRenderFail:(NSString *)errorMessage;


/**
 广告曝光成功
 */
- (void)zj_ysExpressFullscreenVideoAdExposured;

/**
 广告被点击
 */
- (void)zj_ysExpressFullscreenVideoAdDidClicked;


/**
 广告点击了关闭
 */
- (void)zj_ysExpressFullscreenVideoAdDidClosed;

/**
 广告关闭了另一个控制器
 */
- (void)zj_ysExpressFullscreenVideoAdDidClosedOtherController;
@end


@interface ZJ_YSAdSDKExpressFullscreenVideoAdManager : NSObject<ZJ_YSAdSDKExpressFullscreenVideoAdDelegate>
/**
 *  委托对象
 */
@property (nonatomic, weak) id<ZJ_YSAdSDKExpressFullscreenVideoAdDelegate> delegate;

/**
 *  媒体用来获取部分信息的字典
 */
@property (nonatomic, readonly) NSDictionary *mediaExtraInfo;

/**
 *  返回的竞价价
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

#pragma mark -初始化插屏广告
/**
 初始化插屏广告
 @param placementId  广告位id
 */
- (instancetype)initWithPlacementId:(NSInteger)placementId;

#pragma mark -加载插屏广告
/**
 加载插屏广告
 */
- (void)loadExpressFullscreenVideoAd;


/**
 *  加载插屏广告 S2S bidding 后获取到 token 再调用此方法
 *  @param token  通过 Server Bidding 请求回来的 token
 */
- (void)loadExpressFullscreenVideoAdWithToken:(NSString *)token;

#pragma mark -展示插屏广告
/**
 展示插屏广告
 @param rootViewController  展示插屏的控制器
 */
- (void)showExpressFullscreenVideoAd:(UIViewController *)rootViewController;

@end

NS_ASSUME_NONNULL_END
