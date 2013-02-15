//
//  NSObject+dUsefulStuff.h
//  dUsefulStuff
//
//  Created by Derek Clarkson on 7/20/11.
//  Copyright 2011. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Category of useful methods for all objects.
 */
@interface NSObject (dUsefulStuff)

/**
 This creates NSError objects based on the passed information. It wraps some some boiler plate code for creating instances populated with the correct user info
 data for Cocoa dialogs to display.
 
 @param errorCode the error code you want to use.
 @param errorDomain the domain associated with the error.
 @param shortDescription the short description text displayed automatically in error dialogs.
 @param failureReason the more detailed text of the error.
 */
-(NSError *) errorForCode:(NSInteger) errorCode 
				  errorDomain:(NSString *) errorDomain 
			shortDescription:(NSString *) shortDescription 
				failureReason:(NSString *) failureReason; 

/**
 This creates NSError objects based on the passed information and sets it into the original error reference, but only if NULL has not been passed. 
 This matches Apple's error handling recommendations. It wraps some some boiler plate code for creating instances populated with the correct user info
 data for Cocoa dialogs to display.
 
 @param error a reference to a pointer to an error instance. The original reference will be populated.
 @param errorCode the error code you want to use.
 @param errorDomain the domain associated with the error.
 @param shortDescription the short description text displayed automatically in error dialogs.
 @param failureReason the more detailed text of the error.
 @return always returns YES.
 */
-(BOOL) setError:(NSError **) error 
				code:(NSInteger) errorCode 
	  errorDomain:(NSString *) errorDomain 
shortDescription:(NSString *) shortDescription 
	failureReason:(NSString *) failureReason; 

@end
