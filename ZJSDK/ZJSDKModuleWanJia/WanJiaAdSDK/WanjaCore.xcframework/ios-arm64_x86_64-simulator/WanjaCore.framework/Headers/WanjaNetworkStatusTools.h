//
//  WanjaNetworkStatusTools.h
//  WanjaCoreSDK
//
//  Created by guantou on 2019/12/10.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/*
 *  网络状态类
 */
typedef NS_ENUM(NSInteger, WanjaConnectionType) {
    WanjaConnectionUnknown          = -1,
    WanjaConnectionNotReachable     = 0,
    WanjaConnectionNetwork2G        = 2,
    WanjaConnectionNetwork3G        = 3,
    WanjaConnectionNetwork4G        = 4,
    WanjaConnectionWiFi             = 9,
};

typedef NS_ENUM(NSInteger, WanjaOperatorType) {
    WanjaOperatorUnknown     = 0,
    WanjaOperatorCNMobile    = 1, // 中国移动
    WanjaOperatorCNUnicom    = 2, // 中国联通
    WanjaOperatorCNTelecom   = 3, // 中国电信
};

typedef NS_ENUM(NSInteger, WanjaNetworkStatus) {
    WanjaNetworkUnknown       = -1,
    WanjaNetworkNotReachable  = 0,
    WanjaNetworkWWAN          = 1,
    WanjaNetworkWIFI          = 9,
};

UIKIT_EXTERN WanjaNetworkStatus baseWanjaNetworkStatus;

typedef void(^WanjaNetworkingStatusBlock)(WanjaNetworkStatus status);

@interface WanjaNetworkStatusTools : NSObject

@property (nonatomic, readonly) WanjaNetworkStatus networkStatus; // 返回网络状态，WIFI/运营商网络/无网络
@property (nonatomic, readonly) WanjaOperatorType carrierType; // 运营商类型，移动/联通/电信/其它
@property (nonatomic, readonly) WanjaConnectionType connectionType;   // 连接类型，2G/3G/4G/WIFI
@property (nonatomic, readonly) NSString *ipAddress;
@property (nonatomic, readonly) NSString *userAgent;

+ (WanjaNetworkStatusTools *)shareInstance;

+ (void)ljx_startNetWorkMonitoringWithBlock:(WanjaNetworkingStatusBlock)networkStatus;

@end

NS_ASSUME_NONNULL_END
