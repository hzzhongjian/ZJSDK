//
//  WanjaTimeTools.h
//  WanjaCoreSDK
//
//  Created by guantou on 2023/10/10.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*
 *  关于时间的工具集
 */
@interface WanjaTimeTools : NSObject

//  获取时间戳--周二、四、六返回毫秒，其他时间返回秒。
+ (uint64_t)preventCheatingtimeStamp;
//  获取当前时间戳秒
+ (uint64_t)timeStamp;
//  获取当前时间戳毫秒
+ (uint64_t)mtimeStamp;
//  根据时间返回星期
+ (NSInteger)getWeekDayFordate:(NSTimeInterval)data;

//  保存APP安装时间和更新时间
+ (void)createAppInstallTimeAndUpdateTime;
//  获取APP安装时间
+ (uint64_t)getAppInstallTime;
//  获取APP更新时间
+ (uint64_t)getAppUpdateTime;

@end

NS_ASSUME_NONNULL_END
