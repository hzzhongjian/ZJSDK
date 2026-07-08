//
//  SMDeviceTool.h
//  SigmobDemo
//
//  Created by happyelements on 2018/3/27.
//  Copyright © 2018年 Codi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface SMDeviceTool : NSObject

+ (instancetype _Nullable)sharedInstance;
//app的方向
@property (nonatomic,strong, readonly, nullable) NSNumber *orientation;
//app版本号
@property (nonatomic, strong, readonly, nullable) NSString * appVerion;
//app name
@property (nonatomic, strong, readonly, nullable) NSString *appname;
//电池电量
@property (nonatomic, assign, readonly) CGFloat batteryLevel;
//电池状态
@property (nonatomic, assign, readonly) uint32_t batteryState;
//获取时区
@property (nonatomic, strong, readonly, nullable) NSString *timeZone;
@property (nonatomic, strong, readonly, nullable) NSString *secondsFromGMT;
/**ua*/
@property (nonatomic, copy, readonly, nullable) NSString *userAgent;
/**位置信息*/
@property (nonatomic,assign, readonly) float lat;
@property (nonatomic,assign, readonly) float lon;
@property (nonatomic,assign, readonly) BOOL hasLocation;
//当前系统版本号
@property (nonatomic, strong, readonly, nullable) NSString *systemVersion;
//device_model
@property (nonatomic, strong, readonly, nullable) NSString *device_model;
@property (nonatomic, strong, readonly, nullable) NSString *device_name;
//广告位标识符idfa
@property (nonatomic, strong, readonly, nullable) NSString *idfa;

//广告位标识符idfv
@property (nonatomic, strong, readonly, nullable) NSString *idfv;
@property (nonatomic, strong, readonly, nullable) NSString *bundleID;
@property (nonatomic, strong, readonly, nullable) NSString *internalName;
@property (nonatomic, strong, readonly, nullable) NSNumber *dpi;
@property (nonatomic, strong, readonly, nullable) NSString *locale;
@property (nonatomic,assign, readonly) BOOL isJailBreak;
@property (nonatomic,assign, readonly) BOOL battery_saver_state;
@property (nonatomic, assign, readonly) CGFloat screen_width;//pixeis
@property (nonatomic, assign, readonly) CGFloat screen_height;//pixeis
/**运营商*/
@property (nonatomic,strong, readonly, nullable) NSString *carrier;
@property (nonatomic,strong, readonly, nullable) NSString *carrierName;
/**国家代码*/
@property (nonatomic, strong, readonly, nullable) NSString *countryCode;
/**语言*/
@property (nonatomic, strong, readonly, nullable) NSString *languageCode;
/// 客服端自己生成的udid
@property (nonatomic,strong, readonly, nullable) NSString *udid;
/// 后端生成的uid
@property (nonatomic,strong, readonly, nullable) NSString *uid;
/// 系统的更新时间
@property (nonatomic, strong, readonly, nullable) NSString *sysUdpTm;
/// 系统的开机时间
@property (nonatomic, assign, readonly) int64_t uptime;
//adx使用
@property (nonatomic, strong, readonly, nullable) NSString *bMTm;
@property (nonatomic, strong, readonly, nullable) NSString *uMTm;

/// mntId
@property (nonatomic, strong, readonly, nullable) NSString *fmd;
/// 设备初始化时间
@property (nonatomic, strong, readonly, nullable) NSString *devTm;

/// 屏幕宽
@property (nonatomic, assign, readonly) CGFloat screenWidth;

/// 屏幕高
@property (nonatomic, assign, readonly) CGFloat screenHeight;

/** 媒体应用安装时间，单位为秒 */
@property(nonatomic, assign, readonly) int64_t installTime;

@property (nonatomic, copy, readonly, nullable) NSString *allIPv6;


#pragma mark - Disk Space
///=============================================================================
/// @name Disk Space
///=============================================================================
// 系统总内存空间
@property (nonatomic, assign, readonly) int64_t totalDiskSpack;

@property (nonatomic, assign, readonly) int64_t freeDiskSpack;

@property (nonatomic, assign, readonly) int64_t totalMemory;


#pragma mark - Network Information
///=============================================================================
/// @name Network Information
///=============================================================================
- (UIWindow * _Nullable)getKeyWindow;
/** 获取设备支持的方向 */
- (UIInterfaceOrientationMask)supportOrientationMask;
- (NSString * _Nullable)getDcSessionId;
//每次会生成一个unique id
- (NSString * _Nullable)getUniqueId;
/**获取设备类型(1:iphone;2:ipad;3:ipod;0:未知)*/
-(uint32_t)getDeviceType;
-(NSUInteger) getWindSeqId;
- (NSUInteger)getSigSeqId;
/**获取网络状态(100:wifi;2:2g;3:3g;4:4g;0:未知)*/
-(uint32_t)getNetStatus;
- (BOOL)hasAlwaysKey;
- (BOOL)hasWhenInUseKey;
/**获取系统当前时间戳(s)*/
- (long)getCurrentTimestamp;
/**获取系统当前时间戳(ms)*/
- (long long)currentTimeMillis;
/* 判断是否是iphone x系列的手机 */
- (BOOL)isIPhoneXSeries;
- (BOOL)isHTTPEnable;
- (void)updateUid:(NSString * _Nullable)uid;
- (NSMutableArray<NSString*> * _Nullable)getSKAdNetworkIdsArray;
- (BOOL)isAdvertisingTrackingEnabled;
- (NSUInteger)trackingAuthorizationStatus;
- (CGRect)getForecastBounds:(NSUInteger)forecastOri;

/// 可选预热
- (void)preload;
@end
