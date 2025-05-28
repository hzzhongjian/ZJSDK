//
//  WanjaAdDecodeErrorReportModel.h
//  WanjaCoreSDK
//
//

#import "WanjaBaseModel.h"
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class WanjaAdRequestModel;
/**
 广告请求的model
*/
@interface WanjaAdDecodeErrorReportModel : WanjaBaseModel

//
@property (nonatomic, copy) NSString *appId;
//
@property (nonatomic, copy) NSString *slotId;
//
@property (nonatomic, copy) NSString *bundle;
//
@property (nonatomic, copy) NSString *sdkVersion;
//
@property (nonatomic, copy) NSString *requestId;

//章鱼聚合版本号
@property (nonatomic, copy) NSString *groupVersion;
//设备id，iOS传idfv,Android传oaid
@property (nonatomic, copy) NSString *deviceId;
//Android|ios
@property (nonatomic, copy) NSString *os;
//系统版本号
@property (nonatomic, copy) NSString *osv;
//品牌
@property (nonatomic, copy) NSString *brand;
//型号
@property (nonatomic, copy) NSString *model;
//消息类型，写文字即可。
@property (nonatomic, copy) NSString *messageType;
//具体信息
@property (nonatomic, copy) NSString *errorMessage;

- (WanjaAdDecodeErrorReportModel*)copyFromAdRequest:(WanjaAdRequestModel*)model;

@end

NS_ASSUME_NONNULL_END
