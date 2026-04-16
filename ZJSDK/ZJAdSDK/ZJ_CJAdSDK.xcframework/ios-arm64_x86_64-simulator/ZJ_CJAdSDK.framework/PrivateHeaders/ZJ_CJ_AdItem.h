//
//  ZJ_CJ_AdItem.h
//  ZJ_CJAdSDK
//
//  Created by coderqi on 2025/11/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZJ_CJ_AdItem : NSObject

@property (nonatomic,   copy) NSString *adId;
@property (nonatomic,   copy) NSString *iid;
@property (nonatomic, assign) NSInteger bidPrice;
@property (nonatomic, assign) NSInteger bidType;
@property (nonatomic, assign) BOOL isVideoAd;
/// 自渲染广告素材
@property (nonatomic,   copy) NSDictionary *adMaterialDict;
/// 竞价成功的价格，sdk返回广告竞价失败时回传
@property (nonatomic, assign) NSInteger winAdPrice;
/// 竞价回传dict，可以在竞价之后在bidDcit中添加竞价相关信息，便于更好的出价。winadn--竞价成功的渠道；secprice--2价；
@property (nonatomic,   copy) NSDictionary *bidDcit;

@end

NS_ASSUME_NONNULL_END
