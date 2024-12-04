//
//  JLEntryElement.h
//  JLAdSDK
//
//  Created by jlad110 on 2021/6/17.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "JLContentPage.h"
#import <JLAdSDK/JLAdSDKConfig.h>

NS_ASSUME_NONNULL_BEGIN

@class JLEntryElement;

@protocol JLEntryElementDelegate <NSObject>

@optional

- (void)jl_entryElementAdDidLoad:(JLEntryElement *)entryElement;
- (void)jl_entryElementAdDidFailToLoad:(JLEntryElement *)entryElement error:(NSError *)error;
- (void)jl_entryElementAdDidExpose:(JLEntryElement *)entryElement;
- (void)jl_entryElementAdDidClick:(JLEntryElement *)entryElement contentPage:(JLContentPage *) contentPage;

@end

@interface JLEntryElement : NSObject
@property (nonatomic, weak, nullable) id<JLEntryElementDelegate> delegate;
@property (nonatomic, assign, readonly) JLAdSdkUnionType unionType;
@property (nonatomic, copy, readonly) UIView *entryView;
@property (nonatomic, readonly) CGSize entryExpectedSize;

@property (nonatomic, assign) CGFloat expectedWidth;
- (instancetype)initWithSlotId:(NSString *) slotId;
- (void)loadAd;
- (NSInteger)eCPM;
@end

NS_ASSUME_NONNULL_END
