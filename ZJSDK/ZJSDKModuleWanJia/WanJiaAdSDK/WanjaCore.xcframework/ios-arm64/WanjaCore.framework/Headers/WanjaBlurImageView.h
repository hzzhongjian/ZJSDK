//
//  WanjaBlurImageView.h
//  WanjaCoreSDK
//
//  Created by guantou on 2019/12/9.
//

#import <UIKit/UIKit.h>
#import "WanjaAdvertisingDelegate.h"
#import "WanjaImageView.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Image类型广告View
*/
@class WanjaSpaceInfoModel;

@interface WanjaBlurImageView : UIImageView

@property (nonatomic, weak) id<WanjaAdvertisingDelegate> delegate;
//该协议仅sdk内部使用
@property (nonatomic, weak) id<WanjaImageCatchDelegate> catchDelegate;

/**
 点击位置，相对于广告
*/
@property (nonatomic, assign, readonly) CGPoint adClickPoint;
/**
 点击位置，相对于屏幕
*/
@property (nonatomic, assign, readonly) CGPoint srClickPoint;

//
@property (nonatomic, assign) CGFloat blurViewAlpha;

- (instancetype)initWithFrame:(CGRect)frame;
- (instancetype)initWithFrame:(CGRect)frame enableClick:(BOOL)isCanClick;

/**
 渲染广告
 @param spaceInfo 广告数据模型
 @param index 加载第几个广告
*/
- (void)loadImageViewWithWanjaSpaceInfo:(WanjaSpaceInfoModel *)spaceInfo index:(NSInteger)index;

/**
 移除本身，在NSObject中无法释放
 */
- (void)closeSelf;

//获取图片的url
- (NSString*)getImageUrl:(WanjaSpaceInfoModel *)spaceInfo index:(NSInteger)index;

//预加载图片
- (void)preloadImageViewWithWanjaSpaceInfo:(WanjaSpaceInfoModel *)spaceInfo index:(NSInteger)index isCallback:(BOOL)isCallback;
- (void)preloadImageViewWithUrl:(NSString *)imgUrl;

@end

NS_ASSUME_NONNULL_END
