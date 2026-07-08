//
//  CLHTTPRequestSerializer.h
//  CLNetworkDemo
//
//  Created by Codi on 2017/3/31.
//  Copyright © 2017年 Codi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WindFoundation/SMThreadSafeDictionary.h>

@interface SMHTTPRequestSerializer : NSObject

@property (readwrite, nonatomic, strong) NSMutableDictionary *mutableHTTPRequestHeaders;

@property (readonly, nonatomic, strong) SMThreadSafeDictionary  *HTTPRequestHeaders;

@property (nonatomic, strong, readonly) NSString *urlString;


@property (nonatomic,assign) NSInteger timeoutInterval;

/**
 HTTP methods for which serialized requests will encode parameters as a query string. `GET`, `HEAD`, and `DELETE` by default.
 */
@property (nonatomic, strong) NSSet <NSString *> *HTTPMethodsEncodingParametersInURI;


/**
 NSUTF8StringEncoding by default.
 */
@property (nonatomic, assign) NSStringEncoding stringEncoding;



+ (instancetype)serializer;


#pragma mark -

- (NSMutableURLRequest *)requestWithMethod:(NSString *)method
                                 URLString:(NSString *)URLString
                                parameters:(id)parameters
                                     error:(NSError *__autoreleasing *)error;


@end
