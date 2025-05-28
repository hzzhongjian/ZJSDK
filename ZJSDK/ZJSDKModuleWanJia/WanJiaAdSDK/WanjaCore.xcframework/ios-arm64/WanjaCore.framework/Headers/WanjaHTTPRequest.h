//
//  WanjaHTTPRequest.h
//  WanjaCoreSDK
//
//  Created by guantou on 2019/12/9.
//

#import <Foundation/Foundation.h>
#import "WanjaHttpRequestType.h"

NS_ASSUME_NONNULL_BEGIN

/**
 请求管理类
 */
@interface WanjaHTTPRequest : NSObject

@property (nonatomic, assign) NSTimeInterval timeoutInterval;

+ (WanjaHTTPRequest *)shareInstance;

/**
 POST请求，传入加密data
 */
+ (WanjaURLSessionDataTask *)HTTPSerializerPOSTWithUrlString:(NSString *)urlString
                                                  parameters:(id)parameters
                                               backQueueName:(dispatch_queue_t)backQueueName
                                                successBlock:(WanjaResponseSuccess)successBlock
                                                failureBlock:(WanjaResponseFail)failureBlock;
+ (WanjaURLSessionDataTask *)HTTPSerializerPOSTWithUrlString:(NSString *)urlString
                                                  parameters:(id)parameters
                                               backQueueName:(dispatch_queue_t)backQueueName
                                                   timeOut: (double)timeInterval
                                                successBlock:(WanjaResponseSuccess)successBlock
                                              failureBlock:(WanjaResponseFail)failureBlock;

/**
 正常GET请求
 */
+ (WanjaURLSessionDataTask *)requestGETWithUrlString:(NSString *)urlString
                                       backQueueName:(dispatch_queue_t)backQueueName
                                        successBlock:(WanjaResponseSuccess __nullable)successBlock
                                        failureBlock:(WanjaResponseFail __nullable)failureBlock;

/**
 修改userAgent的GET请求
 */
+ (WanjaURLSessionDataTask *)requestGETWithUrlString:(NSString *)urlString
                                           userAgent:(NSString *)userAgent
                                       backQueueName:(dispatch_queue_t)backQueueName
                                        successBlock:(WanjaResponseSuccess)successBlock
                                        failureBlock:(WanjaResponseFail)failureBlock;

///**
// 正常POST请求
// */
//+ (WanjaURLSessionDataTask *)requestPOSTWithUrlString:(NSString *)urlString
//                                           parameters:(id)parameters
//                                        backQueueName:(dispatch_queue_t)backQueueName
//                                         successBlock:(WanjaResponseSuccess)successBlock
//                                         failureBlock:(WanjaResponseFail)failureBlock;

/**
 正常图片下载
 */
+ (WanjaURLSessionDataTask *)downLoadImage:(NSString *)imageURL
                              successBlock:(WanjaResponseSuccess)successBlock
                              failureBlock:(WanjaResponseFail)failureBlock;

/**
 上传单文件
*/
+ (WanjaURLSessionDataTask *)uploadTaskUrl:(NSString *__nullable)uploadPage
                                    params:(NSDictionary *__nullable)params
                                  filePath:(NSString *__nullable)filePath
                                  fileName:(NSString *__nullable)fileName
                              successBlock:(WanjaResponseSuccess __nullable)successBlock
                              failureBlock:(WanjaResponseFail __nullable)failureBlock;

///**
// Crash收集
// */
//+ (WanjaURLSessionDataTask *)requestWithCrash;

@end

NS_ASSUME_NONNULL_END
