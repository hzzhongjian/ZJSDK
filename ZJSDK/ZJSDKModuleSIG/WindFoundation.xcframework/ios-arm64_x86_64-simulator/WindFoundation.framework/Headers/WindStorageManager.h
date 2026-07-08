//
//  WindStorageManager.h
//  WindSDK
//
//  Created by Codi on 2021/1/4.
//  Copyright © 2021 Codi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WindFoundation/SMDB.h>

#define SMTABLE_LOGS @"dclog"
#define SMTABLE_TRACKING @"tracking"
#define SM_SQL_ORDERTYPE_ASC @"asc" //升序
#define SM_SQL_ORDERTYPE_DESC @"desc" //降序

@interface WindStorageManager : NSObject

@property (nonatomic, strong, readonly) SMDatabaseQueue *dbQueue;

+ (instancetype)sharedManager;

- (BOOL)initDatabase;


/// 向表中插入数据
/// @param sql 对应sql value(?, ?)
/// @param arguments 每个?对应的value集合
- (BOOL)inDatabase:(NSString *)sql
            values:(NSArray *)arguments;

- (NSString *)getAndWhereStrWithOptions:(NSDictionary *)params;


- (NSMutableArray *)queryByTable:(NSString *)tableName
                          key:(NSString *)key
                     inValues:(NSArray *)array
                      orderBy:(NSArray<NSString *> *)orderKeys
                    orderType:(NSArray<NSString *> *)types
                        limit:(NSInteger)limit
                       offSet:(NSInteger)offset;


/// 查询表中数据
/// @param tableName 表名称
/// @param whereStr 查询条件
/// @param orderKeys 排序字段
/// @param types 对应排序字段 asc/desc
/// @param limit limit count
/// @param offset 偏移量
- (NSMutableArray *)queryByTable:(NSString *)tableName
                          where:(NSString *)whereStr
                        orderBy:(NSArray<NSString *> *)orderKeys
                      orderType:(NSArray<NSString *> *)types
                          limit:(NSInteger)limit
                         offSet:(NSInteger)offset;

/// 查询表中数据
/// @param sqlStr 查询语句
- (NSMutableArray *)queryBySqlStr:(NSString *)sqlStr;


/// 查询表中数据
/// @param tableName 表名称
/// @param whereStr 查询条件
- (NSInteger)queryCountFromTable:(NSString *)tableName
                           where:(NSString *)whereStr;



/// 删除数据
/// @param tableName 表名称
/// @param whereStr where条件
- (BOOL)deleteFromTable:(NSString *)tableName
                  where:(NSString *)whereStr;



/// 删除表中所有数据
/// @param tableName 表名称
- (BOOL)deleteAllDataFromTable:(NSString *)tableName;



/// 删除表中key in array 的所有数据
/// @param tableName 表名称
/// @param key key名称
/// @param array value枚举
- (BOOL)deleteFromTable:(NSString *)tableName
                    key:(NSString *)key
               inValues:(NSArray *)array;


/// 删除表中数据
/// @param tableName 表名称
/// @param whereStr 查询条件
/// @param orderKeys 排序字段
/// @param types 对应排序字段 asc/desc
/// @param limit limit count
/// @param offset 偏移量
- (BOOL)deleteFromTable:(NSString *)tableName
                  where:(NSString *)whereStr
                orderBy:(NSArray<NSString *> *)orderKeys
              orderType:(NSArray<NSString *> *)types
                  limit:(NSInteger)limit
                 offSet:(NSInteger)offset;




/// 将字典数据插入表中，其中字典中的key需要是表中的字段，否则会报错
/// @param tableName 表名称
/// @param payload keyValues
- (BOOL)insertOrReplace:(NSString *)tableName
                payload:(NSDictionary *)payload;



@end
