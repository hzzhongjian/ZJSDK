//
//  SMAdLogManager.h
//  WindFoundation
//
//  Created by Codi on 2021/10/20.
//

#import <Foundation/Foundation.h>

static NSString *const SM_ADTYPE = @"adtype";
static NSString *const SM_CATEGORY = @"category";
static NSString *const SM_SUB_CATEGORY = @"sub_category";
static NSString *const SM_USER_ID = @"user_id";
static NSString *const SM_TIMESTAMP = @"timestamp";

@interface SMAdLogManager : NSObject

- (void)setSendLogIntervalValue:(NSUInteger)sendLogInterval;
- (void)setMaxSendLogRecordsValue:(uint32_t)maxSendLogRecords;
- (void)setLogValue:(NSString *)log;
- (void)setConsentTypeValue:(NSUInteger)consentType;
- (void)setRequestInEeaValue:(BOOL)isRequestInEea;
///是否开启加密
- (void)setEnableEncValue:(BOOL)enableEnc;



+ (instancetype)sharedInstance;

- (void)addLogWithAcType:(NSUInteger)acType params:(NSDictionary *)params;

- (void)startDCLogService;


@end
