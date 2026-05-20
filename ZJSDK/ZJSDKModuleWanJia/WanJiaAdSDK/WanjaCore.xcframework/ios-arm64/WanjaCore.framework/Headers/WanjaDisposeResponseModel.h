//
//  WanjaDisposeResponseModel.h
//  WanjaCoreSDK
//
//  Created by guantou on 2019/12/9.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class WanjaAdResponseModel;
@class WanjaSpaceInfoModel;

@interface WanjaDisposeResponseModel : NSObject

- (instancetype)initWithData:(WanjaAdResponseModel *)serverResponse;

@property (nonatomic, strong, readonly) WanjaSpaceInfoModel *spaceInfo;

@property (nonatomic, assign, readonly) CGFloat widthThanHeigh;
@property (nonatomic, assign, readonly) CGFloat heighThanWidth;

//记录广告获取到的起始时间
@property (nonatomic, assign) NSTimeInterval startAdtTime;

@end

NS_ASSUME_NONNULL_END
