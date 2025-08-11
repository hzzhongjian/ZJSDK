//
//  JYRewardVideoAd.h
//  JYAdSDK
//
//  Created by jyad110 on 2021/4/20.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <JYAdSDK/JYAdSDKConfig.h>

NS_ASSUME_NONNULL_BEGIN

@class JYRewardVideoAd;

@protocol JYRewardVideoAdDelegate <NSObject>

@optional

- (void)jy_rewardVideoAdDidLoad:(JYRewardVideoAd *)rewardVideoAd;
- (void)jy_rewardVideoAdDidFailToLoad:(JYRewardVideoAd *)rewardVideoAd error:(NSError *)error;
- (void)jy_rewardVideoAdDidCache:(JYRewardVideoAd *)rewardVideoAd;
- (void)jy_rewardVideoAdDidExpose:(JYRewardVideoAd *)rewardVideoAd;
- (void)jy_rewardVideoAdDidClick:(JYRewardVideoAd *)rewardVideoAd;
- (void)jy_rewardVideoAdDidClose:(JYRewardVideoAd *)rewardVideoAd;
- (void)jy_rewardVideoAdDidPlayFinish:(JYRewardVideoAd *)rewardVideoAd;
- (void)jy_rewardVideoAdDidRewardEffective:(JYRewardVideoAd *)rewardVideoAd trackUid:(NSString *)trackUid;
- (void)jy_rewardVideoAdDidCloseOtherController:(JYRewardVideoAd *)rewardVideoAd;
- (void)jy_rewardVideoAdDidPresentFullScreenModal:(JYRewardVideoAd *)rewardVideoAd;

@end

@interface JYRewardVideoAd : NSObject <JYAdProtocol>

@property (nonatomic, weak, nullable) id<JYRewardVideoAdDelegate> delegate;
@property (nonatomic, assign) BOOL videoMuted;
@property (nonatomic, assign, readonly) JYAdSdkUnionType unionType;

- (instancetype)initWithSlotId:(NSString *)slotId;
- (instancetype)initWithSlotId:(NSString *)slotId extra:(NSString * _Nullable)extra;
- (void)loadAd;
- (void)showAdFromRootViewController:(UIViewController *)viewController;
- (BOOL)isValid;
- (NSInteger)eCPM;
- (NSDictionary * _Nullable)extraInfo;
- (void)sendWinNotificationWithInfo:(NSDictionary *)winInfo;
- (void)sendLossNotificationWithInfo:(NSDictionary *)lossInfo;

@end

NS_ASSUME_NONNULL_END
