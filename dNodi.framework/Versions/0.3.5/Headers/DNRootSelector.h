//
//  DNRootNodeRule.h
//  dXml
//
//  Created by Derek Clarkson on 25/01/10.
//  Copyright 2010 Derek Clarkson. All rights reserved.
//

#import "DNAbstractSelector.h"

/**
 Simple selector which traverses back up the tree from the current node until it finds a node with no parent. This node is assumed to be the root node of the data structure and is returned.
 */
@interface DNRootSelector : DNAbstractSelector {
	@private
}

@end
