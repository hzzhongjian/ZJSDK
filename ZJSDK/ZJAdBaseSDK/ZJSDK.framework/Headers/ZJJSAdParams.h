//
//  ZJJSAdParams.h
//  ZJSDK
//
//  Created by 麻明康 on 2025/8/22.
//  Copyright © 2025 zj. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZJJSAdParams : NSObject

// 广告位ID
@property (nonatomic, copy) NSString *posId;

// 用户ID
@property (nonatomic, copy) NSString *userId;

// 是否开启声音
@property (nonatomic, assign) BOOL volumeOn;

// 透传信息
@property (nonatomic, copy) NSString *extra;
    
// 隐藏View
@property (nonatomic, assign) BOOL hide;

// 移除View
@property (nonatomic, assign) BOOL remove;

// 宽
@property (nonatomic, assign) double width;

// 高
@property (nonatomic, assign) double height;

// 上边距
@property (nonatomic, assign) double top;
    
// 左边距
@property (nonatomic, assign) double left;


+ (ZJJSAdParams *)parseParams:(NSString *)params;

@end

NS_ASSUME_NONNULL_END
