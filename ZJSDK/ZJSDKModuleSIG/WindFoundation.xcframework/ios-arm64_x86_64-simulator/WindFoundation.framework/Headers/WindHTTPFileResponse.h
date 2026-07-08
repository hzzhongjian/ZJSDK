#import <Foundation/Foundation.h>
#import <WindFoundation/WindHTTPResponse.h>

@class WindHTTPConnection;


@interface WindHTTPFileResponse : NSObject <WindHTTPResponse>
{
	WindHTTPConnection *connection;
	
	NSString *filePath;
	UInt64 fileLength;
	UInt64 fileOffset;
	
	BOOL aborted;
	
	int fileFD;
	void *buffer;
	NSUInteger bufferSize;
}

- (id)initWithFilePath:(NSString *)filePath forConnection:(WindHTTPConnection *)connection;
- (NSString *)filePath;

@end
