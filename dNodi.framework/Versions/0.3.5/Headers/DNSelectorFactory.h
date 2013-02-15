//
//  DNSelectorFactory.h
//  dNodi
//
//  Created by Derek Clarkson on 25/07/11.
//  Copyright 2011. All rights reserved.
//

#import "DNValueFactory.h"

// This enums tells us the types of the tokens being read that can be read.
typedef enum {
	DNTokenTypeStart =0,
	DNTokenTypeSlash,
	DNTokenTypeNodeName,
	DNTokenTypeOpenBracket,
	DNTokenTypeCloseBracket,
	DNTokenTypeNumber,
	DNTokenTypeSubtree,
	DNTokenTypeParent,
	DNTokenTypeEnd,
	DNTokenTypeAttributeIndicator, 
	DNTokenTypeAttributeName, 
	DNTokenTypeEquals,
	DNTokenTypeOpenQuote,
	DNTokenTypeValue,
	DNTokenTypeCloseQuote,
   DNTokenTypeDotNotation,
	DNTokenTypeError
} DNTokenType;

/**
 Factory class which receives instructions from DNParser and constructs a list of selectors to execute.
 */
@interface DNSelectorFactory : NSObject {
@private
	BOOL NodeSpecification;
	BOOL subtreeSearch;
	NSMutableArray *selectors;
	NSString *attributeName;
	DNValueFactory *valueFactory;
}

/// The list of selectors constructed so far.
@property (readonly, nonatomic) NSArray *selectors;

/// @name Tasks

/**
 Called to pass a read token across.
 
 @param token the token enum that was just read.
 @param value the value associated with the token or nil if there is none.
 */
-(void) didReadToken:(DNTokenType) token value:(id) value;

/**
 If we are going to start reading a new query. Call this first to setup for it.
 */
-(void) reset;

@end
