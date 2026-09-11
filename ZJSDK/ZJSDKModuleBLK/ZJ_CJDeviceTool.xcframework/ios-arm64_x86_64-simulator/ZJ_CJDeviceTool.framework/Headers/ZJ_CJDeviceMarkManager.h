//
//  ZJ_CJDeviceMarkManager.h
//  ZJ_CJDeviceTool
//
//  文件作用：设备标识获取与本地缓存的对外入口。
//  负责功能：读取 UserDefaults 缓存、按需请求服务端、回写 m5r/m5rs。
//  类定义：ZJ_CJDeviceMarkManager 单例，串行队列保护请求状态。
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZJ_CJDeviceMarkManager : NSObject

/**
 * 获取单例。
 * @return 全局唯一实例
 */
+ (instancetype)sharedInstance;

/**
 * 配置后续网络请求使用的媒体 ID 与 SDK 版本。
 * @param appId 媒体应用 ID，写入请求 mid；nil/空串时 mid 为 0
 * @param sdkVersion SDK 版本号，写入请求 v；nil 按空串处理
 */
- (void)configureWithAppId:(nullable NSString *)appId
                sdkVersion:(nullable NSString *)sdkVersion;

/**
 * 异步获取设备标识：有缓存直接回调，无缓存则请求服务端。
 * @param completion 完成回调；mark 为逗号拼接的 version_mark，valList 对应 m5rs
 */
- (void)getDeviceMarkWithCompletion:(void(^)(NSString * _Nullable mark,
                                             NSArray * _Nullable valList,
                                             NSError * _Nullable error))completion;

/**
 * 同步读取本地缓存的设备标识字符串（对应广告字段 m5r）。
 * @return 缓存字符串；无缓存返回 nil
 */
- (nullable NSString *)cachedDeviceMarkString;

/**
 * 同步读取本地缓存的设备标识明细列表（对应广告字段 m5rs）。
 * @return 非空数组；无缓存返回 nil
 */
- (nullable NSArray *)cachedDeviceMarkValList;

/**
 * 获取SDK版本号
 */
+ (NSString *)SDKVersion;

@end

NS_ASSUME_NONNULL_END
