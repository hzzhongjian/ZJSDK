//
//  SMKeyChain.h
//  WindSDK
//
//  Created by happyelements on 2018/4/8.
//  Copyright © 2018 Codi. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SMKeyChain : NSObject

+ (void)saveValue:(id)data forKey:(NSString*)key;
+ (id)loadValueForKey:(NSString*)key;
+ (void)deleteValueForKey:(NSString *)key;

@end
