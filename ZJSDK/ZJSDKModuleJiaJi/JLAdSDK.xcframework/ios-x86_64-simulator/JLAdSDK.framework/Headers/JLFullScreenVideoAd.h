//
//  JLFullScreenVideoAd.h
//  JLAdSDK
//
//  Created by jlad110 on 2021/6/16.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <JLAdSDK/JLAdSDKConfig.h>

NS_ASSUME_NONNULL_BEGIN

@class JLFullScreenVideoAd;

@protocol JLFullScreenVideoAdDelegate <NSObject>

@optional

- (void)jl_fullScreenVideoAdDidLoad:(JLFullScreenVideoAd *)fullScreenVideoAd;
- (void)jl_fullScreenVideoAdDidFailToLoad:(JLFullScreenVideoAd *)fullScreenVideoAd error:(NSError *)error;
- (void)jl_fullScreenVideoAdDidCache:(JLFullScreenVideoAd *)fullScreenVideoAd;
- (void)jl_fullScreenVideoAdDidExpose:(JLFullScreenVideoAd *)fullScreenVideoAd;
- (void)jl_fullScreenVideoAdDidClick:(JLFullScreenVideoAd *)fullScreenVideoAd;
- (void)jl_fullScreenVideoAdDidClose:(JLFullScreenVideoAd *)fullScreenVideoAd;
- (void)jl_fullScreenVideoAdDidPlayFinish:(JLFullScreenVideoAd *)fullScreenVideoAd;
- (void)jl_fullScreenVideoAdDidClickSkip:(JLFullScreenVideoAd *)fullScreenVideoAd;

@end

@interface JLFullScreenVideoAd : NSObject <JLAdProtocol>
@property (nonatomic, weak, nullable) id<JLFullScreenVideoAdDelegate> delegate;
@property (nonatomic, assign, readonly) JLAdSdkUnionType unionType;
- (instancetype)initWithSlotId:(NSString *) slotId;
- (void)loadAd;
- (void)showAdFromRootViewController:(UIViewController *) viewController;
- (BOOL)isValid;
- (NSInteger)eCPM;
- (void)sendWinNotificationWithInfo:(NSDictionary *)winInfo;
- (void)sendLossNotificationWithInfo:(NSDictionary *)lossInfo;
@end

NS_ASSUME_NONNULL_END
