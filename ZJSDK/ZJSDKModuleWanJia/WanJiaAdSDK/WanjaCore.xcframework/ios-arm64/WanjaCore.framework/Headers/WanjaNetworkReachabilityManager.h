//
//  WanjaNetworkReachabilityManager.h
//  WanjaCoreSDK
//
//  Created by guantou on 2023/10/10.
//

#import <Foundation/Foundation.h>

#if !TARGET_OS_WATCH
#import <SystemConfiguration/SystemConfiguration.h>

typedef NS_ENUM(NSInteger, WanjaNetworkReachabilityStatus) {
    WanjaNetworkReachabilityStatusUnknown          = -1,
    WanjaNetworkReachabilityStatusNotReachable     = 0,
    WanjaNetworkReachabilityStatusReachableViaWWAN = 1,
    WanjaNetworkReachabilityStatusReachableViaWiFi = 2,
};

NS_ASSUME_NONNULL_BEGIN

@interface WanjaNetworkReachabilityManager : NSObject

@property (readonly, nonatomic, assign) WanjaNetworkReachabilityStatus networkReachabilityStatus;

@property (readonly, nonatomic, assign, getter = isReachable) BOOL reachable;

@property (readonly, nonatomic, assign, getter = isReachableViaWWAN) BOOL reachableViaWWAN;

@property (readonly, nonatomic, assign, getter = isReachableViaWiFi) BOOL reachableViaWiFi;

+ (instancetype)sharedManager;

+ (instancetype)manager;

+ (instancetype)managerForDomain:(NSString *)domain;

+ (instancetype)managerForAddress:(const void *)address;

- (instancetype)initWithReachability:(SCNetworkReachabilityRef)reachability NS_DESIGNATED_INITIALIZER;

+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)init NS_UNAVAILABLE;

- (void)startMonitoring;

- (void)stopMonitoring;

- (NSString *)localizedNetworkReachabilityStatusString;

- (void)setReachabilityStatusChangeBlock:(nullable void (^)(WanjaNetworkReachabilityStatus status))block;

@end

FOUNDATION_EXPORT NSString * const WanjaNetworkingReachabilityDidChangeNotification;
FOUNDATION_EXPORT NSString * const WanjaNetworkingReachabilityNotificationStatusItem;

FOUNDATION_EXPORT NSString * WanjaStringFromNetworkReachabilityStatus(WanjaNetworkReachabilityStatus status);

NS_ASSUME_NONNULL_END
#endif
