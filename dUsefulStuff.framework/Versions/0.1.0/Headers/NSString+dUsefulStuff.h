//
//  NSString+dUsefulStuff.h
//  dUsefulStuff
//
//  Created by Derek Clarkson on 25/09/11.
//  Copyright (c) 2011. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Category which adds useful functions to the NSString class.
 */
@interface NSString (dUsefulStuff)
/**
 Examines the contents of the string and if it is one of the following values, sets the passed boolean reference.
 
 Valid strings are yes, no, true, false.
 
 @param boolRef a pointer to a boolean variable which will be set if the string contains a valid boolean string value.
 @result YES if a boolean was successfullly read. NO otherwise.
 */
-(BOOL) readBooleanInto:(BOOL*) boolRef;

/**
 Prints the string to the log using an optimized layout. This is mainly useful for printing logging data. It makes use of CFShow to gain full control of
 the text that is printed.
 
 @param object the object that is sending the log message.
 @param selector the selector that is executing the log line
 @param line the line number
 */
-(void) logForObject:(id) object
				function:(NSString *) selector
					 line:(NSUInteger) line;

/**
 Using the passed format, prints the string to the log. This is mainly useful for printing logging data. It makes use of CFShow to gain full control of
 the text that is printed. This delegates to logForObject:function:line:
 
 @param object the object that is sending the log message.
 @param selector the selector that is executing the log line
 @param line the line number
 @param message the message to be printed.
 */
+(void) logObject:(id) object
			function:(NSString *) selector
				 line:(NSUInteger) line
			 message:(NSString *) message;

@end
