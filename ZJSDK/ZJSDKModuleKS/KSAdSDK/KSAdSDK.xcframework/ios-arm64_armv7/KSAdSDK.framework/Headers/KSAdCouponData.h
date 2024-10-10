//
//  KSAdCouponData.h
//  KSUModel
//
//  Created by 崔婉莹 on 2024/4/11.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface KSAdCouponData : NSObject
///优惠券类别 1-满减券 2-折扣券
@property (nonatomic, copy) NSString *displayType;
///优惠券满减门槛
@property (nonatomic, copy) NSString *displayBase;
///优惠券面值
@property (nonatomic, copy) NSString *displayValue;
///优惠券类别 优惠券开始领取时间
@property (nonatomic, copy) NSString *startFetchTime;
///优惠券类别 优惠券结束领取时间
@property (nonatomic, copy) NSString *endFetchTime;
@end

NS_ASSUME_NONNULL_END
