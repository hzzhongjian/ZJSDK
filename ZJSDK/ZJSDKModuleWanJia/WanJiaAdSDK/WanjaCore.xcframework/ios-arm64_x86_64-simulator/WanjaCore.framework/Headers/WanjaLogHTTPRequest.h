//
//  WanjaLogHTTPRequest.h
//  WanjaCoreSDK
//
//  Created by guantou on 2019/12/9.
//

#import <Foundation/Foundation.h>
#import "WanjaHttpRequestType.h"

NS_ASSUME_NONNULL_BEGIN

/**
 上传日志worker
*/
@interface WanjaLogHTTPRequest : NSObject

+ (WanjaLogHTTPRequest *)shareInstance;

/**
 发送时时Log请求
 */
- (void)beginLogHTTPRequestWithURL:(NSString *)url
                      successBlock:(WanjaResponseSuccessWithModel)successBlock
                      failureBlock:(WanjaResponseFailWithError)failureBlock
                            iSSpin:(BOOL)spin;

- (void)beginOfflineLogHTTPRequestWithURL:(NSString *)url
                                 filePath:(NSString *)filePath
                                 fileName:(NSString *)fileName
                             successBlock:(WanjaResponseSuccessWithModel)successBlock
                             failureBlock:(WanjaResponseFailWithError)failureBlock;

@end

NS_ASSUME_NONNULL_END
