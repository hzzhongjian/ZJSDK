//
//  ZJTierAdLoader.h
//  ZJSDK
//
//  Created by 麻明康 on 2023/2/23.
//  Copyright © 2023 zj. All rights reserved.
//

#import <ZJSDKCore/ZJSDKCore.h>
#import <ZJSDKCore/ZJTierAdAdapter.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZJTierProtocol <NSObject>

@required
- (ZJTierAdAdapter *)createTierAdapterForUnit:(ZJAdUnitModel *)unit;

- (void)setCacheAdapter:(ZJTierAdAdapter *)cacheAdapter;

@end

@interface ZJTierAdLoader : NSObject <ZJTierProtocol>

typedef void(^RequestLevelCompleteBlk)( NSMutableArray <ZJTierAdAdapter *>* _Nullable successAdapters, NSMutableArray <NSError *>*_Nullable tierFailArray);

@property (nonatomic,strong)dispatch_semaphore_t semaphore;

@property (nonatomic, strong) dispatch_queue_t semaphoreQueue;

@property (nonatomic, nullable, copy) RequestLevelCompleteBlk completeBlk;

@property (nonatomic, strong) NSArray <ZJAdUnitModel *>* currentTiers;
//广告请求对象数组
@property (nonatomic,readonly)NSMutableArray <ZJTierAdAdapter *>*adapterArray;

//广告请求成功数组
@property (nonatomic,strong)NSMutableArray <ZJTierAdAdapter *>*successAdapters;

//错误信息数组
@property (nonatomic,strong)NSMutableArray <NSError *>*tierFailArray;

//倒计时器
@property (nonatomic,strong)ZJAdCountdown *countdown;

@property (nonatomic, assign) long timeout;

/// caid json值
@property (nonatomic, copy) NSString *caid_json;

// 用户的唯一标识符
@property (nonatomic, copy) NSString *user_unique_identifier;

- (instancetype)initWithTiers:(NSArray <ZJAdUnitModel *>*)tiers
                     timeoutInterval:(CGFloat)timeoutInterval
                        showPriority:(ZJAdShowPriority)showPriority;

- (void)startLoad;

/// 联盟适配器素材加载成功
- (void)unitAdapterDidLoad:(ZJTierAdAdapter *)adapter;
/// 联盟适配器素材加载失败
- (void)unitAdapterLoadFail:(ZJTierAdAdapter *)adapter error:(NSError *)error;

@end

NS_ASSUME_NONNULL_END
