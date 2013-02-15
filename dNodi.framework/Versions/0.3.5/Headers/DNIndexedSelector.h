//
//  DNIndexedSubNodeRule.h
//  dXml
//
//  Created by Derek Clarkson on 27/01/10.
//  Copyright 2010 Derek Clarkson. All rights reserved.
//

#import "DNAbstractSelector.h"

/**
 Simple selector which finds the nth occurance of a subnode of the current node. 
 */
@interface DNIndexedSelector : DNAbstractSelector {
	@private
	int index;
}

/// The index (0 based) of the node we want from the subnodes.
@property (nonatomic) int index;

/// @name Initialisation


/**
 Main initialiser
 
 @param anIndex the index of the subnode we want.
 */
- (id) initWithIndex:(NSInteger)anIndex;

@end
