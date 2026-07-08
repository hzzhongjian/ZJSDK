#import <Foundation/Foundation.h>

@class WindHTTPMessage;
@class WindAsyncSocket;


#define WindWebSocketDidDieNotification  @"WindWebSocketDidDie"

@interface WindWebSocket : NSObject
{
	dispatch_queue_t websocketQueue;
	
	WindHTTPMessage *request;
    WindAsyncSocket *asyncSocket;
	
	NSData *term;
	
	BOOL isStarted;
	BOOL isOpen;
	BOOL isVersion76;
	
	id __unsafe_unretained delegate;
}

+ (BOOL)isWindWebSocketRequest:(WindHTTPMessage *)request;

- (id)initWithRequest:(WindHTTPMessage *)request socket:(WindAsyncSocket *)socket;

/**
 * Delegate option.
 * 
 * In most cases it will be easier to subclass WindWebSocket,
 * but some circumstances may lead one to prefer standard delegate callbacks instead.
**/
@property (/* atomic */ unsafe_unretained) id delegate;

/**
 * The WindWebSocket class is thread-safe, generally via it's GCD queue.
 * All public API methods are thread-safe,
 * and the subclass API methods are thread-safe as they are all invoked on the same GCD queue.
**/
@property (nonatomic, readonly) dispatch_queue_t websocketQueue;

/**
 * Public API
 * 
 * These methods are automatically called by the WindHTTPServer.
 * You may invoke the stop method yourself to close the WindWebSocket manually.
**/
- (void)start;
- (void)stop;

/**
 * Public API
 *
 * Sends a message over the WindWebSocket.
 * This method is thread-safe.
 **/
- (void)sendMessage:(NSString *)msg;

/**
 * Public API
 *
 * Sends a message over the WindWebSocket.
 * This method is thread-safe.
 **/
- (void)sendData:(NSData *)msg;

/**
 * Subclass API
 * 
 * These methods are designed to be overriden by subclasses.
**/
- (void)didOpen;
- (void)didReceiveMessage:(NSString *)msg;
- (void)didClose;

@end

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark -
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * There are two ways to create your own custom WindWebSocket:
 * 
 * - Subclass it and override the methods you're interested in.
 * - Use traditional delegate paradigm along with your own custom class.
 * 
 * They both exist to allow for maximum flexibility.
 * In most cases it will be easier to subclass WindWebSocket.
 * However some circumstances may lead one to prefer standard delegate callbacks instead.
 * One such example, you're already subclassing another class, so subclassing WindWebSocket isn't an option.
**/

@protocol WindWebSocketDelegate
@optional

- (void)webSocketDidOpen:(WindWebSocket *)ws;

- (void)webSocket:(WindWebSocket *)ws didReceiveMessage:(NSString *)msg;

- (void)webSocketDidClose:(WindWebSocket *)ws;

@end
