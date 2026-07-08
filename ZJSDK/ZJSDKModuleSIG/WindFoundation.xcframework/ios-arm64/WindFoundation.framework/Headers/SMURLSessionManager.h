//
//  CLURLSessionManager.h
//  CLNetworkDemo
//
//  Created by Codi on 2017/3/31.
//  Copyright © 2017年 Codi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WindFoundation/SMHTTPRequestSerializer.h>

@interface SMURLSessionManager : NSObject<NSURLSessionDelegate, NSURLSessionDownloadDelegate>

@property (nonatomic,strong) NSOperationQueue * _Nullable operationQueue;

@property (nonatomic,strong) SMHTTPRequestSerializer * _Nullable requestSerializer;

@property (readwrite, nonatomic, strong) NSURLSession * _Nullable session;

@property (readwrite, nonatomic, strong) NSURLSessionConfiguration * _Nullable sessionConfiguration;

@property (nonatomic, strong, nullable) NSURL *baseURL;

@property (readwrite, nonatomic, strong) NSLock * _Nullable lock;
@property (readonly, nonatomic, copy) NSString * _Nullable taskDescriptionForSessionTasks;
@property (readwrite, nonatomic, strong) NSMutableDictionary * _Nullable mutableTaskDelegatesKeyedByTaskIdentifier;



+ (instancetype _Nullable )manager;

+ (instancetype _Nullable)backgroundURLSession;

- (instancetype _Nullable )initWithSessionConfiguration:(NSURLSessionConfiguration *_Nullable)configuration;


/**
 POST请求

 @param urlString 地址
 @param parameters 参数
 @param uploadProgress 上传进度
 @param success 成功
 @param failure 失败
 @return value NSURLSessionDataTask
 */
- (NSURLSessionDataTask *_Nullable)POST:(NSString *_Nullable)urlString
                    parameters:(id _Nullable )parameters
                      progress:(void (^_Nullable)(NSProgress * _Nonnull))uploadProgress
                       success:(void (^_Nullable)(NSURLSessionDataTask * _Nonnull, id _Nullable))success
                       failure:(void (^_Nullable)(NSURLSessionDataTask * _Nullable, NSError * _Nonnull))failure;


- (NSURLSessionDataTask *_Nullable)POST:(NSString *_Nullable)urlString
                             parameters:(id _Nullable )parameters
                                success:(void (^_Nullable)(NSURLSessionDataTask * _Nonnull, id _Nullable))success
                                failure:(void (^_Nullable)(NSURLSessionDataTask * _Nullable, NSError * _Nonnull))failure;



/**
 POST + NSURLRequest

 @param request 构造的request
 @param success 成功回调
 @param failure 失败回调
 @return NSURLSessionDataTask
 */
- (NSURLSessionDataTask *_Nullable)POST:(NSURLRequest *_Nullable)request
                                success:(void (^_Nullable)(NSURLSessionDataTask * _Nonnull, id _Nullable))success
                                failure:(void (^_Nullable)(NSURLSessionDataTask * _Nullable, NSError * _Nonnull))failure;





/**
 GET请求

 @param urlString 请求地址
 @param parameters 参数
 @param downloadProgress nil
 @param success success block
 @param failure failure block
 @return value NSURLSessionDataTask
 */
- (NSURLSessionDataTask *_Nullable)GET:(NSString *_Nullable)urlString
                   parameters:(id _Nullable )parameters
                     progress:(void (^_Nullable)(NSProgress * _Nonnull))downloadProgress
                      success:(void (^_Nullable)(NSURLSessionDataTask * _Nonnull, id _Nullable))success
                      failure:(void (^_Nullable)(NSURLSessionDataTask * _Nullable, NSError * _Nonnull))failure;

- (NSURLSessionDataTask *_Nullable)GET:(NSString *_Nullable)urlString
                            parameters:(id _Nullable )parameters
                               success:(void (^_Nullable)(NSURLSessionDataTask * _Nonnull, id _Nullable))success
                               failure:(void (^_Nullable)(NSURLSessionDataTask * _Nullable, NSError * _Nonnull))failure;



- (NSURLSessionDataTask *_Nullable)GET:(NSString *_Nullable)urlString
                     completionHandler:(void (^_Nullable)(NSData * _Nullable data, NSURLResponse * _Nullable response, NSURLSessionDataTask * _Nullable task, NSError * _Nullable error))completionHandler;


/**
 DELETE请求

 @param urlString 请求地址
 @param parameters 参数
 @param success success block
 @param failure failure block
 @return value NSURLSessionDataTask
 */
- (NSURLSessionDataTask *_Nullable)DELETE:(NSString *_Nullable)urlString
                      parameters:(id _Nullable )parameters
                         success:(void (^_Nullable)(NSURLSessionDataTask * _Nullable task, id _Nullable responseObject))success
                         failure:(void (^_Nullable)(NSURLSessionDataTask * _Nullable task, NSError * _Nullable error))failure;




/**
 PUT请求

 @param urlString urlString 请求地址
 @param parameters parameters 参数
 @param success success success block
 @param failure failure failure block
 @return value NSURLSessionDataTask
 */
- (nullable NSURLSessionDataTask *)PUT:(NSString *_Nullable)urlString
                            parameters:(nullable id)parameters
                               success:(nullable void (^)(NSURLSessionDataTask * _Nullable task, id _Nullable responseObject))success
                               failure:(nullable void (^)(NSURLSessionDataTask * _Nullable task, NSError * _Nullable error))failure;





/**
 HEAD请求

 @param urlString urlString 请求地址
 @param parameters parameters 参数
 @param success success success block
 @param failure failure failure block
 @return value NSURLSessionDataTask
 */
- (nullable NSURLSessionDataTask *)HEAD:(NSString *_Nullable)urlString
                             parameters:(nullable id)parameters
                                success:(nullable void (^)(NSURLSessionDataTask * _Nullable task))success
                                failure:(nullable void (^)(NSURLSessionDataTask * _Nullable task, NSError * _Nullable error))failure;




/**
 DOWNLOAD请求

 @param request 请求NSURLRequest
 @param downloadProgressBlock download progress block
 @param destination 目标地址
 @param completionHandler 完成回调
 @return value NSURLSessionDownloadTask
 */
- (NSURLSessionDownloadTask *_Nullable)downloadTaskWithRequest:(NSURLRequest *_Nullable)request
                                             progress:(nullable void (^)(NSProgress * _Nullable downloadProgress))downloadProgressBlock
                                          destination:(nullable NSURL * _Nullable (^)(NSURL * _Nullable targetPath, NSURLResponse * _Nullable response))destination
                                    completionHandler:(nullable void (^)(NSURLResponse * _Nullable response, NSURL * _Nullable filePath, NSError * _Nullable error))completionHandler;


- (NSURLSessionDownloadTask *_Nullable)downloadTaskWithResumeData:(NSData *_Nullable)resumeData
                                                progress:(nullable void (^)(NSProgress * _Nullable downloadProgress))downloadProgressBlock
                                             destination:(nullable NSURL * _Nullable (^)(NSURL * _Nullable targetPath, NSURLResponse * _Nullable response))destination
                                       completionHandler:(nullable void (^)(NSURLResponse * _Nullable response, NSURL * _Nullable filePath, NSError * _Nullable error))completionHandler;


@end
