//
//  WanjaCoreSDKAdRequestModel+Builder.h
//  WanjaCoreSDK
//
//  Created by guantou on 2020/2/18.
//

#import "WanjaAdRequestModel.h"

NS_ASSUME_NONNULL_BEGIN

@class WanjaAdRequestModel;
@class WanjaAdRecordModel;

@interface WanjaAdRequestModel (Builder)

+ (NSData *)wanjaRequestWithRecordModel:(WanjaAdRecordModel *)model;

@end

NS_ASSUME_NONNULL_END
