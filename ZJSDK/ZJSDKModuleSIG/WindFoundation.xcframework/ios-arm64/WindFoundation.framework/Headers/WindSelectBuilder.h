//
//  WindSelectBuilder.h
//  SQLIiteBuilder
//
//  Created by Codi on 2021/12/22.
//

#import <WindFoundation/WindSqlBuilder.h>

@class WindWhereBuilder;

@interface WindSelectBuilder : WindSqlBuilder

- (instancetype)initWithTable:(NSString *)tablename;

- (WindSelectBuilder * (^)(NSString *table))form;

- (WindSelectBuilder * (^)(NSString *column))column;

- (WindSelectBuilder * (^)(WindWhereBuilder *whereBuilder))whereBuilder;

@end
