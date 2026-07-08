//
//  WindTableBuilder.h
//  SQLIiteBuilder
//
//  Created by Codi on 2021/12/24.
//

#import <WindFoundation/WindSqlBuilder.h>

@interface WindTableBuilder : WindSqlBuilder

- (WindTableBuilder * (^)(NSString *value))table;

- (WindTableBuilder * (^)(NSString *value))column;

- (WindTableBuilder * (^)(void))notNull;
- (WindTableBuilder * (^)(void))primaryKey;
- (WindTableBuilder * (^)(void))autoincrement;

//为文本格式
- (WindTableBuilder * (^)(void))text;
- (WindTableBuilder * (^)(NSInteger len))varchar;
//值是一个带符号的整数，根据值的大小存储在 1、2、3、4、6 或 8 字节中
- (WindTableBuilder * (^)(void))integer;
//值是一个浮点值，存储为 8 字节的 IEEE 浮点数字。
- (WindTableBuilder * (^)(void))real;

@end
