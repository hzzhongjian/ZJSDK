//
//  SMAlivedThread.h
//  WindSDK
//
//  Created by Codi on 2020/4/9.
//  Copyright © 2020 Codi. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface SMAlivedThread : NSObject

- (instancetype)initWithName:(NSString *)name;

/**
 执行任务

 @param task 任务
 */
- (void)executeTask:(void(^)(void))task;

/**
 停止执行任务的线程
 */
- (void)stop;

@end
