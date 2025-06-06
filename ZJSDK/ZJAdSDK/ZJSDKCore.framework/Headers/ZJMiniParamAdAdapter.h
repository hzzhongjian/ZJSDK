//
//  ZJMiniParamAdAdapter.h
//  ZJSDKCore
//
//  Created by 麻明康 on 2022/9/26.
//

#import <ZJSDKCore/ZJCoreAdAdapter.h>
#import <ZJSDKCore/ZJMiniParamAdProtocol.h>
#import <ZJSDKCore/ZJTierAdAdapter.h>

NS_ASSUME_NONNULL_BEGIN

@class ZJMiniParamAdAdapter;

@protocol ZJMiniParamAdAdapterDelegate <NSObject>

@optional
/**
 *  小程序唤起成功
 */
- (void)zj_miniParamAdAdapterDidAwake:(ZJMiniParamAdAdapter *)miniParamAdAdapter;


/**
 *  小程序唤起失败
 */
- (void)zj_miniParamAdAdapterAwakeFail:(ZJMiniParamAdAdapter *)miniParamAdAdapter error:(NSError *)error;

- (void)zj_miniParamAdAdapter:(ZJMiniParamAdAdapter *)miniParamAdAdapter onResp:(id)resp;

@end

// 修改之前，是继承ZJCoreAdAdapter这个类的

@interface ZJMiniParamAdAdapter : ZJTierAdAdapter <ZJMiniParamAdProtocol>

@property (nonatomic, weak) id <ZJMiniParamAdAdapterDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
