//
//  WindHCDataReader.h
//  WindHTTPCache
//
//  Created by Single on 2017/8/11.
//  Copyright © 2017年 Single. All rights reserved.
//

#import <Foundation/Foundation.h>

@class WindHCDataReader;
@class WindHCDataRequest;
@class WindHCDataResponse;

@protocol WindHCDataReaderDelegate <NSObject>

- (void)wind_readerDidPrepare:(WindHCDataReader *)reader;
- (void)wind_readerHasAvailableData:(WindHCDataReader *)reader;
- (void)wind_reader:(WindHCDataReader *)reader didFailWithError:(NSError *)error;

@end

@interface WindHCDataReader : NSObject <NSLocking>

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

@property (nonatomic, weak) id <WindHCDataReaderDelegate> delegate;
@property (nonatomic, strong) id object;

@property (nonatomic, strong, readonly) WindHCDataRequest *request;
@property (nonatomic, strong, readonly) WindHCDataResponse *response;

@property (nonatomic, copy, readonly) NSError *error;

@property (nonatomic, readonly, getter=isPrepared) BOOL prepared;
@property (nonatomic, readonly, getter=isFinished) BOOL finished;
@property (nonatomic, readonly, getter=isClosed) BOOL closed;

@property (nonatomic, readonly) long long readedLength;
@property (nonatomic, readonly) double progress;

- (void)prepare;
- (void)close;

- (NSData *)readDataOfLength:(NSUInteger)length;

@end
