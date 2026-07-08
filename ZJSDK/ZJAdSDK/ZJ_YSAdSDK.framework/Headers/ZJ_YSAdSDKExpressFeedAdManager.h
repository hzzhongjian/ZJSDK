//
//  ZJ_YSAdSDKExpressFeedAdManager.h
//  ZJ_YSAdSDK
//
//  模版信息流广告管理器
//
//  典型使用流程：
//    1. initWithPlacementId:adSize: 初始化（宽度固定，高度传 0 表示自适应）
//    2. 设置 delegate
//    3. 调用 loadAdDataWithCount: 发起请求
//    4. 在 expressFeedAdManagerSuccessToLoad:views: 回调中拿到 ZJ_YSAdSDKExpressFeedAdView 数组
//    5. 对每个 view 设置 delegate/rootViewController，调用 render，然后 addSubview 到 Cell

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class ZJ_YSAdSDKExpressFeedAdManager;
@class ZJ_YSAdSDKExpressFeedAdView;

@protocol ZJ_YSAdSDKExpressFeedAdManagerDelegate <NSObject>

@optional

/// 模版信息流广告加载成功，返回渲染好的 view 数组
/// @param manager 管理器实例
/// @param views 模版广告 view 数组，每个元素为 ZJ_YSAdSDKExpressFeedAdView
- (void)expressFeedAdManagerSuccessToLoad:(ZJ_YSAdSDKExpressFeedAdManager *)manager
                                    views:(NSArray<ZJ_YSAdSDKExpressFeedAdView *> *)views;

/// 模版信息流广告加载失败
/// @param manager 管理器实例
/// @param error 错误信息
- (void)expressFeedAdManager:(ZJ_YSAdSDKExpressFeedAdManager *)manager
            didFailWithError:(NSError *)error;

@end


@interface ZJ_YSAdSDKExpressFeedAdManager : NSObject

/// 委托对象
@property (nonatomic, weak) id<ZJ_YSAdSDKExpressFeedAdManagerDelegate> delegate;

/// 媒体附加信息（含 requestId 等）
@property (nonatomic, readonly) NSDictionary *mediaExtraInfo;

/// 竞价价格
- (double)salePrice;


/// 发送竞胜通知
- (void)sendWinNotificationWithPrice:(NSInteger)price;

/// 发送竞败通知
- (void)sendWinFailNotificationWithPrice:(NSInteger)price;

#pragma mark - Bidding

/// 获取 buyerId，用于 Server Bidding 请求
- (NSString *)getBuyerIdWithContext:(nullable NSDictionary *)info;

/**
 获取用于 Server Bidding 请求SDK侧相关请求参数信息
 不阻塞主线程，token 获取和广告预请求完成后通过 completion 回调 sdkInfo
 */
- (void)getSDKInfoWithPlacementId:(NSInteger)placementId completion:(void(^)(NSString *sdkInfo))completion;

#pragma mark - 初始化

/// 初始化模版信息流广告管理器
/// @param placementId 广告位 ID
/// @param adSize 模版尺寸（宽度固定，高度传 0 表示自适应）
- (instancetype)initWithPlacementId:(NSInteger)placementId adSize:(CGSize)adSize;

#pragma mark - 加载

/// 加载模版信息流广告
/// @param count 加载广告的个数，推荐不超过 3 条，默认 1 条
- (void)loadAdDataWithCount:(NSInteger)count;

/**
 S2S Bidding 模式：拿到 token 后调用
 @param count 加载广告的个数，推荐不超过 3 条，默认 1 条
 @param token Server Bidding 返回的 token
 */
- (void)loadAdDataWithCount:(NSInteger)count WithToken:(NSString *)token;

@end

NS_ASSUME_NONNULL_END
