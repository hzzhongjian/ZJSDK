//
//  SMQueueManager.h
//  WindSDK
//
//  Created by happyelements on 2019/8/2.
//  Copyright © 2019 Codi. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void(^DCLogBlock)(NSMutableDictionary *params);

typedef enum : NSUInteger {
    SMTrackQueueTypeSigmob = 0,
    SMTrackQueueTypeToBid = 1,
} SMTrackQueueType;

@interface SMTrackingQueueManager : NSObject

/** track事件过期时间，过期后不执行补发操作，单位秒 */
@property(nonatomic, readwrite) uint32_t trackingExpirationTime;

/** track上报失败的重发时间间隔 */
@property(nonatomic, readwrite) uint32_t trackingRetryInterval;

+ (instancetype)sharedManager;

/** 启动tracking重试检查服务 */
- (void)startTimerCheckTrackingFailedList;

/** 注册重试tracking的dclog回调 */
- (void)addTrackResponseListener:(DCLogBlock)block
                       queueType:(SMTrackQueueType)type;

@end

