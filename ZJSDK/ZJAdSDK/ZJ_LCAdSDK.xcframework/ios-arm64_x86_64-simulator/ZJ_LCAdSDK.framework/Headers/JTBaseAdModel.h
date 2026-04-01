//
//  JTBaseAdModel.h
//  JTAdSDK
//
//  Created by Frank on 2025/7/4.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface JTBaseAdModel : NSObject

@property (nonatomic, strong) NSDictionary *mediaExtraInfo;

/// 确认广告是否有效。
- (BOOL)isValidAd;

/// 获取当前广告eCPM，单位：分/千次。
- (NSInteger)getECPM;

/// 竞价成功
- (void)bidWin;

/// 竞价失败
/// - Parameters:
///   - pirce: 竞价成功的广告的价格
///   - providerName: 竞价成功的广告的供应商名称
- (void)bidFailureWithWinPrice:(NSInteger)price
                      privider:(nullable NSString *)providerName;

@end

NS_ASSUME_NONNULL_END
