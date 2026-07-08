#import <WindFoundation/SMLog.h>

/**
 * The constant/variable/method responsible for controlling the current log level.
 **/
#ifndef SIG_LOG_LEVEL_DEF
    #define SIG_LOG_LEVEL_DEF smLogLevel
#endif

/**
 * Whether async should be used by log messages, excluding error messages that are always sent sync.
 **/
#ifndef SIG_LOG_ASYNC_ENABLED
    #define SIG_LOG_ASYNC_ENABLED YES
#endif

/**
 * These are the two macros that all other macros below compile into.
 * These big multiline macros makes all the other macros easier to read.
 **/
#define SIG_LOG_MACRO(isAsynchronous, lvl, flg, ctx, atag, fnct, frmt, ...) \
        [SMLog log : isAsynchronous                                     \
             level : lvl                                                \
              flag : flg                                                \
           context : ctx                                                \
              file : __FILE__                                           \
          function : fnct                                               \
              line : __LINE__                                           \
               tag : atag                                               \
            format : (frmt), ## __VA_ARGS__]

#define SIG_LOG_MACRO_TO_SMLOG(smlog, isAsynchronous, lvl, flg, ctx, atag, fnct, frmt, ...) \
        [smlog log : isAsynchronous                                     \
             level : lvl                                                \
              flag : flg                                                \
           context : ctx                                                \
              file : __FILE__                                           \
          function : fnct                                               \
              line : __LINE__                                           \
               tag : atag                                               \
            format : (frmt), ## __VA_ARGS__]


#define SIG_LOG_MAYBE(async, lvl, flg, ctx, tag, fnct, frmt, ...) \
        do { if(lvl & flg) SIG_LOG_MACRO(async, lvl, flg, ctx, tag, fnct, frmt, ##__VA_ARGS__); } while(0)

#define SIG_LOG_MAYBE_TO_SMLOG(smlog, async, lvl, flg, ctx, tag, fnct, frmt, ...) \
        do { if(lvl & flg) SIG_LOG_MACRO_TO_SMLOG(smlog, async, lvl, flg, ctx, tag, fnct, frmt, ##__VA_ARGS__); } while(0)

/**
 * Ready to use log macros with no context or tag.
 **/
#define SMLogError(frmt, ...)   SIG_LOG_MAYBE(NO,                SIG_LOG_LEVEL_DEF, SMLogFlagError,   0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define SMLogWarn(frmt, ...)    SIG_LOG_MAYBE(SIG_LOG_ASYNC_ENABLED, SIG_LOG_LEVEL_DEF, SMLogFlagWarning, 0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define SMLogInfo(frmt, ...)    SIG_LOG_MAYBE(SIG_LOG_ASYNC_ENABLED, SIG_LOG_LEVEL_DEF, SMLogFlagInfo,    0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define SMLogDebug(frmt, ...)   SIG_LOG_MAYBE(SIG_LOG_ASYNC_ENABLED, SIG_LOG_LEVEL_DEF, SMLogFlagDebug,   0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define SMLogVerbose(frmt, ...) SIG_LOG_MAYBE(SIG_LOG_ASYNC_ENABLED, SIG_LOG_LEVEL_DEF, SMLogFlagVerbose, 0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)

#define SMLogErrorToSMLog(smlog, frmt, ...)   SIG_LOG_MAYBE_TO_SMLOG(smlog, NO, SIG_LOG_LEVEL_DEF, SMLogFlagError,   0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define SMLogWarnToSMLog(smlog, frmt, ...)    SIG_LOG_MAYBE_TO_SMLOG(smlog, SIG_LOG_ASYNC_ENABLED, SIG_LOG_LEVEL_DEF, SMLogFlagWarning, 0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define SMLogInfoToSMLog(smlog, frmt, ...)    SIG_LOG_MAYBE_TO_SMLOG(smlog, SIG_LOG_ASYNC_ENABLED, SIG_LOG_LEVEL_DEF, SMLogFlagInfo,    0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define SMLogDebugToSMLog(smlog, frmt, ...)   SIG_LOG_MAYBE_TO_SMLOG(smlog, SIG_LOG_ASYNC_ENABLED, SIG_LOG_LEVEL_DEF, SMLogFlagDebug,   0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define SMLogVerboseToSMLog(smlog, frmt, ...) SIG_LOG_MAYBE_TO_SMLOG(smlog, SIG_LOG_ASYNC_ENABLED, SIG_LOG_LEVEL_DEF, SMLogFlagVerbose, 0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
