//
//  ZJ_MJKAdError.h
//  ZJ_MJKAdOS
//
//  Created by Harry Jiang on 29/4/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZJ_MJKAdError : NSObject

@property (nonatomic, assign)NSInteger code;

@property (nonatomic, strong)NSString* msg;

/**
 初始化
 **/
- (instancetype)init:(NSInteger)code msg:(NSString *)msg;

@end

NS_ASSUME_NONNULL_END
