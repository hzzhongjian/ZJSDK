//
//  WindAdOptions.h
//  WindSDK
//
//  Created by Codi on 2021/11/1.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface WindAdOptions : NSObject
/// Sigmob平台申请的appId
@property (copy, nonatomic, readonly) NSString* appId;
/// Sigmob平台申请的appKey
@property (copy, nonatomic, readonly) NSString* appKey;


- (instancetype)initWithAppId:(NSString *)appId appKey:(NSString *)appKey;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

