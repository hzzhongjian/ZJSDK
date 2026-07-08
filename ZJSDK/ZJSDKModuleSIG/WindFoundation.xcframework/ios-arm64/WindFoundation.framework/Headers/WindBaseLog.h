//
//  WindBaseLog.h
//  WindFoundation
//
//  Created by Codi on 2021/11/9.
//

#import <Foundation/Foundation.h>

@interface WindBaseLog : NSObject
@property(nonatomic,copy) NSString *uniq_key;//扩展信息
@property(nonatomic,copy) NSString *user_id;//必传参数
@property(nonatomic,copy) NSString *ac_type;//必传参数
@property(nonatomic,copy) NSString *wmsession_id;//应用生命周期内唯一id
@property(nonatomic,copy) NSString *category;//事件类型
@property(nonatomic,copy) NSString *sub_category;//事件子类型
@property(nonatomic,copy) NSString *timestamp;//事件产生的时间戳
@property(nonatomic,copy) NSString *networktype;//网络类型
@property(nonatomic,copy) NSString *idfa;//iOS设备idfa
@property(nonatomic,copy) NSString *idfv;//Vindor标示符，适用于对内：例如分析用户在应用内的行为等。
@property(nonatomic,copy) NSString *uid;//扩展信息
@property(nonatomic,copy) NSString *carrier;//运营商
@property(nonatomic,copy) NSString *gameversion;//应用版本
@property(nonatomic,copy) NSString *clientversion;//系统版本
@property(nonatomic,copy) NSString *lat;//维度
@property(nonatomic,copy) NSString *lng;//经度
@property(nonatomic,copy) NSString *os;//操作系统区分，取值为：1:ios、2:android
@property(nonatomic,copy) NSString *time_zone;
@property(nonatomic,copy) NSString *seconds_from_GMT;
@property(nonatomic,copy) NSString *cwidth;//物理屏幕宽度
@property(nonatomic,copy) NSString *cheight;//物理屏幕高度
@end
