//
//  DNExcutor.h
//  dNodi
//
//  Created by Derek Clarkson on 24/01/10.
//  Copyright 2010 Derek Clarkson. All rights reserved.
//

#import "DNNode.h"

/**
 This class processes queries against the datastructure you have given it.
 
 The processing follows the w3school standard (Although I found it a bit hard to follow!) as near as I can. The reference I used 
 can be found at http://www.w3schools.com/XPath/xpath_syntax.asp Basically what happens is that unless there is a starting slash in the 
 query, navigation starts with the node that you send the request to. If there is a starting slash then the processing of the query
 starts from the root of the object graph.
 
 Query processing is designed to return multiple nodes if they exist. So specifying something like abc/[2] will bring back the secod sub nodes from all occurances of the "abc" Node. Not just the first. 
 
 Here is a list of the tokens you can use in the queries and how they are processed.
 - <b><i>Node-name</i></b> - returns all sub nodes with name <i>Node-name</i> which belong to the current node. 
 - <b>//<i>Node-name</i></b> - returns all occurances of <i>Node-name</i> from the current point in the document model and below. This 
 is regardless of where they occur so effective it is a search of all sub nodes and below.
 - <b>/</b> - delimiter between nodes of the query. <b>Note:</b> If this occurs at the start of the query then it causes the query to be regarded as an absolute query which starts from the root of the object model. 
 - <b>..</b> - refers back up to the parent of each of the current set of nodes. 
 - <b>.</b> - refers to the current node so doesn't really do anything as such, but is here for completeness. Allows queries like "./abc"
 - <b>[nn]</b> - This depends on how it is used. Combined with a node name it selects the nth node by that name. However, if used by itself, it selects the nth DNNode under the current nodes.
 - <b>[@attribute='value']</b> - looks for nodes with the specified attribute and value setting.
 */
@interface DNExecutor : NSObject {
@private
	NSObject<DNNode> *rootNode;
}

/**
 The starting node of the query. Normally this is the root node of a data structure but it can actually be any node in the tree. Thus is also possible to execute queries that start from the bottom of the tree and work backwards.
 */
@property (retain, nonatomic) NSObject<DNNode> *rootNode;

/**
 Default constructor.
 @param aRootNode the node from which to start the query. Note that this does not have to be the root node of the structure being queried. 
 */
- (DNExecutor *) initWithRootNode:(NSObject<DNNode> *)aRootNode;

/**
 Executes the passed query and returns whatever it finds.
 
 @param query This is the query string to be executed.
 @param error A reference to a variable which will be populated with an NSError should there be an issue with processing the query against the current model.
 @return a NSArray containing zero or more nodes. Or nil if an error was generated.
 */
- (NSArray *) executeQuery:(NSString *)query error:(NSError **)error;

@end

