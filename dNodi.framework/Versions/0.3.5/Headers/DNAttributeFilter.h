//
//  DNAttributeFilter.h
//  dNodi
//
//  Created by Derek Clarkson on 28/07/11.
//  Copyright 2011. All rights reserved.
//

#import "DNFilter.h"

/**
 This filter searches for attributes of a node.
 */
@interface DNAttributeFilter : NSObject<DNFilter> {
	@private
}

/// The name of the attribute we are looking for.
@property (nonatomic, retain) NSString *attributeName;

/// The value we are to match against once the property has been found.
@property (nonatomic, retain) id value;

/// @name Initialisation

/**
 Main initialiser.
 
 @param attributeName the attribute we are looking for.
 @param value the value we want to match against.
 */
-(id) initWithAttribute:(NSString *) attributeName value:(id) value;

@end
