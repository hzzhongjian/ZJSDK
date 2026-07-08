//
//  SMMotionManager.h
//  WindSDK
//
//  Created by happyelements on 2019/5/22.
//  Copyright © 2019 Codi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreMotion/CoreMotion.h>

@interface SMMotionModel : NSObject
//角度，单位欧拉角
//@property(nonatomic, copy) NSString *attitude_yaw;
//@property(nonatomic, copy) NSString *attitude_pitch;
//@property(nonatomic, copy) NSString *attitude_roll;

//陀螺仪，各轴的转速
@property(nonatomic, copy) NSString *gyro_x;
@property(nonatomic, copy) NSString *gyro_y;
@property(nonatomic, copy) NSString *gyro_z;

//加速计，地球重力对该设备在X、Y、Z轴上施加的重力加速度；
//@property(nonatomic, copy) NSString *gravity_x;
//@property(nonatomic, copy) NSString *gravity_y;
//@property(nonatomic, copy) NSString *gravity_z;

//该属性返回用户外力对该设备在X、Y、Z轴上施加的重力加速度；
@property(nonatomic, copy) NSString *userAcceleration_x;
@property(nonatomic, copy) NSString *userAcceleration_y;
@property(nonatomic, copy) NSString *userAcceleration_z;

//该属性返回校准后的磁场信息。该属性值是一个CMCalibratedMagneticField结构体变量。CMCalibratedMagneticField类型的变量包括field和accuracy两个字段，其中field代表X、Y、Z、轴上的磁场强度，accuracy则代表磁场强度的精度；
@property(nonatomic, copy) NSString *magneticField_field_x;
@property(nonatomic, copy) NSString *magneticField_field_y;
@property(nonatomic, copy) NSString *magneticField_field_z;

//屏幕当前亮度
@property(nonatomic, copy) NSString *brightness;

//在转json时需要忽略改参数
@property (nonatomic,assign) long long timestamp;


@end

@interface SMMotionEventResult : NSObject
@property (nonatomic,strong) NSArray<SMMotionModel *> * before_values;
@property (nonatomic,strong) NSArray<SMMotionModel *> * after_values;
@end

@interface SMMotionManager : NSObject

@property (nonatomic,assign) BOOL hasMotionConfig;
@property (nonatomic,assign) NSInteger interval;
@property (nonatomic,assign) NSInteger count;
@property (nonatomic,assign) NSInteger queueMaxCount;

+ (instancetype)sharedInstance;

- (void)startMotionServices;

- (SMMotionEventResult *)getEventMotionsWithTimestamp:(long long)timestamp;

@end
