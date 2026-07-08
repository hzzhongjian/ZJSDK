//
//  SMNetworkManager.h
//  SigmobDemo
//
//  Created by happyelements on 2018/3/28.
//  Copyright © 2018年 Codi. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SMNetworkManager : NSObject

+ (NSURLSessionDataTask *)GET:(NSString *)urlString
                  retryNumber:(NSInteger)retryNumber
            completionHandler:(void (^)(NSData *data, NSURLResponse *response, NSURLSessionDataTask *task, NSError *error))completionHandler;


+ (NSURLSessionDataTask *)GET:(NSString *)urlString
                            parameters:(id  )parameters
                            retryNumber:(NSInteger)retryNumber
                               success:(void (^)(NSURLSessionDataTask * , id ))success
                               failure:(void (^)(NSURLSessionDataTask * , NSError * ))failure;


@end
