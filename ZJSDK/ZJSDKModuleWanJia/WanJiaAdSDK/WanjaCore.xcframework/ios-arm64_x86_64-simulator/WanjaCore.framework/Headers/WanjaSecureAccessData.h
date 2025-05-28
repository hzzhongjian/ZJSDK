//
//  WanjaSecureAccessData.h
//  WanjaCore
//
//  Created by ZY on 2019/12/11.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class WanjaAdResponseModel;
@class WanjaSpaceInfoModel;
@class WanjaResponseModel;
@class WanjaContentInfoModel;
@class WanjaAdContentSlotModel;

@interface WanjaSecureAccessData : NSObject

+ (WanjaSpaceInfoModel *)spaceInfo:(WanjaAdResponseModel *)response;

+ (WanjaResponseModel *)adResponse:(WanjaSpaceInfoModel *)spaceInfo;

+ (WanjaContentInfoModel *)adContentInfo:(WanjaSpaceInfoModel *)spaceInfo;

+ (WanjaAdContentSlotModel *)adContentSlot:(WanjaSpaceInfoModel *)spaceInfo;

@end

NS_ASSUME_NONNULL_END
