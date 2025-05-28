//
//  WanjaDeviceInfoHelper.h
//  WanjaCoreSDK
//
//  Created by guantou on 2019/12/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*
 *  获取请求设备信息内容类
 */
@interface WanjaDeviceInfoHelper : NSObject

+ (WanjaDeviceInfoHelper *)shareInstance;

@property (nonatomic, readonly) NSString *sdkUID;
@property (nonatomic, readonly) NSString *did;
@property (atomic, copy) NSString *idfa;
@property (nonatomic, readonly) NSString *mac;
@property (nonatomic, readonly) NSString *os;
@property (nonatomic, readonly) NSString *platform;
@property (nonatomic, readonly) NSString *devType;
@property (nonatomic, readonly) NSString *brand;
@property (nonatomic, readonly) NSString *model;
@property (nonatomic, readonly) NSString *resolution;
@property (nonatomic, readonly) NSString *screenSize;
@property (nonatomic, readonly) NSString *language;
@property (nonatomic, readonly) NSString *idfv;
@property (nonatomic, readonly) NSString *openUdid;
@property (nonatomic, readonly) NSString *density;
@property (nonatomic, readonly) NSString *wifi;
@property (nonatomic, readonly) NSString *cpu;
@property (nonatomic, readonly) NSString *root;
@property (nonatomic, readonly) NSString *isVpn;
@property (atomic, readonly) NSString *defaultIdfa;
@property (nonatomic, readonly) NSArray *shakeImageList;
@property (nonatomic, readonly) BOOL isInitSo;

@end

NS_ASSUME_NONNULL_END
