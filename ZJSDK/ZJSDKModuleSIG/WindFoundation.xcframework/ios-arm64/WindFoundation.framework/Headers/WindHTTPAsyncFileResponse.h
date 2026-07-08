#import <Foundation/Foundation.h>
#import <WindFoundation/WindHTTPResponse.h>

@class WindHTTPConnection;

/**
 * This is an asynchronous version of WindHTTPFileResponse.
 * It reads data from the given file asynchronously via GCD.
 * 
 * It may be overriden to allow custom post-processing of the data that has been read from the file.
 * An example of this is the WindHTTPDynamicFileResponse class.
**/

@interface WindHTTPAsyncFileResponse : NSObject <WindHTTPResponse>
{	
	WindHTTPConnection *connection;
	
	NSString *filePath;
	UInt64 fileLength;
	UInt64 fileOffset;  // File offset as pertains to data given to connection
	UInt64 readOffset;  // File offset as pertains to data read from file (but maybe not returned to connection)
	
	BOOL aborted;
	
	NSData *data;
	
	int fileFD;
	void *readBuffer;
	NSUInteger readBufferSize;     // Malloced size of readBuffer
	NSUInteger readBufferOffset;   // Offset within readBuffer where the end of existing data is
	NSUInteger readRequestLength;
	dispatch_queue_t readQueue;
	dispatch_source_t readSource;
	BOOL readSourceSuspended;
}

- (id)initWithFilePath:(NSString *)filePath forConnection:(WindHTTPConnection *)connection;
- (NSString *)filePath;

@end
