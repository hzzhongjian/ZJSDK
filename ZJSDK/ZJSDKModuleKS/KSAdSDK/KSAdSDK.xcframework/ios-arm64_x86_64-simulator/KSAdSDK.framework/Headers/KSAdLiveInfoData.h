//
//  KSAdLiveInfoData.h
//  KSUModel
//
//  Created by 崔婉莹 on 2024/4/11.
//

#import <Foundation/Foundation.h>
#import "KSAdLiveBaseData.h"
#import "KSAdLiveShopData.h"
#import "KSAdCouponData.h"

NS_ASSUME_NONNULL_BEGIN

@interface KSAdLiveInfoData : NSObject
/// 转化类型 0:未知; 1:直播进人; 2:直播深度
@property (nonatomic, assign) NSInteger roiType;
/// 直播间信息
@property (nonatomic, strong) KSAdLiveBaseData *liveBaseData;
/// 商品信息
@property (nonatomic, copy) NSArray<KSAdLiveShopData *> *liveShopListData;
/// 优惠券信息
@property (nonatomic, copy) NSArray<KSAdCouponData *> *couponListData;

@end

NS_ASSUME_NONNULL_END
