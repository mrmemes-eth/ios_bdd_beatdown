//
//  DNSubtreeSelector.h
//  dXml
//
//  Created by Derek Clarkson on 7/02/10.
//  Copyright 2010 Derek Clarkson. All rights reserved.
//

/**
 * Selector which can search all DNNode nodes below the current node. This will traverse the entire tree below the node and matches all subnodes again the specified name.
 */

#import "DNAbstractSelector.h"


@interface DNSubtreeSelector : DNAbstractSelector {
@protected
	NSString *nodeName;
}

/// The name of the node we are looking for.
@property (retain,nonatomic) NSString * nodeName;

/// @name Intialisation

/**
 Main constructor
 
 @param aNodeName the node name to look for.
 */
- (id) initWithNodeName:(NSString *)aNodeName;

@end
