//
//  WindHCDataLoader.h
//  WindHTTPCache
//
//  Created by Single on 2018/6/7.
//  Copyright © 2018 Single. All rights reserved.
//

#import <Foundation/Foundation.h>

@class WindHCDataLoader;
@class WindHCDataRequest;
@class WindHCDataResponse;

@protocol WindHCDataLoaderDelegate <NSObject>

@optional
- (void)wind_loaderDidFinish:(WindHCDataLoader *)loader;
- (void)wind_loader:(WindHCDataLoader *)loader didFailWithError:(NSError *)error;
- (void)wind_loader:(WindHCDataLoader *)loader didChangeProgress:(double)progress;

@end

@interface WindHCDataLoader : NSObject

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

@property (nonatomic, weak) id <WindHCDataLoaderDelegate> delegate;
@property (nonatomic, strong) id object;

@property (nonatomic, strong, readonly) WindHCDataRequest *request;
@property (nonatomic, strong, readonly) WindHCDataResponse *response;

@property (nonatomic, copy, readonly) NSError *error;

@property (nonatomic, readonly, getter=isFinished) BOOL finished;
@property (nonatomic, readonly, getter=isClosed) BOOL closed;

@property (nonatomic, readonly) long long loadedLength;
@property (nonatomic, readonly) double progress;
/// 透传
@property (nonatomic, weak) id obj;

- (void)prepare;
- (void)close;

@end
