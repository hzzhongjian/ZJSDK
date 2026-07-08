//
//  WindHCRange.h
//  WindHTTPCache
//
//  Created by Single on 2018/5/20.
//  Copyright © 2018年 Single. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef struct WindHCRange {
    long long start;
    long long end;
} WindHCRange;

static const long long WindHCNotFound = LLONG_MAX;

BOOL WindHCRangeIsFull(WindHCRange range);
BOOL WindHCRangeIsVaild(WindHCRange range);
BOOL WindHCRangeIsInvaild(WindHCRange range);
BOOL WindHCEqualRanges(WindHCRange range1, WindHCRange range2);
long long WindHCRangeGetLength(WindHCRange range);
NSString * WindHCStringFromRange(WindHCRange range);
NSDictionary * WindHCRangeFillToRequestHeaders(WindHCRange range, NSDictionary *headers);
NSDictionary * WindHCRangeFillToRequestHeadersIfNeeded(WindHCRange range, NSDictionary *headers);
NSDictionary * WindHCRangeFillToResponseHeaders(WindHCRange range, NSDictionary *headers, long long totalLength);

WindHCRange WindHCMakeRange(long long start, long long end);
WindHCRange WindHCRangeZero(void);
WindHCRange WindHCRangeFull(void);
WindHCRange WindHCRangeInvaild(void);
WindHCRange WindHCRangeWithSeparateValue(NSString *value);
WindHCRange WindHCRangeWithRequestHeaderValue(NSString *value);
WindHCRange WindHCRangeWithResponseHeaderValue(NSString *value, long long *totalLength);
WindHCRange WindHCRangeWithEnsureLength(WindHCRange range, long long ensureLength);
