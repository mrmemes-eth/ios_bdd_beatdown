//
//  DNValueFactory.h
//  dNodi
//
//  Created by Derek Clarkson on 21/09/11.
//  Copyright (c) 2011. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Used to create values from strings which have been read from a query path expression. Usually these are the attribute values when attributes have been specified.
 */
@interface DNValueFactory : NSObject

/**
 Generates the appropriate object for the passed string.
 
 @param string a string containing the value to be interpreted.
 @return If the string contains a number then an NSNumber, if a boolean true, false, yes or no then a NSNumber, anything else returns the original string.
 */
-(id) valueFromString:(NSString *) string;

@end
