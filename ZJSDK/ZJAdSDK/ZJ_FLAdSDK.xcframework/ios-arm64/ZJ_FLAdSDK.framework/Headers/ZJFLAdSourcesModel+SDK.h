//
//  ZJFLAdSourcesModel+SDK.h
//  ZJ_FLAdSDK
//
//  Created by Lurich on 2024/7/4.
//

#import <ZJ_FLAdSDK/ZJ_FLAdSDK.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZJFLAdSourcesModel (SDK)

/// MARK: SDK 内部使用参数
@property (nonatomic, copy)     NSString *place_id;
@property (nonatomic, copy)     NSString *token;
@property (nonatomic, copy)     NSString *hotspot;
@property (nonatomic, assign)   NSInteger hotspot_type;
@property (nonatomic, assign)   NSInteger scale_type;
@property (nonatomic, copy)     NSString *red_package_rain;
@property (nonatomic, copy)     NSString *skip_button;
@property (nonatomic, copy)     NSString *bidTimeLocal;
@property (nonatomic, assign)   NSInteger only_button;
@property (nonatomic, assign)   NSInteger close_button_interval;
@property (nonatomic, copy)     NSString *display_effective_count;
@property (nonatomic, assign)   NSInteger draw_type;
@property (nonatomic, assign)   NSInteger close_button_freq;
@property (nonatomic, assign)   NSInteger resp_area_ratio;
@property (nonatomic)           NSTimeInterval beginTime;

@property (nonatomic, copy)     NSString *ads_show_time;

@end

NS_ASSUME_NONNULL_END
