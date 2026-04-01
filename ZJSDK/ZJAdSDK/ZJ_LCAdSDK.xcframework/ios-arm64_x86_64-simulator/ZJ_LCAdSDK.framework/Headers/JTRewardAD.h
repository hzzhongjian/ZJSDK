//
//  JTInteractionAD.h
//  JTAdSDK
//
//  Created by Frank on 2025/6/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class JTRewardAD;

@protocol JTRewardADDelegate <NSObject>

@optional

// 激励广告加载成功
- (void)jtRewardADLoadSuccess:(JTRewardAD *)rewardAd;

// 激励广告加载失败回调
- (void)jtRewardADLoadFail:(JTRewardAD *)rewardAd error:(NSError *)error;

// 激励广告展示成功
- (void)jtRewardADExposureSuccess:(JTRewardAD *)rewardAd;

// 激励广告展示失败
- (void)jtRewardADExposureFail:(JTRewardAD *)rewardAd error:(NSError *)error;

// 激励广告点击回调
- (void)jtRewardADClickContent:(JTRewardAD *)rewardAd;

// 激励广告点激励达成
- (void)jtRewardADRewardArchived:(JTRewardAD *)rewardAd;

// 激励广告关闭回调
- (void)jtRewardADClosed:(JTRewardAD *)rewardAd;

@end

@interface JTRewardAD : JTBaseAdModel

/// 激励广告事件回调
@property (nonatomic, weak, nullable) id<JTRewardADDelegate> delegate;

/// 广告位模型
@property (nonatomic, strong, readonly) JTAdSlot *slot;

/// 通过Slot ID初始化激励广告
/// - Parameters:
///   - itemId: 广告位ID
- (instancetype)initWithSlotID:(NSString *)itemId;

/// 装载广告
- (void)loadAdData;

/// 展示激励广告
/// - Parameters:
///   - rootVC: 根控制器
- (void)showRewardADFromRootViewController:(UIViewController *)rootVC;

@end

NS_ASSUME_NONNULL_END
