//
//  JLRewardVideoAd.h
//  JLAdSDK
//
//  Created by jlad110 on 2021/4/20.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <JLAdSDK/JLAdSDKConfig.h>

NS_ASSUME_NONNULL_BEGIN

@class JLRewardVideoAd;

@protocol JLRewardVideoAdDelegate <NSObject>

@optional

- (void)jl_rewardVideoAdDidLoad:(JLRewardVideoAd *)rewardVideoAd;
- (void)jl_rewardVideoAdDidFailToLoad:(JLRewardVideoAd *)rewardVideoAd error:(NSError *)error;
- (void)jl_rewardVideoAdDidCache:(JLRewardVideoAd *)rewardVideoAd;
- (void)jl_rewardVideoAdDidExpose:(JLRewardVideoAd *)rewardVideoAd;
- (void)jl_rewardVideoAdDidClick:(JLRewardVideoAd *)rewardVideoAd;
- (void)jl_rewardVideoAdDidClose:(JLRewardVideoAd *)rewardVideoAd;
- (void)jl_rewardVideoAdDidPlayFinish:(JLRewardVideoAd *)rewardVideoAd;
- (void)jl_rewardVideoAdDidRewardEffective:(JLRewardVideoAd *)rewardVideoAd trackUid:(NSString *)trackUid;
- (void)jl_rewardVideoAdDidCloseOtherController:(JLRewardVideoAd *)rewardVideoAd;
- (void)jl_rewardVideoAdDidPresentFullScreenModal:(JLRewardVideoAd *)rewardVideoAd;

@end

@interface JLRewardVideoAd : NSObject <JLAdProtocol>

@property (nonatomic, weak, nullable) id<JLRewardVideoAdDelegate> delegate;
@property (nonatomic, assign) BOOL videoMuted;
@property (nonatomic, assign, readonly) JLAdSdkUnionType unionType;

- (instancetype)initWithSlotId:(NSString *)slotId;
- (instancetype)initWithSlotId:(NSString *)slotId extra:(NSString * _Nullable)extra;
- (void)loadAd;
- (void)showAdFromRootViewController:(UIViewController *)viewController;
- (BOOL)isValid;
- (NSInteger)eCPM;
- (void)sendWinNotificationWithInfo:(NSDictionary *)winInfo;
- (void)sendLossNotificationWithInfo:(NSDictionary *)lossInfo;

@end

NS_ASSUME_NONNULL_END
