//
//  WanjaAdFeedbackModel.h
//  WanjaCore
//
//  Created by hongji cai on 2025/8/25.
//

#import <Foundation/Foundation.h>
#import "WanjaBaseModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface WanjaAdFeedbackBaseModel : WanjaBaseModel

@end

@interface WanjaAdFeedbackModel : WanjaAdFeedbackBaseModel
@property (nonatomic, copy) NSString *appId;
@property (nonatomic, copy) NSNumber *result;
//
@property (nonatomic, copy) NSString *slotId;
@property (nonatomic, copy) NSString *reqId;
//
@property (nonatomic, copy) NSString *extra;
@property (nonatomic, copy) NSNumber *ptime;
//
@property (nonatomic, copy) NSNumber *bid;
//
@property (nonatomic, copy) NSNumber *callback;

- (id)initWith:(NSString *)type;
@end

NS_ASSUME_NONNULL_END
