//
//  SWModel.h
//  SliderSwitch
//
//  Created by kkmm on 2019/1/9.
//  Copyright © 2019 kkmm. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SliderSwitchProtocol.h"
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN

@interface SWModel : NSObject
@property(nonatomic,strong) NSString *title;
@property(nonatomic,strong) NSString *categoryId;
@property(nonatomic,strong) NSString *content_app_id;
@property (nonatomic, strong) NSString *subChannelId;
/// 新增参数，用来配置百度资讯是否屏蔽视频，不配置为不屏蔽，后台配置就是屏蔽
@property (nonatomic, assign) BOOL show_video;
@property(nonatomic,strong) UIView <SliderSwitchProtocol>* pageView;
@end

NS_ASSUME_NONNULL_END
