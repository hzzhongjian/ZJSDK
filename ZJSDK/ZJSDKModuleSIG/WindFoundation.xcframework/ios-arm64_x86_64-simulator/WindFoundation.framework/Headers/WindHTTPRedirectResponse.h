#import <Foundation/Foundation.h>
#import <WindFoundation/WindHTTPResponse.h>


@interface WindHTTPRedirectResponse : NSObject <WindHTTPResponse>
{
	NSString *redirectPath;
}

- (id)initWithPath:(NSString *)redirectPath;

@end
