//
//  WanjaImageView.h
//  WanjaCoreSDK
//
//  Created by guantou on 2019/12/9.
//

#import <UIKit/UIKit.h>
#import "WanjaAdvertisingDelegate.h"

NS_ASSUME_NONNULL_BEGIN

//该协议仅sdk内部使用
@protocol WanjaImageCatchDelegate <NSObject>

/**
  获取缓存data
 */
- (NSData*)wanja_getImageCatchData:(NSString*)fileName;

/**
   保存图片数据
 */
- (void)wanja_saveImageData:(NSData*)data fileName:(NSString*)fileName;

/**
   移除缓存数据
 */
- (void)wanja_removeCatchData:(NSString*)fileName;

@end

/**
 Image类型广告View
*/
@class WanjaSpaceInfoModel;

@interface WanjaImageView : UIImageView

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
