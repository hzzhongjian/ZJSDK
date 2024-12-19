//
//  ZJSDKInitModel.h
//  ZJSDKCore
//
//  Created by 麻明康 on 2024/12/6.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZJSDKInitModel : NSObject

/**
 * SDK初始化的AppId
 */
@property (nonatomic, copy) NSString *appId;

/**
 * 用户标识, 如果需要设置流量分组，根据用户标识进行区分，则是必传，否则为可选,
 */
@property (nonatomic, copy) NSString *userId;

/**
 * 渠道ID, 如果需要设置流量分组，根据渠道ID进行区分，则是必传，否则为可选,
 */
@property (nonatomic, copy) NSString *channel;


/**
 * 媒体透传参数，如果需要设置流量分组则是必传，用户可以自定义参数，否则为可选,
 */
@property (nonatomic, strong) NSDictionary *app_extra;


- (instancetype)initWithAppId:(NSString *)appId
                       userId:(NSString *)userId
                      channel:(NSString *)channel
                    app_extra:(NSDictionary *)app_extra;

@end

NS_ASSUME_NONNULL_END
