//
//  JYFullScreenVideoAd.h
//  JYAdSDK
//
//  Created by jyad110 on 2021/6/16.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <JYAdSDK/JYAdSDKConfig.h>

NS_ASSUME_NONNULL_BEGIN

@class JYFullScreenVideoAd;

@protocol JYFullScreenVideoAdDelegate <NSObject>

@optional

- (void)jy_fullScreenVideoAdDidLoad:(JYFullScreenVideoAd *)fullScreenVideoAd;
- (void)jy_fullScreenVideoAdDidFailToLoad:(JYFullScreenVideoAd *)fullScreenVideoAd error:(NSError *)error;
- (void)jy_fullScreenVideoAdDidCache:(JYFullScreenVideoAd *)fullScreenVideoAd;
- (void)jy_fullScreenVideoAdDidExpose:(JYFullScreenVideoAd *)fullScreenVideoAd;
- (void)jy_fullScreenVideoAdDidClick:(JYFullScreenVideoAd *)fullScreenVideoAd;
- (void)jy_fullScreenVideoAdDidClose:(JYFullScreenVideoAd *)fullScreenVideoAd;
- (void)jy_fullScreenVideoAdDidPlayFinish:(JYFullScreenVideoAd *)fullScreenVideoAd;
- (void)jy_fullScreenVideoAdDidClickSkip:(JYFullScreenVideoAd *)fullScreenVideoAd;

@end

@interface JYFullScreenVideoAd : NSObject <JYAdProtocol>
@property (nonatomic, weak, nullable) id<JYFullScreenVideoAdDelegate> delegate;
@property (nonatomic, assign, readonly) JYAdSdkUnionType unionType;
- (instancetype)initWithSlotId:(NSString *) slotId;
- (void)loadAd;
- (void)showAdFromRootViewController:(UIViewController *) viewController;
- (BOOL)isValid;
- (NSInteger)eCPM;
- (NSDictionary * _Nullable)extraInfo;
- (void)sendWinNotificationWithInfo:(NSDictionary *)winInfo;
- (void)sendLossNotificationWithInfo:(NSDictionary *)lossInfo;
@end

NS_ASSUME_NONNULL_END
