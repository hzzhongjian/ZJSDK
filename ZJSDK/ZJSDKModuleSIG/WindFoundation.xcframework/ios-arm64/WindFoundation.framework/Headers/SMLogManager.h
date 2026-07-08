//
//  SMLogManager.h
//  SigmobDemo
//
//  Created by happyelements on 03/04/2018.
//  Copyright © 2018 Codi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WindFoundation/SMLog.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^SMAdDebugCallBack)(NSString * _Nullable msg);

@interface SMLogManager : NSObject

@property (nonatomic,assign) BOOL enableDebug;

@property (nonatomic,assign) SMLogLevel logLevel;

+ (instancetype)sharedInstance;

- (void)configLogServices;



NS_ASSUME_NONNULL_END

@end


