//
//  KSAdLiveShopData.h
//  KSUModel
//
//  Created by 崔婉莹 on 2024/4/11.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface KSAdLiveShopData : NSObject
/// 商品主图
@property (nonatomic, copy) NSString *icon;
/// 商品名
@property (nonatomic, copy) NSString *name;
/// 商品价格
@property (nonatomic, copy) NSString *price;
/// 商品原价
@property (nonatomic, copy) NSString *originPrice;
/// 商品销量
@property (nonatomic, copy) NSString *volume;
/// 是否有优惠券
@property (nonatomic, assign) BOOL haveCoupon;

@end

NS_ASSUME_NONNULL_END
