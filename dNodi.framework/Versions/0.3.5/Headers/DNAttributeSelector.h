//
//  DNAttributeSelector.h
//  dNodi
//
//  Created by Derek Clarkson on 29/07/11.
//  Copyright 2011. All rights reserved.
//

#import "DNAbstractSelector.h"

/**
 Attribute selectors are used when there is no node name being selected and an object attribute has been specified. It is left up to the implementation to intepret how the attribute name and value relate to the underlying data.
 */
@interface DNAttributeSelector : DNAbstractSelector{
	@private
}

/// @name Properties

/// The attribute name.
@property(retain, nonatomic) NSString *attributeName;

/// The value to compare.
@property(retain, nonatomic) id value;

/// @name Initialisation

/**
 Default initialiser with the attribute name and value.
 
 @param attributeName the name of the attribute.
 @param value the value to be checked. The DCSelectorFactory class will pass either a NSNumber for numbers and boolean values or  NSString value.
 @return YES if there is a match.
 */
- (id) initWithAttributeName:(NSString *)attributeName value:(id) value;

@end
