//
//  ZJ_CJBaseAd.h
//  ZJ_CJAdSDK
//
//  Created by coderqi on 2025/12/19.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZJ_CJBaseAd : NSObject

/// 广告的拓展信息
@property (nonatomic, strong, readonly)NSMutableDictionary *extInfo;

- (BOOL)isReady;

@end

NS_ASSUME_NONNULL_END
