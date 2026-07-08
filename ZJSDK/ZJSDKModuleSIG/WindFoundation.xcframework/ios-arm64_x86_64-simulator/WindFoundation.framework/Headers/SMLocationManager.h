//
//  SMLocationManager.h
//  SigmobDemo
//
//  Created by happyelements on 2018/3/27.
//  Copyright © 2018年 Codi. All rights reserved.
//


#import <Foundation/Foundation.h>
#ifdef SIGMOB_LOCATION_MACRO
#import <CoreLocation/CoreLocation.h>
#endif

@interface SMLocationManager : NSObject

#ifdef SIGMOB_LOCATION_MACRO
@property(nonatomic, assign) BOOL hasAlwaysKey;
@property(nonatomic, assign)BOOL hasWhenInUseKey;
#endif
@property(nonatomic, assign)BOOL canUsed;

+ (SMLocationManager *)sharedManager;
- (BOOL)hasAuthorization;
- (void)startLocationService;
- (void)stopLocationService;
- (float)latitude;
- (float)longitude;

@end
