//
//  KSAdRewardAdRetryTaskConversionContext.h
//  KSUConversion
//
//  Created by 杜祥军 on 2025/9/15.
//

#import <Foundation/Foundation.h>
#import <KSUModel/KSAdInfo.h>

NS_ASSUME_NONNULL_BEGIN

@interface KSAdRewardAdRetryTaskConversionContext : NSObject

- (instancetype)initWithAdnfo:(KSAdInfo *)adInfo;

- (void)openDeeplinkURLWithAdInfo:(KSAdInfo *)adInfo
                completionHandler:(void (^)(BOOL))completionHandler;

@end

NS_ASSUME_NONNULL_END
