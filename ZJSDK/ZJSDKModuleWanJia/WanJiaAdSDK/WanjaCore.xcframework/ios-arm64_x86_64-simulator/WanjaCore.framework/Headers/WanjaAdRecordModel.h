//
//  WanjaAdRecordModel.h
//  WanjaCoreSDK
//
//  Created by guantou on 2019/12/10.
//

#import <Foundation/Foundation.h>
#import "WanjaAdvertisingType.h"
#import "WanjaAdRequestModel.h"

NS_ASSUME_NONNULL_BEGIN

/**
 广告周期Model，跟随一个广告的生命周期运行
*/
@interface WanjaAdRecordModel : NSObject

@property (nonatomic, copy) NSString *adTypeId;     // 聚合adid
@property (nonatomic, strong) id configDataModel;   //聚合的配置文件数据model
@property (nonatomic, copy) NSString *spaceParam;

@property (nonatomic, assign) WanjaChannelType channel;   // 渠道类型

@property (nonatomic, assign) uint64_t lifeTime;
@property (nonatomic, assign) WanjaAdvertisingType adType;

@property (nonatomic, copy) NSString *randomUUID;
@property (nonatomic, assign) NSTimeInterval requestTimeStamp;
@property (nonatomic, assign) NSTimeInterval startInitTimeStamp;
@property (nonatomic, assign) NSTimeInterval overInitTimeStamp;

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
//超时时间，默认5s
@property (nonatomic, assign) double timeoutInterval;
//有的客户需要合成caid的14个原始参数
@property (nonatomic, copy) NSString *carrierInfo; //
@property (nonatomic, copy) NSString *machine; //
@property (nonatomic, copy) NSString *sysFileTime; //
@property (nonatomic, copy) NSString *countryCode; //
@property (nonatomic, copy) NSString *deviceName; //
@property (nonatomic, copy) NSString *timeZone; //
@property (nonatomic, copy) NSString *memory; //
@property (nonatomic, copy) NSString *disk; //
@property (nonatomic, copy) NSString *language; //
@property (nonatomic, copy) NSString *systemVersion; //
@property (nonatomic, copy) NSString *bootTimeInSec; //
@property (nonatomic, copy) NSString *model; //
@property (nonatomic, copy) NSString *mntId; //
@property (nonatomic, copy) NSString *deviceInitTime; //
//本地安装的app列表
@property (nonatomic, copy) NSString *appList;
//idfa和caid的来源
@property (nonatomic, assign) NSInteger idfaM;
@property (nonatomic, assign) NSInteger caidM;


//@property (nonatomic, copy) NSString *wanjaAppID;
//@property (nonatomic, copy) NSString *wanjaSlotID;
//@property (nonatomic, copy) NSString *KSAppID;
//@property (nonatomic, copy) NSString *KSSlotID;
//@property (nonatomic, copy) NSString *GDTAppID;
//@property (nonatomic, copy) NSString *GDTSlotID;
//@property (nonatomic, copy) NSString *BUAdAppID;
//@property (nonatomic, copy) NSString *BUAdSlotID;
//@property (nonatomic, copy) NSString *baiduAppID;
//@property (nonatomic, copy) NSString *baiduSlotID;

@end

NS_ASSUME_NONNULL_END
