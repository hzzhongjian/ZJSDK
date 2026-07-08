//
//  SMRequest.h
//  SigmobDemo
//
//  Created by happyelements on 04/04/2018.
//  Copyright © 2018 Codi. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface WindAdRequest : NSObject

/// 广告位ID
@property (nonatomic,copy) NSString *placementId;

/// 媒体用户ID
@property (nonatomic,copy, nullable) NSString *userId;

/// 用于服务端激励回调的扩展参数
@property (nonatomic,strong, nullable) NSDictionary<NSString *, NSString *> *options;

/// 用于打点信息的扩展参数
@property (nonatomic,strong, nullable) NSDictionary<NSString *, NSString *> *extra;

+ (instancetype)request;

@end

NS_ASSUME_NONNULL_END
