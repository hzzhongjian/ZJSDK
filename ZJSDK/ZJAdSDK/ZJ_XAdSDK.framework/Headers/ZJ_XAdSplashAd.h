//
//  ZJ_XAdSplashAd.h
//  WangMaiAdSDK
//
//  Created by 周泽浩 on 2023/2/13.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZJ_XAdSplashDelegate;

@interface ZJ_XAdSplashAd : NSObject

/// 开屏协议
@property (nonatomic,weak) id<ZJ_XAdSplashDelegate>delegate;

/// 是否需要满足HTTPS  [可选] 默认为NO
@property (nonatomic, assign) BOOL secure;

/// 是否屏蔽摇一摇，NO或者不赋值，不屏蔽，YES屏蔽
@property (nonatomic, assign) BOOL disableShake;

/// 是否屏蔽扭一扭，NO或者不赋值，不屏蔽，YES屏蔽
@property (nonatomic, assign) BOOL disableTwist;

/// 开屏广告停留时长（仅脉盟预算支持）
@property (nonatomic, assign) NSInteger stayTime;
 
/// 底部自定义窗口  [可选]
@property (nonatomic, weak) UIView *bottomView;

/// 构造方法
/// - Parameter adSlotId: 广告位id
- (instancetype)initWithAdSlotId:(NSString *)adSlotId;

/// 获取用于 Server Bidding 请求SDK侧相关请求参数信息
/// - Parameter adSlotId: 广告位id
- (NSString *)getBuyerIdWithAdSlotId:(NSString *)adSlotId;

/// 加载广告,只加载不展示,需要调用showAd展示广告
/// - Parameter serverBidToken: 通过 Server Bidding 请求回来的 token  不使用Server Bidding时传 nil
- (void)preloadAdDataWithServerBidToken:(NSString *_Nullable)serverBidToken;

/**
 广告是否有效
 @return 广告有效返回YES  广告无效返回NO
 */
- (BOOL)isReady;

/// 展示广告
/// @param window 应用的window窗口 [必传]
- (void)showAdInWindow:(UIWindow *)window;

/**
 返回广告的eCPM，单位：分
 
 @return 成功返回一个大于等于0的值，-1表示无权限或后台出现异常
 */
- (NSInteger)eCPM;

/// 竞价成功上报，脉盟平台竞胜之后调用，需要在广告请求成功之后,展示之前调用，winInfo脉盟平台竞价获胜信息，可为nil。（使用 Server Bidding 时，竞胜竞败由Server处理。不用调用该方法）
/// @param winInfo 竞胜信息 字典类型
- (void)sendWinNotificationWithInfo:(NSDictionary *_Nullable)winInfo;

/// 获取当前广告物料
// material_url: 素材 url 数组
// adTitle: 标题
// adDescription:描述
// crid:素材id/创意id
- (NSDictionary *)getCurrentAdMaterialsInfo;

/// 广告销毁（仅脉盟预算支持）
- (void)destroy;

@end

NS_ASSUME_NONNULL_END
