//
//  WindWhereBuilder.h
//  SQLIiteBuilder
//
//  Created by Codi on 2021/12/23.
//

#import <WindFoundation/WindSqlBuilder.h>

@interface WindWhereBuilder : WindSqlBuilder

- (WindWhereBuilder * (^)(void))sms_and;
- (WindWhereBuilder * (^)(void))sms_or;

- (WindWhereBuilder * (^)(void))desc;
- (WindWhereBuilder * (^)(void))asc;
- (WindWhereBuilder * (^)(NSString *column))orderBy;

- (WindWhereBuilder * (^)(NSInteger limit))limit;
- (WindWhereBuilder * (^)(NSInteger offset))offset;

- (WindWhereBuilder * (^)(NSString *name))column;
- (WindWhereBuilder * (^)(NSArray *values))sms_in;
- (WindWhereBuilder * (^)(NSArray *values))notIn;
- (WindWhereBuilder * (^)(void))notNull;
- (WindWhereBuilder * (^)(void))isNull;

- (WindWhereBuilder * (^)(id value))equal;
- (WindWhereBuilder * (^)(id value))notEqual;
- (WindWhereBuilder * (^)(id value))greatThan;
- (WindWhereBuilder * (^)(id value))lessThan;
- (WindWhereBuilder * (^)(id value))greatThanOrEqual;
- (WindWhereBuilder * (^)(id value))lessThanOrEqual;






@end
