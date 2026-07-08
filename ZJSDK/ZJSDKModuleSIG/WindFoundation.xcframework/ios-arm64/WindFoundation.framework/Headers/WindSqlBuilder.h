//
//  WindSqlBuilder.h
//  SQLIiteBuilder
//
//  Created by Codi on 2021/12/23.
//

#import <Foundation/Foundation.h>

@interface WindSqlBuilder : NSObject

- (NSString * (^)(void))toSql;

@end
