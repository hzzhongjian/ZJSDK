//
//  WanjaReplaceURLTools.h
//  WanjaCoreSDK
//
//  Created by guantou on 2019/12/10.
//

#import <Foundation/Foundation.h>
#import "WanjaAdRecordModel.h"
#import <UIKit/UIKit.h>
@class WanjaBuyerModel;
NS_ASSUME_NONNULL_BEGIN

@interface WanjaReplaceURLTools : NSObject

//  配置文件宏替换
+ (NSString *)wanja_replaceConfigureWithMacro:(NSString *)replaceString;

//  事件上报宏替换
+ (NSString *)wanja_replaceReportWithMacro:(NSString *__nullable)replaceString
                                     model:(WanjaAdRecordModel *__nullable)adRecordModel
                                   buyerId:(NSString *__nullable)buyerID
                              channelAppID:(NSString *__nullable)appID
                            channelSpaceID:(NSString *__nullable)spaceID
                                 eventCode:(NSString *__nullable)eventCode
                                     Error:(NSError *__nullable)error;

//  曝光上报宏替换
+ (NSString *)wanja_replacerReportURLWithUrlString:(NSString *)urlString withDataString:(NSString *)dataString randomUUID:(NSString *)randomUUID;

//  点击上报宏替换
+ (NSString *)wanja_replacerReportURLWithUrlString:(NSString *)urlString withDataString:(NSString *)dataString randomUUID:(NSString *)randomUUID adClickPoint:(CGPoint)adClickPoint srClickPoint:(CGPoint)srClickPoint;

+ (NSString *)wanja_logReplaceWithMacro:(NSString *__nullable)replaceString
                             adTypeId:(NSString *_Nullable)adTypeId
                        channelSlotId:(NSString *_Nullable)channelSlotId
                                buyer:(WanjaBuyerModel *_Nullable)buyer
                                reqId:(NSString *)reqId
                                ptime:(NSTimeInterval)ptime
                                  bid:(BOOL)bid
                                price:(CGFloat)price
                              isAoclk:(BOOL)isAoclk ;

@end

NS_ASSUME_NONNULL_END
