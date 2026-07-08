//
//  WindShareData.h
//  WindFoundation
//
//  Created by Codi on 2021/10/20.
//

#import <Foundation/Foundation.h>

@class SMDispatchQueuePool;
@class WindSDKAdCache;

@interface WindShareData : NSObject

+ (instancetype)sharedInstance;

@property (nonatomic, copy) NSString *mAppId;
@property (nonatomic, copy) NSString *mAppKey;
@property (nonatomic, copy) NSString *appId;
@property (nonatomic, copy) NSString *appKey;

@property (nonatomic, copy) NSString *userId;
/// 1: accepted; 2:Denied
@property (nonatomic, assign) NSInteger gdprState;
///是否使用聚合
@property (nonatomic, assign) BOOL useMedation __attribute__((deprecated("后续版本废弃"))); 
@property (nonatomic, strong) NSDictionary *customGroup;


- (void)initUserAgent;

- (NSString *)getUserAgent;

- (void)updateUserAgent:(NSString *)userAgent;

- (void)updateCarrierInfo:(NSString *)infoStr;
- (NSDictionary *)getCarrierInfo;

/// 记录广告的加载时间（s）
/// @param placementId 广告位ID
- (void)removeLoadTimestamp:(NSString *)placementId medation:(BOOL)isMedation;
- (void)removeLoadReadyTimestamp:(NSString *)placementId  medation:(BOOL)isMedation;
- (void)addLoadTimestamp:(NSString *)placementId  medation:(BOOL)isMedation;
- (void)addLoadReadyTimestamp:(NSString *)placementId  medation:(BOOL)isMedation;
- (int64_t)getLoadTimestampWithPlacementId:(NSString *)placementId  medation:(BOOL)isMedation;
- (int64_t)getLoadReadyTimestampWithPlacementId:(NSString *)placementId  medation:(BOOL)isMedation;

/// 记录sigmob在当前策略组的位置
/// @param placementId 广告位ID
- (void)addSigmobIndexInStrategyGroupWithPlacementId:(NSString *)placementId index:(NSInteger)index;
- (int)getSigmobIndexInStrategyGroupWithPlacementId:(NSString *)placementId;

- (SMDispatchQueuePool *)getDispatchQueuePool;
@end
