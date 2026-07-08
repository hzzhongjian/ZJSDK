//
//  WindHCHTTPResponse.h
//  WindHTTPCache
//
//  Created by Single on 2017/8/10.
//  Copyright © 2017年 Single. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WindFoundation/WindHCHTTPHeader.h>

@class WindHCHTTPConnection;
@class WindHCDataRequest;

@interface WindHCHTTPResponse : NSObject <WindHTTPResponse>

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithConnection:(WindHCHTTPConnection *)connection dataRequest:(WindHCDataRequest *)dataRequest NS_DESIGNATED_INITIALIZER;

@end
