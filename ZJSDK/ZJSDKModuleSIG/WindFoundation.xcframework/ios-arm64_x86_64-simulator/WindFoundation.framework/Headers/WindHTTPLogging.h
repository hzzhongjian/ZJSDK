//
//  WindHTTPLogging.h
//  CocoaWindHTTPServer
//
//  Created by Single on 2018/5/18.
//  Copyright © 2018年 Single. All rights reserved.
//

#import <Foundation/Foundation.h>

#define WindCHSLog(level, frmt, ...) [WindHTTPLogging log:level format:frmt, ##__VA_ARGS__]

#define WindTHIS_FILE   self
#define WindTHIS_METHOD NSStringFromSelector(_cmd)

#define WindHTTP_LOG_FLAG_ERROR   (1 << 0)
#define WindHTTP_LOG_FLAG_WARN    (1 << 1)
#define WindHTTP_LOG_FLAG_INFO    (1 << 2)
#define WindHTTP_LOG_FLAG_VERBOSE (1 << 3)
#define WindHTTP_LOG_FLAG_TRACE   (1 << 4)

#define WindHTTP_LOG_LEVEL_OFF     0
#define WindHTTP_LOG_LEVEL_ERROR   (WindHTTP_LOG_LEVEL_OFF   | WindHTTP_LOG_FLAG_ERROR)
#define WindHTTP_LOG_LEVEL_WARN    (WindHTTP_LOG_LEVEL_ERROR | WindHTTP_LOG_FLAG_WARN)
#define WindHTTP_LOG_LEVEL_INFO    (WindHTTP_LOG_LEVEL_WARN  | WindHTTP_LOG_FLAG_INFO)
#define WindHTTP_LOG_LEVEL_VERBOSE (WindHTTP_LOG_LEVEL_INFO  | WindHTTP_LOG_FLAG_VERBOSE)

#define WindHTTP_LOG_ERROR   (httpLogLevel & WindHTTP_LOG_FLAG_ERROR)
#define WindHTTP_LOG_WARN    (httpLogLevel & WindHTTP_LOG_FLAG_WARN)
#define WindHTTP_LOG_INFO    (httpLogLevel & WindHTTP_LOG_FLAG_INFO)
#define WindHTTP_LOG_VERBOSE (httpLogLevel & WindHTTP_LOG_FLAG_VERBOSE)
#define WindHTTP_LOG_TRACE   (httpLogLevel & WindHTTP_LOG_FLAG_TRACE)

#define WindHTTPLogError(frmt, ...)    WindCHSLog(WindHTTP_LOG_ERROR,   frmt, ##__VA_ARGS__)
#define WindHTTPLogWarn(frmt, ...)     WindCHSLog(WindHTTP_LOG_WARN,    frmt, ##__VA_ARGS__)
#define WindHTTPLogInfo(frmt, ...)     WindCHSLog(WindHTTP_LOG_INFO,    frmt, ##__VA_ARGS__)
#define WindHTTPLogVerbose(frmt, ...)  WindCHSLog(WindHTTP_LOG_VERBOSE, frmt, ##__VA_ARGS__)
#define WindHTTPLogTrace()             WindCHSLog(WindHTTP_LOG_TRACE,   @"%@ : %@", WindTHIS_FILE, WindTHIS_METHOD)
#define WindHTTPLogTrace2(frmt, ...)   WindCHSLog(WindHTTP_LOG_TRACE,   frmt, ##__VA_ARGS__)


@interface WindHTTPLogging : NSObject

+ (void)log:(int)level format:(NSString *)format, ...;

@end
