//
//  WanjaUserProfileModel.h
//  WanjaCore
//
//  Created by hongji cai on 2026/4/5.
//

#import "WanjaBaseModel.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface WanjaUserProfileModel : WanjaBaseModel

/**
 年龄区间: 18-24、25-30、31-35、36-40、40-45、46-50、51-55、56-60、60+
 传值示例："18-24,25-30"
 */
@property (nonatomic, copy) NSString *age;
// 性别: 男/女
@property (nonatomic, copy) NSString *gender;
/**
 职业: 学生、白领、蓝领、宝妈、自由职业等等
 传值示例："学生,白领"
 */
@property (nonatomic, copy) NSString *occupation;
// 消费能力：高 / 中 / 低
@property (nonatomic, copy) NSString *consumptionAbility;
// 婚恋状态：单身 / 已婚 / 宝妈
@property (nonatomic, copy) NSString *maritalStatus;
/**
 兴趣标签：游戏、电商、阅读、汽车、房产、教育、金融、健康等等
 传值示例："游戏,电商"
 */
@property (nonatomic, copy) NSString *interestTag;

@end

NS_ASSUME_NONNULL_END
