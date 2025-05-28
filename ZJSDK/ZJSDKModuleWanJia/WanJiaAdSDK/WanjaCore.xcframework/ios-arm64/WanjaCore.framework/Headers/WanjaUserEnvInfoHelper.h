//
//  WanjaUserEnvInfoHelper.h
//  WanjaCoreSDK
//
//  Created by guantou on 2019/12/9.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/*
 *  用户信息类
 */
@interface WanjaUserEnvInfoHelper : NSObject

+ (WanjaUserEnvInfoHelper *)shareInstance;

@property (nonatomic, readonly) NSString *net;
@property (nonatomic, readonly) NSString *isp;
@property (nonatomic, readonly) NSString *ip;
@property (nonatomic, readonly) CGFloat battery;
@property (nonatomic, readonly) uint64_t diskSpace;
@property (nonatomic, readonly) uint64_t useSpace;
@property (nonatomic, readonly) NSString *geo_longitude;
@property (nonatomic, readonly) NSString *geo_latitude;
@property (nonatomic, readonly) NSString *geo_geoName;

@end

NS_ASSUME_NONNULL_END
