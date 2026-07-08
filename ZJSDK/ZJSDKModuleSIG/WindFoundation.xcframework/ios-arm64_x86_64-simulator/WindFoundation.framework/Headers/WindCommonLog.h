//
//  WindCommonLog.h
//  WindFoundation
//
//  Created by Codi on 2021/11/9.
//

#import <WindFoundation/WindBaseLog.h>

@interface WindCommonLog : WindBaseLog

@property(nonatomic,copy) NSString *browser;//ua
@property(nonatomic,copy) NSString *device_type;//判断手机或平板
@property(nonatomic,copy) NSString *pkgname;//app包名
@property(nonatomic,copy) NSString *udid;//扩展信息
//@property(nonatomic,copy) NSString *time_zone;
@property(nonatomic,copy) NSString *clienttype;//设备型号
@property(nonatomic,copy) NSString *screendensity;
@property(nonatomic,copy) NSString *clientpixel;//分辨率
@property (nonatomic, assign) float battery_level; //电量
@property(nonatomic,assign) uint32_t battery_save_enabled; //是否为低电量模式
@property (nonatomic, assign) uint32_t battery_state; //电池状态
@property (nonatomic,assign) uint32_t isEmulator;//是否是模拟器
@property(nonatomic,copy) NSString *location_switch;//上报定位开关获取信息
@property (nonatomic, copy) NSString *advertising_tracking_enabled;
@property (nonatomic, copy) NSString *tracking_authorization_status;
@property (nonatomic, strong) NSString *country_code;
@property(nonatomic,copy) NSString *is_minor;//是否是未成年
@property(nonatomic,copy) NSString *is_unpersonalized;//是否关闭个性化推荐

@end

