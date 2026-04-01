//
//  JTInteractiveAD.h
//  JTAdSDK
//
//  Created by Frank on 2025/8/14.
//

#import <Foundation/Foundation.h>
#import "JTAdSlot.h"

NS_ASSUME_NONNULL_BEGIN

@class JTInteractiveAD;
@class UIViewController;

/// 聚推互动式广告事件回调协议
@protocol JTInteractiveADDelegate <NSObject>

@optional

/// 互动式广告拉取成功
/// - Parameter interactiveAd: 互动式广告模型
- (void)jtInteractiveAdLoadSuccess:(JTInteractiveAD *)interactiveAd;

/// 互动式广告拉取失败
/// - Parameters:
///   - interactiveAd: 互动式广告模型
///   - error: 失败原因
- (void)jtInteractiveAdLoadFail:(JTInteractiveAD *)interactiveAd error:(NSError *_Nullable)error;

/// 互动式广告展示成功
/// - Parameter interactiveAd: 互动式广告模型
- (void)jtInteractiveAdDidExposureSuccess:(JTInteractiveAD *)interactiveAd;

/// 互动式广告展示失败
/// - Parameter interactiveAd: 互动式广告模型
- (void)jtInteractiveAdDidExposureFail:(JTInteractiveAD *)interactiveAd error:(NSError *_Nullable)error;

/// 互动式广告点击关闭
/// - Parameter interactiveAd: 互动式广告模型
- (void)jtInteractiveAdDidClose:(JTInteractiveAD *)interactiveAd;

/// 互动式广告成功曝光了一个广告
/// - Parameter interactiveAd: 互动式广告模型
- (void)jtInteractiveAdDidExposureAdSuccess:(JTInteractiveAD *)interactiveAd;

@end

@interface JTInteractiveAD : NSObject

/// 广告位模型
@property (nonatomic, strong, readonly) JTAdSlot *slot;

/// 互动式广告事件回调
@property (nonatomic, weak, nullable) id<JTInteractiveADDelegate> delegate;

/// 通过Slot ID初始化互动式广告
/// - Parameters:
///   - itemId: 广告位模型
- (instancetype)initWithSlotID:(NSString *)slotId;

/// 装载广告且展示互动式广告
/// - Parameters:
///   - rootVC: 根控制器VC,或者导航控制器。
- (void)loadAndShowInteractiveAdFromRootViewController:(UIViewController *)rootVC;

/// 手动移除当前互动式广告页面
- (void)removeInteractiveAdView;

@end

NS_ASSUME_NONNULL_END
