//
//  NSError+sUsefulStuff.h
//  dUsefulStuff
//
//  Created by Derek Clarkson on 16/09/12.
//
//

#import <Foundation/Foundation.h>

/**
 Category of useful NSError methods.
 */

@interface NSError (dUsefulStuff)

/// Checks both localizedFailureReason then localizedDescription and returns the first that has text.
-(NSString *) localizedErrorMessage;

@end
