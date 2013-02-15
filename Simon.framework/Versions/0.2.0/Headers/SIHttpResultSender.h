//
//  SIHttpResultSender.h
//  Simon
//
//  Created by Derek Clarkson on 9/08/12.
//  Copyright (c) 2012. All rights reserved.
//

#import <Simon/SIResultListener.h>
#import <Simon/SIHttpConnection.h>

/**
 Class which sends messages to Simon about the status of a run.
 */
@interface SIHttpResultSender : SIResultListener

/// @name Default initialiser

/**
 Inits the result sender with the passed connection.
 
 @param connection the connection to send results to.
 @return an instance of this class.
 */
-(id) initWithConnection:(SIHttpConnection *) connection;

@end
