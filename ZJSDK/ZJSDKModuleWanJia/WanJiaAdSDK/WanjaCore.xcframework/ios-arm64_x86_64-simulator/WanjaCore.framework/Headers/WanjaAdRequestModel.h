//
//  WanjaCoreSDKAdRequestModel.h
//  WanjaCoreSDK
//
//  Created by guantou on 2020/2/17.
//

#import "WanjaBaseModel.h"
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class WanjaGeoModel;
@class WanjaDevInfoModel;
@class WanjaEnvInfoModel;
@class WanjaAdReqInfoModel;
@class WanjaSdidModel;

/**
 广告请求的model
*/
@interface WanjaAdRequestModel : WanjaBaseModel

//  reqid
@property (nonatomic, copy) NSString *reqid;
//  SDK版本号
@property (nonatomic, copy) NSString *version;
//  请求来源    0:未知 1:移动应用 2:移动Web 3:PC 4:测试
@property (nonatomic, copy) NSString *srcType;
//  广告请求类型  0:未知 1:广告请求 2:广告WIFI预加载
@property (nonatomic, copy) NSString *reqType;
//  请求时间戳（毫秒）
@property (nonatomic, assign) uint64_t timeStamp;
//  广告位id
@property (nonatomic, copy) NSString *appid;
//  设备model
@property (nonatomic, strong) WanjaDevInfoModel *devInfo;
//  用户信息
@property (nonatomic, strong) WanjaEnvInfoModel *envInfo;
//  广告信息
@property (nonatomic, strong) NSMutableArray<WanjaAdReqInfoModel *> *adReqInfo;
//  app版本
@property (nonatomic, copy) NSString *appVersion;
//  app包名
@property (nonatomic, copy) NSString *apkName;
//  安装时间
@property (nonatomic, assign) uint64_t appInstallTime;
//  更新时间
@property (nonatomic, assign) uint64_t appUpdateTime;
//  app名字
@property (nonatomic, copy) NSString *appName;
//  app包名
@property (nonatomic, copy) NSString *packageName;
//idfa和caid的来源
@property (nonatomic, assign) NSInteger idfaM;
@property (nonatomic, assign) NSInteger caidM;

@end

@interface WanjaDevInfoModel : WanjaBaseModel

//  SDK唯一标识
@property (nonatomic, copy) NSString *sdkUID;
//  设备唯一标识
@property (nonatomic, copy) NSString *idfa;
//  设备mac地址
@property (nonatomic, copy) NSString *mac;
//  设备系统版本
@property (nonatomic, copy) NSString *os;
//  平台类型    0:未知 1:ios 2:android 3:其他
@property (nonatomic, copy) NSString *platform;
//  设备类型    0:未知 1:移动电话 2:平板 3:穿戴设备 4:PC 5:其他设备
@property (nonatomic, copy) NSString *devType;
//  设备厂商
@property (nonatomic, copy) NSString *brand;
//  设备型号
@property (nonatomic, copy) NSString *model;
//  屏幕像素
@property (nonatomic, copy) NSString *resolution;
//  屏幕大小
@property (nonatomic, copy) NSString *screenSize;
//  屏幕密度
@property (nonatomic, copy) NSString *density;
//  wifi名称
@property (nonatomic, copy) NSString *wifi;//70:BB:E9:9E:CD:0F,Wanja3-5G",
//  设备CPU
@property (nonatomic, copy) NSString *cpu;
//  是否越狱
@property (nonatomic, copy) NSString *root;
//系统启动时间
@property (nonatomic, copy) NSString *bootMark;
//系统更新时间
@property (nonatomic, copy) NSString *updateMark;
//caid信息
@property (nonatomic, strong) NSArray<WanjaSdidModel *> *iosidInfo;
//paid信息
@property (nonatomic, copy) NSString *paid;
//idfv信息
@property (nonatomic, copy) NSString *idfv;

//有的客户需要合成caid的14个原始参数
@property (nonatomic, copy) NSString *physicalMemory;//物理内存
@property (nonatomic, copy) NSString *harddiskSize;//磁盘大小
@property (nonatomic, copy) NSString *hardwareMachine;//machine 如“iPhone10,3”
@property (nonatomic, copy) NSString *startupTime;//设备启动时间
@property (nonatomic, copy) NSString *mbTime;//系统版本更新时间
@property (nonatomic, copy) NSString *countryCode;//国家 local地区，如“CN”
@property (nonatomic, copy) NSString *carrierName;//运营商名称，如“中国移动”
@property (nonatomic, copy) NSString *localTzName;//local时区，如"28800"
@property (nonatomic, copy) NSString *hardwareModel;//设备model
@property (nonatomic, copy) NSString *osVersion;//系统版本
@property (nonatomic, copy) NSString *language;//设备设置的语言：如"zh -Hans-CN"
@property (nonatomic, copy) NSString *phoneName;//设备名称（小写MD5)
@property (nonatomic, copy) NSString *fileInitTime;//设备初始化时间
@property (nonatomic, copy) NSString *mntId;//mnt_id
//本地安装的app列表
@property (nonatomic, copy) NSString *appList;


@end

@interface WanjaEnvInfoModel : WanjaBaseModel
//  网络状态    0:未知 1:3G 2:4G 3:5G 4:WIFI 5:其他 6:2G
@property (nonatomic, copy) NSString *net;
//  运营商     0:未知 1:移动 2:联通 3:电信 4:其他运营
@property (nonatomic, copy) NSString *isp;
//  ip
@property (nonatomic, copy) NSString *ip;
//  地理位置model
@property (nonatomic, strong) WanjaGeoModel *geo;
//  电量
@property (nonatomic, assign) CGFloat battery;
//  磁盘总空间
@property (nonatomic, assign) uint64_t diskSpace;
//  磁盘使用空间
@property (nonatomic, assign) uint64_t useSpace;

@end

@interface WanjaGeoModel : WanjaBaseModel

//  横坐标
@property (nonatomic, copy) NSString *longitude;
//  纵坐标
@property (nonatomic, copy) NSString *latitude;
//  使用坐标系
@property (nonatomic, copy) NSString *name;

@end

@interface WanjaAdReqInfoModel : WanjaBaseModel

//  广告位id
@property (nonatomic, copy) NSString *slotId;
//  预留备用参数
@property (nonatomic, copy) NSString *spaceParam;
//  随机id
@property (nonatomic, copy) NSString *requestUUID;
//  广告超时时长
@property (nonatomic, assign) uint64_t channelReserveTs;
//  预留备用字段
@property (nonatomic, copy) NSString *sdkExtInfo;

@end

@interface WanjaSdidModel : WanjaBaseModel
//  id值
@property (nonatomic, copy) NSString *iosid;
//  版本
@property (nonatomic, copy) NSString *version;

@end



NS_ASSUME_NONNULL_END
