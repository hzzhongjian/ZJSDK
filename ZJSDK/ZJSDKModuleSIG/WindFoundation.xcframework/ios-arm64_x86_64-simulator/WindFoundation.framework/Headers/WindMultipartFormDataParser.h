
#import <WindFoundation/WindMultipartMessageHeader.h>

/* 
Part one: http://tools.ietf.org/html/rfc2045 (Format of Internet Message Bodies)
Part two: http://tools.ietf.org/html/rfc2046 (Media Types)
Part three: http://tools.ietf.org/html/rfc2047 (Message Header Extensions for Non-ASCII Text)
Part four: http://tools.ietf.org/html/rfc4289 (Registration Procedures) 
Part five: http://tools.ietf.org/html/rfc2049 (Conformance Criteria and Examples) 
 
Internet message format:  http://tools.ietf.org/html/rfc2822

WindMultipart/form-data http://tools.ietf.org/html/rfc2388
*/

@class WindMultipartFormDataParser;

//-----------------------------------------------------------------
// protocol WindMultipartFormDataParser
//-----------------------------------------------------------------

@protocol WindMultipartFormDataParserDelegate <NSObject> 
@optional
- (void) processContent:(NSData*) data WithHeader:(WindMultipartMessageHeader*) header;
- (void) processEndOfPartWithHeader:(WindMultipartMessageHeader*) header;
- (void) processPreambleData:(NSData*) data;
- (void) processEpilogueData:(NSData*) data;
- (void) processStartOfPartWithHeader:(WindMultipartMessageHeader*) header;
@end

//-----------------------------------------------------------------
// interface WindMultipartFormDataParser
//-----------------------------------------------------------------

@interface WindMultipartFormDataParser : NSObject {
NSMutableData*						pendingData;
    NSData*							boundaryData;
    WindMultipartMessageHeader*			currentHeader;

	BOOL							waitingForCRLF;
	BOOL							reachedEpilogue;
	BOOL							processedPreamble;
	BOOL							checkForContentEnd;

#if __has_feature(objc_arc_weak)
	__weak id<WindMultipartFormDataParserDelegate>                  delegate;
#else
	__unsafe_unretained id<WindMultipartFormDataParserDelegate>     delegate;
#endif	
	int									currentEncoding;
	NSStringEncoding					formEncoding;
}

- (BOOL) appendData:(NSData*) data;

- (id) initWithBoundary:(NSString*) boundary formEncoding:(NSStringEncoding) formEncoding;

#if __has_feature(objc_arc_weak)
    @property(weak, readwrite) id delegate;
#else
    @property(unsafe_unretained, readwrite) id delegate;
#endif
@property(readwrite) NSStringEncoding	formEncoding;

@end
