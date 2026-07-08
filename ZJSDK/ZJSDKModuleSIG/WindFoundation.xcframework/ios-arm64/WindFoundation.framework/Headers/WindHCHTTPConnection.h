//
//  WindHCHTTPConnection.h
//  WindHTTPCache
//
//  Created by Single on 2017/8/10.
//  Copyright © 2017年 Single. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WindFoundation/WindHCHTTPHeader.h>

@interface WindHCHTTPConnection : WindHTTPConnection

+ (NSString *)URITokenPing;
+ (NSString *)URITokenPlaceHolder;
+ (NSString *)URITokenLastPathComponent;

@end
