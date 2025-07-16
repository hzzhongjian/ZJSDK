//
//  KSAdFeatureCollectManager.h
//  KSUCommercialLog
//
//  Created by 杜祥军 on 2025/3/26.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface KSAdFeatureCollectManager : NSObject

+ (instancetype)sharedInstance;

- (BOOL)enableCollectAndReport;

- (void)collectDeviceInfo;

- (void)startSlidingTrajectoryMonitoring:(UIView *)view;

@end

NS_ASSUME_NONNULL_END
