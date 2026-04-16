//
//  JTAdSizeModel.h
//  JTAdSDK
//
//  Created by Frank on 2025/7/1.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 自渲染广告中，素材尺寸模型
@interface JTAdSizeModel : NSObject

/// 宽度。单位：px/像素
@property (nonatomic, assign) NSInteger width;

/// 高度。单位：px/像素
@property (nonatomic, assign) NSInteger height;

@end

NS_ASSUME_NONNULL_END
