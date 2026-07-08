//
//  ZJ_YSAdSDKSplashView.h
//
//  开屏View
//  Created by yanchao on 2020/6/15.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class ZJ_YSAdSDKSplashView;

@protocol ZJ_YSAdSDKSplashAdDelegate <NSObject>

@optional

/**
 广告加载成功
 */
- (void)zj_ysSplashAdLoadSuccess:(ZJ_YSAdSDKSplashView *)splashAd;;

/**
 广告加载失败
 @param errorCode 错误码
 @param errorMessage 错误信息
 */
- (void)zj_ysSplashAdLoadFail:(NSInteger)errorCode andErrorMessage:(NSString *)errorMessage;

/**
 广告曝光成功
 */
- (void)zj_ysSplashAdExposedSuccess;

/**
 广告展示失败
 @param errorMessage 错误信息
 */
- (void)zj_ysSplashAdShowFail:(NSString *)errorMessage;

/**
 广告点击跳过
 */
- (void)zj_ysSplashAdClickSkip;

/**
 广告完成倒计时
 */
- (void)zj_ysSplashAdFinishCountdown;

/**
 广告被点击
 */
- (void)zj_ysSplashAdDidClicked;

/**
 广告关闭了
 */
- (void)zj_ysSplashAdDidClosed;

/**
 广告关闭了另一个控制器
 */
- (void)zj_ysSplashAdDidCloseOtherController;


@end

@interface ZJ_YSAdSDKSplashView : UIView <ZJ_YSAdSDKSplashAdDelegate>

/**
 *  委托对象
 */
@property (nonatomic, weak) id<ZJ_YSAdSDKSplashAdDelegate> delegate;

/**
 *  非必传，开屏广告半屏时下方展示视图，不传入或传入为nil时为全屏
 */
@property (nonatomic, strong) UIView *bottomView;

/**
 *  媒体用来获取部分信息的字典
 */
@property (nonatomic, readonly) NSDictionary *mediaExtraInfo;

/**
 *  媒体用来获取返回的竞价价格
 */
- (double)salePrice;

/**
 *  移除所有子视图
 */
- (void)removeAllSubViews;

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


#pragma mark -加载开屏广告
/**
 *  设置广告位
 *  @param placementId  广告位 ID
 */
- (instancetype)initWithPlacementId:(NSInteger)placementId;


/**
 *  加载开屏广告
 */
- (void)loadSplashAdData;

/**
 *  加载开屏广告 S2S bidding 后获取到 token 再调用此方法
 *  @param token  通过 Server Bidding 请求回来的 token
 */
- (void)loadSplashAdDataWithToken:(NSString *)token;

/**
 *  展示开屏广告
 *  @param window  自定义window
 */

- (void)showInWindow:(UIWindow *)window;


/**
 *  展示开屏广告
 *  @param window  keyWindow
 */

- (void)showInKeyWindow:(UIWindow *)window;

@end

NS_ASSUME_NONNULL_END
