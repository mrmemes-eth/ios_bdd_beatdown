//
//  DNNodeRule.h
//  dXml
//
//  Created by Derek Clarkson on 26/01/10.
//  Copyright 2010 Derek Clarkson. All rights reserved.
//

#import "DNAbstractSelector.h"
/**
 Selects a subnode based on it's name.
 */
@interface DNNodeNameSelector : DNAbstractSelector {
	@protected
	NSString *nodeName;
}

/// The name we are looking for.
@property (retain,nonatomic) NSString * nodeName;

/// @name Initialisation

/**
 Main initialiser.
 
 @param aNodeName the name we are looking for.
 */
- (id) initWithNodeName:(NSString *)aNodeName;

@end
