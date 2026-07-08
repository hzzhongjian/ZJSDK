//
//  ZJMultipleAdAdapter.h
//  ZJSDKCore
//
//  Created by 麻明康 on 2023/3/7.
//

#import <ZJSDKCore/ZJCoreAdAdapter.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZJMultipleAdAdapterProtocol <NSObject>

- (void)loadAdWithCount:(NSUInteger)count;

@end

@interface ZJMultipleAdAdapter : ZJCoreAdAdapter<ZJMultipleAdAdapterProtocol>

@property (nonatomic, strong, readonly) NSArray *multipleResultObject;

// 用于ServerBidding请求参数
@property (nonatomic, copy) NSString *trade_no;

@end

NS_ASSUME_NONNULL_END
