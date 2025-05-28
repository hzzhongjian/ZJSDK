//
//  WanjaPlayerView.h
//  WanjaCoreSDK
//
//  Created by guantou on 2019/12/9.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import "WanjaAdvertisingDelegate.h"
#import "WanjaBusinessReport.h"

NS_ASSUME_NONNULL_BEGIN

//该协议仅sdk内部使用
@protocol WanjaVedioCatchDelegate <NSObject>
/**
  获取缓存资源
 */
- (NSString*)wanja_getPlayerResourceByFileName:(NSString*)fileName;

/**
  获取缓存路径
 */
- (NSString*)wanja_getCathPath:(NSString*)fileName;

/**
 获取文件名
 */
- (NSString * __nullable)wanja_getFileNameOfUrl:(NSString*)urlString;

/**
   移除缓存数据
 */
- (void)wanja_removeCatchData:(NSString*)fileName;

@end

/**
 视频广告View
*/
@class WanjaSpaceInfoModel;

@interface WanjaPlayerView : UIView

@property (nonatomic, weak) id<WanjaAdvertisingDelegate> delegate;
//该协议仅sdk内部使用
@property (nonatomic, weak) id<WanjaVedioCatchDelegate> catchDelegate;
/**
 视频填充方式, 默认AVLayerVideoGravityResizeAspect
*/
@property (nonatomic, copy) AVLayerVideoGravity videoGravity;
/**
 控制click事件
*/
@property (nonatomic, assign) BOOL isCanClick;

/**
音量视图
*/
@property (nonatomic, strong, readonly) UIImageView * voiceImageView;


/**
 点击位置，相对于广告
*/
@property (nonatomic, assign, readonly) CGPoint adClickPoint;
/**
 点击位置，相对于屏幕
*/
@property (nonatomic, assign, readonly) CGPoint srClickPoint;

/**
 视频开始时间
 */
@property (nonatomic, readonly) NSString * videoStartTime;
/**
 视频结束时间
 */
@property (nonatomic, readonly) NSString * videoEndTime;
//
@property (nonatomic, strong) WanjaBusinessReport *businessReport;

- (instancetype)initWithFrame:(CGRect)frame;

/**
 渲染广告
 @param spaceInfo 广告数据模型
 @param view LogoView，由于视频播放器的原因，要先确定尺寸。
 @param index 加载第几个广告
*/
- (void)loadPlayerWithWanjaSpaceInfo:(WanjaSpaceInfoModel *)spaceInfo bottomView:(UIView * _Nullable)view index:(NSInteger)index;

/**
 播放
 */
- (void)play;

/**
 重新播放
 */
- (void)rePlay;

/**
 暂停
 */
- (void)pause;

/**
 移除本身，在NSObject中无法释放
 */
- (void)closeSelf;

/**
 清理缓存
 */
+ (void)clearCache;

@end

NS_ASSUME_NONNULL_END
