/**
 * WindDDRange is the functional equivalent of a 64 bit NSRange.
 * The WindHTTP Server is designed to support very large files.
 * On 32 bit architectures (ppc, i386) NSRange uses unsigned 32 bit integers.
 * This only supports a range of up to 4 gigabytes.
 * By defining our own variant, we can support a range up to 16 exabytes.
 * 
 * All effort is given such that WindDDRange functions EXACTLY the same as NSRange.
**/

#import <Foundation/NSValue.h>
#import <Foundation/NSObjCRuntime.h>

@class NSString;

typedef struct _WindDDRange {
    UInt64 location;
    UInt64 length;
} WindDDRange;

typedef WindDDRange *WindDDRangePointer;

NS_INLINE WindDDRange WindDDMakeRange(UInt64 loc, UInt64 len) {
    WindDDRange r;
    r.location = loc;
    r.length = len;
    return r;
}

NS_INLINE UInt64 WindDDMaxRange(WindDDRange range) {
    return (range.location + range.length);
}

NS_INLINE BOOL WindDDLocationInRange(UInt64 loc, WindDDRange range) {
    return (loc - range.location < range.length);
}

NS_INLINE BOOL WindDDEqualRanges(WindDDRange range1, WindDDRange range2) {
    return ((range1.location == range2.location) && (range1.length == range2.length));
}

FOUNDATION_EXPORT WindDDRange WindDDUnionRange(WindDDRange range1, WindDDRange range2);
FOUNDATION_EXPORT WindDDRange WindDDIntersectionRange(WindDDRange range1, WindDDRange range2);
FOUNDATION_EXPORT NSString *WindDDStringFromRange(WindDDRange range);
FOUNDATION_EXPORT WindDDRange WindDDRangeFromString(NSString *aString);

NSInteger WindDDRangeCompare(WindDDRangePointer pWindDDRange1, WindDDRangePointer pWindDDRange2);

@interface NSValue (NSValueWindDDRangeExtensions)

+ (NSValue *)wind_valueWithWindDDRange:(WindDDRange)range;
- (WindDDRange)wind_ddrangeValue;

- (NSInteger)wind_ddrangeCompare:(NSValue *)ddrangeValue;

@end
