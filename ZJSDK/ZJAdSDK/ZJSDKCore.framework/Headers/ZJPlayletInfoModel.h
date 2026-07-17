//
//  ZJPlayletInfoModel.h
//  ZJSDKCore
//
//  Created by 麻明康 on 2026/7/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZJPlayletInfoModel : NSObject

@property (nonatomic, assign) NSInteger shortplay_id;            // 短剧ID
@property (nonatomic, copy) NSString *title;                     // 短剧名
@property (nonatomic, copy) NSString *cover_image;               // 短剧的封面
@property (nonatomic, assign) NSInteger status;                  // 短剧状态 1表示未完结
@property (nonatomic, assign) NSInteger total;                   // 共多少集
@property (nonatomic, copy) NSString *desc;                      // 简介
@property (nonatomic, assign) NSInteger category_id;             // 分类id
@property (nonatomic, copy) NSString *category_name;             // 分类名称
@property (nonatomic, copy) NSString *source_novel_name;         // 短剧对应的小说名
@property (nonatomic, copy) NSString *source_novel_author;       // 小说作者
@property (nonatomic, assign) CGFloat video_duration;            // 时长
@property (nonatomic, assign) NSInteger current_episode;         // 播放到第几集
@property (nonatomic, assign) NSInteger group_id;                // 播放到的剧集gid
@property (nonatomic, assign) NSInteger channel_id;              // 推荐模块id
@property (nonatomic, assign) NSInteger next_skit_id;            // 下一步短剧的id
@property (nonatomic, assign) NSInteger create_time;             // 上线时间
@property (nonatomic, assign) NSInteger action_time;             // 观看时间
@property (nonatomic, assign) NSInteger unlock_index;            // 解锁集数
@property (nonatomic, copy) NSArray<NSNumber *> *lockStatusArray; // 解锁状态列表
@property (nonatomic) NSString *icp_number;                       // 备案号
@property (nonatomic, copy) NSArray *cover_image_v2s; // 短剧封面海报
@property (nonatomic, copy) NSArray *poster_image_v2s; // 剧集首帧

@property (nonatomic) NSInteger favorite_state;
@property (nonatomic) NSInteger favorite_time;
@property (nonatomic) NSInteger favorite_count;
@property (nonatomic) NSInteger like_state;
@property (nonatomic) NSInteger like_time;
@property (nonatomic) NSInteger like_count;
@property (nonatomic) NSInteger level_label;                    //等级标签 "1:S|2:A|3:B"
@property (nonatomic) BOOL is_potential;                        //是否潜力剧
@property (nonatomic) NSInteger style_type;                     //内容风格: 1:短剧 2:漫剧 3:沙雕动画


@end

NS_ASSUME_NONNULL_END
