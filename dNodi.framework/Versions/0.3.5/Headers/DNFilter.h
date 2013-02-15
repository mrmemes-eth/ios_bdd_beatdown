//
//  untitled.h
//  dXml
//
//  Created by Derek Clarkson on 27/01/10.
//  Copyright 2010 Derek Clarkson. All rights reserved.
//
#import "DNNode.h"

/**
 A filter is called once for each DNNode that will be added to the new current list of nodes. It provides the ability
 to do additional processing based on the node or it's index within it's parent node.
 */
@protocol DNFilter
/**
 This method is called for each node added to the list in the selector.
 
 @param node A reference to the node being added. 
 @param anIndex The index of the node within the list of returned nodes from a selector. This is 0 based.
 @returns YES if the node should be added to the results, NO if it should not.
 */
- (BOOL) acceptNode:(NSObject<DNNode> *)node index:(int)anIndex;

@end
