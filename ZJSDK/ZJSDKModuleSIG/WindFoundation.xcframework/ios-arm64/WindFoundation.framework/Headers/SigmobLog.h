//
//  SMLog.h
//  SigmobDemo
//
//  Created by happyelements on 03/04/2018.
//  Copyright © 2018 Codi. All rights reserved.
//

#ifndef SMSIGLog_h
#define SMSIGLog_h

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, SIGLogLevel){
    SIGLogLevelDebug=2,
    SIGLogLevelInfo=4,
    SIGLogLevelWarning=6,
    SIGLogLevelError=8,
};

#define WindLog(level, sdkName, module, ...) \
{ \
    WindLogEx(level, sdkName, module, @(__FILE__), @(__PRETTY_FUNCTION__), __LINE__, nil, __VA_ARGS__); \
}

//! Log to Error level
#define WindFoundationLogDebug(module, ...)        WindLog(SIGLogLevelDebug, @"WF", module, __VA_ARGS__)
#define WindFoundationLogInfo(module, ...)        WindLog(SIGLogLevelInfo, @"WF", module, __VA_ARGS__)
#define WindFoundationLogWarning(module, ...)        WindLog(SIGLogLevelWarning, @"WF", module, __VA_ARGS__)
#define WindFoundationLogError(module, ...)        WindLog(SIGLogLevelError, @"WF", module, __VA_ARGS__)

#define WindLogDebug(module, ...)        WindLog(SIGLogLevelDebug, @"Sigmob", module, __VA_ARGS__)
#define WindLogInfo(module, ...)        WindLog(SIGLogLevelInfo, @"Sigmob", module, __VA_ARGS__)
#define WindLogWarning(module, ...)        WindLog(SIGLogLevelWarning, @"Sigmob", module, __VA_ARGS__)
#define WindLogError(module, ...)        WindLog(SIGLogLevelError, @"Sigmob", module, __VA_ARGS__)

#define WindmillLogDebug(module, ...)        WindLog(SIGLogLevelDebug, @"ToBid", module, __VA_ARGS__)
#define WindmillLogInfo(module, ...)        WindLog(SIGLogLevelInfo, @"ToBid", module, __VA_ARGS__)
#define WindmillLogWarning(module, ...)        WindLog(SIGLogLevelWarning, @"ToBid", module, __VA_ARGS__)
#define WindmillLogError(module, ...)        WindLog(SIGLogLevelError, @"ToBid", module, __VA_ARGS__)


FOUNDATION_EXPORT void WindLogEx(SIGLogLevel level,
                                   NSString *sdkName,
                                   NSString *module,
                                   NSString *file,
                                   NSString *function,
                                   unsigned int line,
                                   id __nullable contextObject,
                                   NSString *format, ...) NS_FORMAT_FUNCTION(8,9);

NS_ASSUME_NONNULL_END

#endif /* SMLog_h */
