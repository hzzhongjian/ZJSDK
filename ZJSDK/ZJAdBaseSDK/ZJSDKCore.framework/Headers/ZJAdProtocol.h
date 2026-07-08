//
//  ZJAdProtocol.h
//  ZJSDKCore
//
//  Created by 麻明康 on 2025/3/28.
//

#import <Foundation/Foundation.h>
#import <ZJSDKCore/ZJAdExposureReportParam.h>


NS_ASSUME_NONNULL_BEGIN


@protocol ZJAdProtocol <NSObject>

@optional

/**
 * @brief 设置竞价价格，单位（分）
 * @param ecpm              竞价价格
 * @param highestLossEcpm   最大竞价失败方出价
 */
- (void)setBidEcpm:(NSInteger)ecpm
   highestLossEcpm:(NSInteger)highestLossEcpm;

/**
 * @brief 广告曝光失败后上报失败原因
 * @param failureCode 曝光失败原因类型
 * @param reportParam 曝光失败原因描述
 *        reportParam.winEcpm 胜出者的ecpm报价（单位：分）
 *        reportParam.adnType 胜出方，见ZJAdExposureReportParam.h 中ZJAdExposureAdnType定义
 *        reportParam.adnName 胜出平台名，见ZJAdExposureReportParam.h 中ZJAdADNType平台定义
 */
- (void)reportAdExposureFailed:(ZJAdExposureFailureCode)failureCode reportParam:(ZJAdExposureReportParam *)reportParam;

@end

NS_ASSUME_NONNULL_END
