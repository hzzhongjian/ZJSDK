//
//  QMRetentionAlertInfo.h
//  QMAdSDK
//
//  Created by Donnie on 2024/10/31.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface QMRetentionAlertInfo : NSObject

/// 弹窗标题
@property (nonatomic, copy) NSString *messageTitle;

/// 弹窗信息
@property (nonatomic, copy, nullable) NSString *messageBody;

/// 继续按钮
@property (nonatomic, copy) NSString *confirmButtonText;

/// 关闭按钮
@property (nonatomic, copy) NSString *cancelButtonText;

- (instancetype)init;

- (instancetype)initWithMessageTitle:(NSString * _Nullable)messageTitle
                         messageBody:(NSString * _Nullable)messageBody
                   confirmButtonText:(NSString *)confirmButtonText
                    cancelButtonText:(NSString *)cancelButtonText;

@end

NS_ASSUME_NONNULL_END
