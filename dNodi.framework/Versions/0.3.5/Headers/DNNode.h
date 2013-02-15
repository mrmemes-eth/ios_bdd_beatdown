//
//  DNNode.h
//  dNodi
//
//  Created by Derek Clarkson on 7/17/11.
//  Copyright 2011. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 DNNode is a protocol which represents the connection between dNodi and your data structure. Classes which implement this protocol can be used by dNodi to execute it's selectors and filters against.
 */
@protocol DNNode <NSObject>

/**
 Returns the name of the node.
 */
@property(readonly) NSString *dnName;

/**
 Returns a reference to the parent node of this node.
 */
@property(readonly) NSObject<DNNode> *dnParentNode;

/**
 Returns an array of the subnodes of this node. You can return either an empty NSArray or nil.
 */
@property(readonly) NSArray *dnSubNodes;

/**
 Returns the value of an attribute of the node. dNodi will pass one of three values through to this method when it is querying an attribute value using the DNAttributeFilter or DNAttributeSelector. If dNodi detects the BOOL keywords: YES, NO, TRUE or FALSE (upper or lowercase) it will pass a NSNumber set with the boolean equivalent. So use NSNumber::boolValue to get it back. if dNodi detects a number with no other extranious text, it will also pass in a NSNumber containing the value. Otherwise it passes in a NSString.
 
 @param attribute the attribute we want the value for.
 @param value the value we want to compare. It is up to the implementor how this is done.
 @return YES if there is an attribute with a matching value.
 */
-(BOOL) dnHasAttribute:(NSString *) attribute withValue:(id) value;

@end
