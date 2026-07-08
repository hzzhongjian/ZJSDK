#import <Foundation/Foundation.h>


@interface NSNumber (WindDDNumber)

+ (BOOL)wind_parseString:(NSString *)str intoSInt64:(SInt64 *)pNum;
+ (BOOL)wind_parseString:(NSString *)str intoUInt64:(UInt64 *)pNum;

+ (BOOL)wind_parseString:(NSString *)str intoNSInteger:(NSInteger *)pNum;
+ (BOOL)wind_parseString:(NSString *)str intoNSUInteger:(NSUInteger *)pNum;

@end
