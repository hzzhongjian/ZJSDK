//
//  ZJFLFeedVideoViewController.h
//  ZJ_FLAdSDKAdapter
//
//  Created by YJoo on 2025/7/10.
//

#import <UIKit/UIKit.h>
#import "ZJFLFeedAdData.h"
#import "ZJFLAdSourcesModel.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ZJFLFeedVideoPlayDelegate <NSObject>

@optional

/**
激励视频广告点击下载
 */
- (void)feedAdClick;

/**
激励视频达到激励条件
 */
- (void)feedAdRewardEffective;

/**
激励视频广告已经关闭
 */
- (void)feedAdShowFinish;

@end

@interface ZJFLFeedVideoViewController : UIViewController

@property (nonatomic, weak) id<ZJFLFeedVideoPlayDelegate> delegate;
@property (nonatomic, strong) ZJFLAdSourcesModel *baseModel;
@property (nonatomic, strong) ZJFLFeedAdData *adData;  //广告数据

@property (nonatomic, strong) UIButton *backAppBtn;
@property (nonatomic, strong) UIView *appView;
@property (nonatomic, strong) UIView *mediaView;
@property (nonatomic, assign) CGFloat mediaDuration;
@property (nonatomic, assign) BOOL muted; //是否静音

@end

NS_ASSUME_NONNULL_END
