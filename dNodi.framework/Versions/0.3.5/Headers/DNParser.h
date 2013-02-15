//
//  DNParser.h
//  dNodi
//
//  Created by Derek Clarkson on 7/22/11.
//  Copyright 2011. All rights reserved.
//

#import "DNSelectorFactory.h"

/**
 Parser which analyses a query and generates an array of selectors which can then be run against the nodes.
 */
@interface DNParser : NSObject {
@private
	NSMutableCharacterSet *validNodeNameCharacters;
	NSMutableString *attributeName;
	DNSelectorFactory *selectorFactory;
	NSString *endingQuote;
   NSScanner *scanner;
   NSUInteger scanStartIndex;
   BOOL scanValue;
   BOOL scanningAttributeName;
}

/**
 Gives access to the selector factory. Mainly for convenience and testing.
 */
@property (retain, nonatomic) DNSelectorFactory *selectorFactory;

/**
 Analyses the passed query and generates a list of selectors.

 @param query the query to process.
 @param error a reference to an NSError variable that will be populated if there is any problem. In this case the returned array will be nil.
 @return an array of the found nodes. Or nil if there is an error in the error reference.
 */
-(NSArray *) selectorsForQuery:(NSString *) query error:(NSError **) error;

@end
