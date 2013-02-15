//
//  DNNodeFilter.h
//  dXml
//
//  Created by Derek Clarkson on 2/02/10.
//  Copyright 2010 Derek Clarkson. All rights reserved.
//

#import "DNFilter.h"

/**
 * Filters NSObject<DNNode> objects and only accepts nodes which have the specified name. What that name represents in your datastructure is decided by the class that implements DNNode.
 */
@interface DNNodeNameFilter : NSObject<DNFilter> {
	@private
	NSString *nodeName;
}

/// The name we are looking for.
@property (retain, nonatomic) NSString *nodeName;

/// @name Initialisation

/**
 Main initialiser.
 
 @param aNodeName the name we are to look for.
 */
- (DNNodeNameFilter *) initWithNodeName:(NSString *)aNodeName;

@end
