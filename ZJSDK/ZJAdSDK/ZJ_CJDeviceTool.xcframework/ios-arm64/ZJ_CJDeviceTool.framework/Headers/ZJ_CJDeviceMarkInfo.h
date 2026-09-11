//
//  ZJ_CJDeviceMarkInfo.h
//  ZJ_CJDeviceTool
//
//  文件作用：设备标识指纹采集入口。
//  负责功能：读取启动时间、系统文件时间、内存磁盘、机型语言等信号，并组装服务端 b_info JSON。
//  类定义：ZJ_CJDeviceMarkInfo 仅提供类方法，不持有实例状态。
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZJ_CJDeviceMarkInfo : NSObject

/**
 * 组装上报用的设备指纹 JSON（混淆 key：b01~b14）。
 * @return UTF-8 JSON 字符串；序列化失败时返回空串
 */
+ (NSString *)deviceInfoJSONString;

/**
 * 系统启动时间（KERN_BOOTTIME 秒）。
 * @return 十进制秒数字符串；读取失败返回空串
 */
+ (NSString *)bootTime;

/**
 * 系统更新时间：PublicInfo/MCMeta.plist 创建时间，保留 6 位小数。
 * @return 时间戳字符串；读取失败返回空串
 */
+ (NSString *)sysFileTime;

/**
 * 设备初始化时间：/var/mobile 的 birthtime，保留 9 位小数。
 * @return 时间戳字符串；读取失败返回空串
 */
+ (NSString *)deviceInitTime;

/**
 * 物理内存总容量。
 * @return 字节数字符串，取值 >= 0
 */
+ (NSString *)memory;

/**
 * 磁盘总容量。
 * @return 字节数字符串；失败时为 @"-1"
 */
+ (NSString *)disk;

/**
 * 设备 machine 编码（如 iPhone14,2）。
 * @return 非空字符串；失败返回空串
 */
+ (NSString *)machine;

@end

NS_ASSUME_NONNULL_END
