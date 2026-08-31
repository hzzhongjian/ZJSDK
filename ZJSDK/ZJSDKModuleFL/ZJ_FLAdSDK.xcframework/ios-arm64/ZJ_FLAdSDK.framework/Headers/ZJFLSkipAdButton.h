//
//  ZJFLSkipAdButton.h
//  AdDemo
//
//  Created by lurich on 2021/9/14.
//

#import <UIKit/UIKit.h>
/**
 *  倒计时类型
 */
typedef NS_ENUM(NSInteger,ZJFLSkipType) {
    ZJFLSkipTypeNone      = 1,//无
    /** 方形 */
    ZJFLSkipTypeTime      = 2,//方形:倒计时
    ZJFLSkipTypeText      = 3,//方形:跳过
    ZJFLSkipTypeTimeText  = 4,//方形:倒计时+跳过 (default)
    /** 圆形 */
    ZJFLSkipTypeRoundTime = 5,//圆形:倒计时
    ZJFLSkipTypeRoundText = 6,//圆形:跳过
    ZJFLSkipTypeRoundProgressTime = 7,//圆形:进度圈+倒计时
    ZJFLSkipTypeRoundProgressText = 8,//圆形:进度圈+跳过
    
    ZJFLSkipTypeCustomGdtSkip = 9,//自定义广点通跳过
    ZJFLSkipTypeVast = 10, //vast海外 是一个返回按键，没有动画 没有倒计时
    ZJFLSkipTypeReward = 11  //激励视频 倒计时 + X秒后获取奖励
};

@interface ZJFLSkipAdButton : UIButton

// 针对方形跳过按钮控制跳过的间距,默认左右为5，上下为2.5
@property (nonatomic, assign) CGFloat           leftRightSpace;
@property (nonatomic, assign) CGFloat           topBottomSpace;
@property (nonatomic, assign) CGFloat bili;
@property (nonatomic, assign) CGFloat resp_area_ratio;
@property (nonatomic, assign) CGFloat display_countdown;
@property (nonatomic, assign) ZJFLSkipType skipType;

- (instancetype)initWithSkipType:(ZJFLSkipType)skipType;

- (void)setTitleduration:(NSInteger)duration;

- (void)startRoundDispathTimerWithDuration:(CGFloat)duration completion:(void(^)(void))completion;
- (void)cancelTimer;

- (void)setCloseTitle;

@end
