#import <Foundation/Foundation.h>

@class WindAsyncSocket;
@class WindHTTPMessage;
@class WindHTTPServer;
@class WindWebSocket;
@protocol WindHTTPResponse;


#define WindHTTPConnectionDidDieNotification  @"WindHTTPConnectionDidDie"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark -
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

@interface WindHTTPConfig : NSObject
{
	WindHTTPServer __unsafe_unretained *server;
	NSString __strong *documentRoot;
	dispatch_queue_t queue;
}

- (id)initWithServer:(WindHTTPServer *)server documentRoot:(NSString *)documentRoot;
- (id)initWithServer:(WindHTTPServer *)server documentRoot:(NSString *)documentRoot queue:(dispatch_queue_t)q;

@property (nonatomic, unsafe_unretained, readonly) WindHTTPServer *server;
@property (nonatomic, strong, readonly) NSString *documentRoot;
@property (nonatomic, readonly) dispatch_queue_t queue;

@end

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark -
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

@interface WindHTTPConnection : NSObject
{
	dispatch_queue_t connectionQueue;
    WindAsyncSocket *asyncSocket;
	WindHTTPConfig *config;
	
	BOOL started;
	
	WindHTTPMessage *request;
	unsigned int numHeaderLines;
	
	BOOL sentResponseHeaders;
	
	NSString *nonce;
	long lastNC;
	
	NSObject<WindHTTPResponse> *httpResponse;
	
	NSMutableArray *ranges;
	NSMutableArray *ranges_headers;
	NSString *ranges_boundry;
	int rangeIndex;
	
	UInt64 requestContentLength;
	UInt64 requestContentLengthReceived;
	UInt64 requestChunkSize;
	UInt64 requestChunkSizeReceived;
  
	NSMutableArray *responseDataSizes;
}

- (id)initWithAsyncSocket:(WindAsyncSocket *)newSocket configuration:(WindHTTPConfig *)aConfig;

- (void)start;
- (void)stop;

- (void)startConnection;

- (BOOL)supportsMethod:(NSString *)method atPath:(NSString *)path;
- (BOOL)expectsRequestBodyFromMethod:(NSString *)method atPath:(NSString *)path;

- (BOOL)isSecureServer;
- (NSArray *)sslIdentityAndCertificates;

- (BOOL)isPasswordProtected:(NSString *)path;
- (BOOL)useDigestAccessAuthentication;
- (NSString *)realm;
- (NSString *)passwordForUser:(NSString *)username;

- (NSDictionary *)parseParams:(NSString *)query;
- (NSDictionary *)parseGetParams;

- (NSString *)requestURI;

- (NSArray *)directoryIndexFileNames;
- (NSString *)filePathForURI:(NSString *)path;
- (NSString *)filePathForURI:(NSString *)path allowDirectory:(BOOL)allowDirectory;
- (NSObject<WindHTTPResponse> *)httpResponseForMethod:(NSString *)method URI:(NSString *)path;
- (WindWebSocket *)webSocketForURI:(NSString *)path;

- (void)prepareForBodyWithSize:(UInt64)contentLength;
- (void)processBodyData:(NSData *)postDataChunk;
- (void)finishBody;

- (void)handleVersionNotSupported:(NSString *)version;
- (void)handleAuthenticationFailed;
- (void)handleResourceNotFound;
- (void)handleInvalidRequest:(NSData *)data;
- (void)handleUnknownMethod:(NSString *)method;

- (NSData *)preprocessResponse:(WindHTTPMessage *)response;
- (NSData *)preprocessErrorResponse:(WindHTTPMessage *)response;

- (void)finishResponse;

- (BOOL)shouldDie;
- (void)die;

@end

@interface WindHTTPConnection (AsynchronousWindHTTPResponse)
- (void)responseHasAvailableData:(NSObject<WindHTTPResponse> *)sender;
- (void)responseDidAbort:(NSObject<WindHTTPResponse> *)sender;
@end
