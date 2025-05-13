//
//  QMLog.h
//  QMAdSDK
//
//  Created by qusy on 2023/12/28.
//

#import <Foundation/Foundation.h>
typedef NS_ENUM(int, QMLoggingLevel) {
    kQMLoggingLevel_Info,
    kQMLoggingLevel_Warning,
    kQMLoggingLevel_Error,
};

extern void _QMLogMessage(QMLoggingLevel level, NSString *format, ...) NS_FORMAT_FUNCTION(2, 3);

#define QMLog(fmt, ...)         _QMLogMessage(kQMLoggingLevel_Info, @"%s: " fmt, __PRETTY_FUNCTION__, ##__VA_ARGS__)
#define QMLogWarning(fmt, ...)  _QMLogMessage(kQMLoggingLevel_Warning, @"%s: " fmt, __PRETTY_FUNCTION__, ##__VA_ARGS__)
#define QMLogError(fmt, ...)    _QMLogMessage(kQMLoggingLevel_Error, @"%s: " fmt, __PRETTY_FUNCTION__, ##__VA_ARGS__)

