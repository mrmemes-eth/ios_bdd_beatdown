//
//  DNArrayIndexFilter.h
//  dXml
//
//  Created by Derek Clarkson on 27/01/10.
//  Copyright 2010 Derek Clarkson. All rights reserved.
//

#import "DNFilter.h"

/**
 Filter that only accepts a single node, depending on it's index within it's parent node.
 */
@interface DNIndexFilter : NSObject<DNFilter> {
	@private
	int index;
}

/// @name Initialisation

/**
 Main initialiser.
 
 @param anIndex the index of the node to return.
 */
- (DNIndexFilter *) initWithIndex:(int)anIndex;

@end
