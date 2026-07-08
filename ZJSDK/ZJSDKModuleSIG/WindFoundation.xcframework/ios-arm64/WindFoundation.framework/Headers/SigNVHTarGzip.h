//
//  NVHTarGzip.h
//  Pods
//
//  Created by Niels van Hoorn on 26/03/14.
//
//

#import <Foundation/Foundation.h>

@interface SigNVHTarGzip : NSObject

+ (SigNVHTarGzip *)sharedInstance;

// Sync API
- (BOOL)unTarFileAtPath:(NSString *)sourcePath toPath:(NSString *)destinationPath error:(NSError **)error;
- (BOOL)unGzipFileAtPath:(NSString *)sourcePath toPath:(NSString *)destinationPath error:(NSError **)error;
- (BOOL)unTarGzipFileAtPath:(NSString*)sourcePath toPath:(NSString*)destinationPath error:(NSError **)error;
- (BOOL)tarFileAtPath:(NSString *)sourcePath toPath:(NSString *)destinationPath error:(NSError**)error;
- (BOOL)gzipFileAtPath:(NSString *)sourcePath toPath:(NSString *)destinationPath error:(NSError **)error;
- (BOOL)tarGzipFileAtPath:(NSString*)sourcePath toPath:(NSString *)destinationPath error:(NSError **)error;

// Async API
- (void)unTarFileAtPath:(NSString *)sourcePath toPath:(NSString *)destinationPath completion:(void(^)(NSError *))completion;
- (void)unGzipFileAtPath:(NSString *)sourcePath toPath:(NSString *)destinationPath completion:(void(^)(NSError *))completion;
- (void)unTarGzipFileAtPath:(NSString*)sourcePath toPath:(NSString *)destinationPath completion:(void(^)(NSError *))completion;
- (void)tarFileAtPath:(NSString *)sourcePath toPath:(NSString *)destinationPath completion:(void(^)(NSError *))completion;
- (void)gzipFileAtPath:(NSString *)sourcePath toPath:(NSString *)destinationPath completion:(void(^)(NSError *))completion;
- (void)tarGzipFileAtPath:(NSString*)sourcePath toPath:(NSString *)destinationPath completion:(void(^)(NSError*))completion;

@end
