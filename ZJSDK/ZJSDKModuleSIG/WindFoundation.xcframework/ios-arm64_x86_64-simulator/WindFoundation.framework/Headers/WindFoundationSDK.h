//
//  WindFoundationSDK.h
//  WindFoundation
//
//  Created by Codi on 2022/11/22.
//

#import <Foundation/Foundation.h>

@protocol WFFCustomDevProtocol;

@interface WindFoundationSDK : NSObject

@property (nonatomic, weak) id<WFFCustomDevProtocol> customDevDelegate;

+ (instancetype)sharedInstance;

@end
