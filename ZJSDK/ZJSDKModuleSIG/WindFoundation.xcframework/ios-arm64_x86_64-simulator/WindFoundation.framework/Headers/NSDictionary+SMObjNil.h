//
//  NSDictionary+SMObjNil.h
//  WindSDK
//
//  Created by happyelements on 2018/5/3.
//  Copyright © 2018 Codi. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSDictionary (SMObjNil)

+ (instancetype)dictionaryWithObjects:(const id[])objects forKeys:(const id[])keys count:(NSUInteger)cnt;

@end
