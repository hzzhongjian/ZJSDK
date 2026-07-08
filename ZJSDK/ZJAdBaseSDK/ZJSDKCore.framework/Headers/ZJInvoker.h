//
//  ZJInvoker.h
//  ZJSDKCore
//
//  Created by 麻明康 on 2022/9/27.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZJInvoker : NSObject

// 此处object参数，只支持对象类型，切NSValue类型不能转换
+ (id)safePerformAction:(SEL)action
                 target:(NSObject *)target
             withObject:(nullable id)object,...NS_REQUIRES_NIL_TERMINATION;

+ (NSArray *)getInstanceMethodList:(NSString *)className;

+ (NSArray *)getClassMethodList:(NSString *)className;

+ (NSArray *)getMethodList:(NSString *)className;

// 判断类是否有实例方法
+ (BOOL)className:(NSString *)className instanceMethodName:(NSString *)instanceMethodName;

// 判断类是否有类方法
+ (BOOL)className:(NSString *)className classMethodName:(NSString *)classMethodName;

// 判断类是否拥有某个属性
+ (BOOL)className:(NSString *)className propertyName:(NSString *)propertyName;

// 此方法支持任意类型的参数，可以自动转换NSValue类型
- (id)performSelector:(SEL)selector withTarget:(NSObject *)target withArguments:(NSArray *)arguments;

@end

NS_ASSUME_NONNULL_END
