//
//  SMRequestManager.h
//  SigmobDemo
//
//  Created by happyelements on 2018/3/28.
//  Copyright © 2018年 Codi. All rights reserved.
//

#import <Foundation/Foundation.h>



typedef void(^RequestCompletedBlock)(NSURLSessionDataTask * dataTask, id responseObject, NSError *error);

@interface SMRequestManager : NSObject



+ (instancetype)manager;


/**
 track get

 @param url trackingUrl
 */
- (void)getTrackingUrl:(NSString *)url retryNumber:(NSInteger)retryCount completionHandler:(void (^)(NSData *data, NSURLResponse *response, NSURLSessionDataTask *task, NSError *error))completionHandler;

@end



