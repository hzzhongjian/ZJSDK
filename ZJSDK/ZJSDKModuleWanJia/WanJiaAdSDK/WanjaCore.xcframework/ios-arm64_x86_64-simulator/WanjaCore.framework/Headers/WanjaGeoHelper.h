//
//  WanjaGeoHelper.h
//  WanjaCoreSDK
//
//  Created by guantou on 2019/12/9.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <MapKit/MapKit.h>

NS_ASSUME_NONNULL_BEGIN

/*
 *  定位类
 */
@class CLLocation;

@interface WanjaGeoHelper : NSObject

+ (WanjaGeoHelper *)shareInstance;

- (CLLocationCoordinate2D)getLatestAddress;

@end

NS_ASSUME_NONNULL_END
