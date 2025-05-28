//
//  WanjaEventCodes.h
//  WanjaCoreSDK
//
//  Created by guantou on 2020/3/24.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

//sdk初始化开始
static NSString *const kWanjaEventCode_init_start = @"100.000";
//sdk初始化成功
static NSString *const kWanjaEventCode_init_success = @"100.200";

//广告请求开始（接收到媒体请求）
static NSString *const kWanjaEventCode_ad_request = @"200.000";
//广告请求配置获取开始
static NSString *const kWanjaEventCode_ad_request_config_start = @"210.000";
//广告请求配置获取成功
static NSString *const kWanjaEventCode_ad_request_config_success = @"210.200";
//广告请求配置获取失败
static NSString *const kWanjaEventCode_ad_request_config_no_config = @"210.101";
//平台filter开始
static NSString *const kWanjaEventCode_ad_request_filter_start = @"220.000";
//平台filter通过
static NSString *const kWanjaEventCode_ad_request_filter_pass = @"220.200";
//平台filter失败-设备标识没通过
static NSString *const kWanjaEventCode_ad_request_filter_invalid_deviceidentifier = @"220.401";
//minAdLoadTime不满足
static NSString *const kWanjaEventCode_ad_request_filter_not_enough_ad_load_time = @"220.403";
//广告拍卖开始
static NSString *const kWanjaEventCode_ad_request_auction_start = @"230.000";
//随机数没匹配到
static NSString *const kWanjaEventCode_ad_request_auction_no_buyer = @"230.500";
//渠道信息未找到（buyer中不存在）
static NSString *const kWanjaEventCode_ad_request_config_percentage_error = @"230.501";
//广告转发渠道开始
static NSString *const kWanjaEventCode_ad_request_auction_buyer_start = @"240.000";
//当前渠道已转发过
static NSString *const kWanjaEventCode_ad_request_auction_buyer_already = @"240.100";
//渠道filter开始
static NSString *const kWanjaEventCode_ad_request_auction_buyer_filter_start = @"245.000";
//渠道filter通过
static NSString *const kWanjaEventCode_ad_request_auction_buyer_filter_pass = @"245.200";
//平台filter失败-设备标识没通过
static NSString *const kWanjaEventCode_ad_request_auction_buyer_filter_invalid_deviceidentifier = @"245.401";
//minAdLoadTime不满足
static NSString *const kWanjaEventCode_ad_request_auction_buyerfilter_not_enough_ad_load_time = @"245.403";
//已有其它渠道请求成功
static NSString *const kWanjaEventCode_ad_request_auction_buyer_eliminate = @"250.000";
//渠道初始化开始
static NSString *const kWanjaEventCode_ad_request_auction_buyer_init = @"250.100";
//渠道初始化成功
static NSString *const kWanjaEventCode_ad_request_auction_buyer_init_success = @"250.200";
//渠道广告请求
static NSString *const kWanjaEventCode_ad_request_auction_buyer_forward = @"255.200";
//广告请求时间小于sleep时间
static NSString *const kWanjaEventCode_ad_request_auction_buyer_max_sleep_time = @"255.500";
//请求是buyer中slotId未获取到
static NSString *const kWanjaEventCode_ad_request_auction_buyer_no_slotId = @"255.501";
//广告返回（ios）
static NSString *const kWanjaEventCode_ad_request_auction_buyer_response = @"260.200";
//广告返回失败ios）
static NSString *const kWanjaEventCode_ad_request_auction_buyer_no_internat = @"260.500";
//HPFRW先返回其它渠道历史价格低于HPFRW则失败，移除
static NSString *const kWanjaEventCode_ad_request_auction_buyer_candidate = @"265.200";
//HPFRW先返回其它渠道历史价格高于HPFRW则上报此事件，等待其它渠道返回
static NSString *const kWanjaEventCode_ad_request_auction_buyer_not_highest_price = @"265.601";
//其他渠道已经显示被移除
static NSString *const kWanjaEventCode_ad_request_auction_buyer_other_show_remove = @"265.602";
//广告load成功
static NSString *const kWanjaEventCode_ad_request_auction_buyer_load = @"280.200";
//渠道广告胜出
static NSString *const kWanjaEventCode_ad_request_auction_buyer_win = @"280.250";
//广告load曝光
static NSString *const kWanjaEventCode_ad_request_auction_buyer_exposured = @"280.300";
//广告点击事件
static NSString *const kWanjaEventCode_ad_request_auction_buyer_click = @"290.300";
//广告load失败
static NSString *const kWanjaEventCode_ad_request_auction_buyer_load_error = @"280.500";
//广告超时未返回
static NSString *const kWanjaEventCode_ad_request_auction_buyer_over_time = @"280.502";
static NSString *const kWanjaEventCode_ad_request_auction_buyer_other_channel_show = @"280.504";
//定时器开始
static NSString *const kWanjaEventCode_configurator_start = @"300.000";
//已经过期
static NSString *const kWanjaEventCode_configurator_check_expire = @"310.200";
//未过期
static NSString *const kWanjaEventCode_configurator_check_not_expire = @"310.210";
//更新成功
static NSString *const kWanjaEventCode_configurator_update_success = @"320.200";
//更新失败
static NSString *const kWanjaEventCode_configurator_update_no_internet = @"320.500";
//定时器restart
static NSString *const kWanjaEventCode_configurator_restart = @"330.210";


//事件配置文件开始
static NSString *const kWanjaEventCode_messenger_config_start = @"410.000";
//事件配置文件成功
static NSString *const kWanjaEventCode_messenger_config_success = @"410.200";
//本地缓存服务配置不存在或获取失败
static NSString *const kWanjaEventCode_messenger_config_fail = @"410.500";
//定时器间隔改变restart定时器
static NSString *const kWanjaEventCode_messenger_config_restart = @"410.300";

