#import <WindFoundation/WindHTTPResponse.h>

@interface WindHTTPErrorResponse : NSObject <WindHTTPResponse> {
    NSInteger _status;
}

- (id)initWithErrorCode:(int)httpErrorCode;

@end
