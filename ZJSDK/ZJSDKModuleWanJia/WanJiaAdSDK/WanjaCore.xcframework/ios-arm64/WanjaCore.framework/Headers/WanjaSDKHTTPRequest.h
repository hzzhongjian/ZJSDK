//
//  WanjaCoreSDKHTTPRequest.h
//  WanjaCoreSDK
//
//  Created by guantou on 2019/12/9.
//

#import <Foundation/Foundation.h>
#import "WanjaHttpRequestType.h"

NS_ASSUME_NONNULL_BEGIN

typedef void(^NormalGetDataBlock)(NSDictionary * __nullable);
/**
 请求广告worker
*/
@interface WanjaSDKHTTPRequest : NSObject

+ (WanjaSDKHTTPRequest *)shareInstance;

@property (atomic, copy) NSString *errorReportUrl;

/**
 发起广告请求
 */
- (void)beginAdvertisingHTTPRequestWithData:(NSData *)data
                                 requestURL:(NSString *)requestURL
                               successBlock:(WanjaResponseSuccessWithModel)successBlock
                               failureBlock:(WanjaResponseFailWithError)failureBlock;
- (void)beginAdvertisingHTTPRequestWithData:(NSData *)data
                                 requestURL:(NSString *)requestURL
                                    timeOut: (double)timeInterval
                               successBlock:(WanjaResponseSuccessWithModel)successBlock
                               failureBlock:(WanjaResponseFailWithError)failureBlock;

//发起其它本公司的服务请求
- (void)beginCommonHTTPRequestWithData:(NSData *)data
                                 modelClass:(Class)modelClass
                                 requestURL:(NSString *)requestURL
                               successBlock:(WanjaResponseSuccessWithModel)successBlock
                          failureBlock:(WanjaResponseFailWithError)failureBlock;

//请求外部数据
- (void)wanjaGetDataWithURL:(NSString *)viewURL handler:(NormalGetDataBlock)handler;

@end

NS_ASSUME_NONNULL_END
