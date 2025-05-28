//
//  WanjaAdvertLog.h
//  WanjaAD
//
//  Created by zwf on 2020/12/29.
//

#import <UIKit/UIKit.h>

#ifdef DEBUG
# define WanjaLog(fmt, ...) [[WanjaAdvertLog sharedInstance] logDebugMessage:[NSString stringWithFormat:fmt, ##__VA_ARGS__]];
#else
# define WanjaLog(fmt, ...)
#endif

//可以开放给媒体查看，通过开关showDebugLog控制
# define WanjaLogPrint(fmt, ...) [[WanjaAdvertLog sharedInstance] logDebugMessage:[NSString stringWithFormat:fmt, ##__VA_ARGS__]];

NS_ASSUME_NONNULL_BEGIN

@interface WanjaAdvertLog : NSObject

@property (nonatomic, assign) BOOL showDebugLog;
@property (nonatomic, strong) UITextView *textView;

+ (WanjaAdvertLog *)sharedInstance;

- (void)logDebugMessage:(NSString *)message;

@end

NS_ASSUME_NONNULL_END
