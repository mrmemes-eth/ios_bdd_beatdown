//
//  NSArray+dNodi.h
//  dNodi
//
//  Created by Derek Clarkson on 7/22/11.
//  Copyright 2011. All rights reserved.
//

#import "DNNode.h"

/**
 Category which provides so easy access methods for dealing with results from queries.
 */
@interface NSArray (dNodi)

/**
 Returns the nth node from the list.
 
 @param index the index of the wanted node.
 */
-(NSObject<DNNode> *) nodeAtIndex:(NSUInteger) index;

@end
