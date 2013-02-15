//
//  DNAbstractRule.h
//  dXml
//
//  Created by Derek Clarkson on 27/01/10.
//  Copyright 2010 Derek Clarkson. All rights reserved.
//

#import "DNNode.h"
#import "DNFilter.h"

/**
 Abstract parent class of all selectors. The basic idea of a selector is that it is presented with a node and asked to select further nodes based on that node. For example a parent node select is given a node and returns it's parent.
 In addition to this, selectors can also have multiple filters added to them. If a selector has filters, before adding a node to the list of nodes to be returned, each filter is asked if it is ok to add that node. Only if <b>all</b> filters agree, will the node be added.
 */
@interface DNAbstractSelector : NSObject {
	@protected
	NSMutableArray * filters;
}

/// A list of any filters that are to be applied to the list of nodes returned by the selector.
@property (readonly) NSArray *filters;

/// @name Tasks

/**
 Adds the passed filter to the list of filters.
 
 @param filter a DNFilter instance which is to be added to a list of filters to be run against the results of the selectors search.
 */
-(void) addFilter:(NSObject<DNFilter> *) filter;

/**
 Called for each node in the current list of nodes by DNExecutor. This should not be overridden because it contains the common processing applicable to all selectors.
 
 @param currentNode The current DCXmlNode to be used as the base node for the current query token.
 @param anIndex The index of the parent node in the list of current nodes being processed.
 @param anErrorVar A reference to a variable that will be populated with a NSError should something go wrong with trying to apply the query to the document model.
 @return An NSArray containing the nodes found by the selector. Unless an error is found, in which case this is nil.
 */
- (NSArray *) selectFromNode:(NSObject<DNNode> *)currentNode index:(int) anIndex errorVar:(NSError **) anErrorVar;

/**
 Called internally to obtain the nodes for the selector. Derived classes should implement this method to return the selected nodes.
 
 @param rootNode The node current being processed. It is the based from which the selector should select new nodes.
 @param anIndex The index of the current node in the list of nodes being processed.
 @return A NSArray of the nodes being selected. Note, as per the filter details, these nodes may not make it back to the DNExecutor.
 */
- (NSArray *) selectNodesFromNode:(NSObject<DNNode> * )rootNode index:(int) anIndex;

@end
