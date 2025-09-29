//
//  KSAdRewardAdRetryTaskUtil.h
//  KSURetryTaskUtil
//
//  Created by 杜祥军 on 2025/9/13.
//

#import <Foundation/Foundation.h>
#if __has_include(<KSUModel/KSAdInfoData.h>)
#import <KSUModel/KSAdInfoData.h>
#else
#import "KSAdInfoData.h"
#endif
#import "KSAdRewardAdRetryTaskResult.h"
#import <KSUModel/KSAdInfo.h>


NS_ASSUME_NONNULL_BEGIN

typedef void (^KSAdCompletionHandler)(BOOL success, NSError * _Nullable error);
typedef void (^KSAdRetryTaskResultListHandler)(NSArray<KSAdRewardAdRetryTaskResult *> * retryTaskResultList, BOOL success, NSError * _Nullable error);

@interface KSAdRewardAdRetryTaskUtil : NSObject

+ (instancetype)sharedInstance;

/**
 获取数据库中的缓存数据
 */
- (void)gainInfoFromDB;

- (void)storeRewardAdRetryTaskAdInfo:(KSAdInfo *)adInfo;

// 更新任务状态，实现跳转
- (void)rewardAdRetryTaskUpdate:(KSAdInfoData *)retryTaskInfo callback:(KSAdCompletionHandler)callback;

// 查询任务结果
- (void)getRewardRetryTaskStatus:(NSArray<KSAdInfoData *> *)retryTaskInfoList retryTaskCallback:(KSAdRetryTaskResultListHandler)retryResultCallback;

@end

NS_ASSUME_NONNULL_END
