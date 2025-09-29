//
//  KSAdRewardAdRetryTaskResult.h
//  KSUVideoAd
//
//  Created by 杜祥军 on 2025/9/13.
//

#import <Foundation/Foundation.h>
#if __has_include(<KSUModel/KSAdInfoData.h>)
#import <KSUModel/KSAdInfoData.h>
#else
#import "KSAdInfoData.h"
#endif

NS_ASSUME_NONNULL_BEGIN

@interface KSAdRewardAdRetryTaskResult : NSObject

@property (nonatomic, strong) KSAdInfoData *retryTaskInfo;
// 0:未知，1:已点击未转化，2：已成功转化，3：点击已失效
@property (nonatomic, assign) NSInteger conversionStatus;

@end

NS_ASSUME_NONNULL_END
