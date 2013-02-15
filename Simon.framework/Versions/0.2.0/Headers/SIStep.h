//
//  Step.h
//  Simon
//
//  Created by Derek Clarkson on 5/30/11.
//  Copyright 2011. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Simon/SIConstants.h>
#import <Simon/SIStepMapping.h>
#import <Simon/SIJsonAware.h>

/**
 Represents a step within a SIStory. It stores the text of the step as read from the story file and the SISTepMapping which is then used to execute the implementation code.
 */
@interface SIStep : NSObject<SIJsonAware>

/// @name Properties

/// A SIKeyword enum value which we use to track what the keyword found at the beginning of the step. 
@property (nonatomic, readonly) SIKeyword keyword;

/// The full text of the step as read from the story file.
@property (nonatomic, retain) NSString *command;

/// The SIStepMapping which was matched to the step by the [SIStepMapping regex] expression.
@property (nonatomic, retain) SIStepMapping * stepMapping;

/**
 Indicates whether the mapping was executed. 
 */
@property (nonatomic, assign) BOOL executed;

/**
 If an exception is caught, it is stored here.
 */
@property (nonatomic, retain) NSException *exception;

/// The current executions status of the step.
@property (nonatomic, readonly) SIStepStatus status;

/// The status as a string.
@property (nonatomic, readonly) NSString *statusString;

/// @name Initialisation

/**
 Initialises the SIStep with the passed keyword and command. This is usually executed by the SIStory instance to which this step belongs to.
 
 @param aKeyword the keyword that starts the line of text stored in the command.
 @param theCommand the contents of the step as read from the story file.
 */
-(id) initWithKeyword:(SIKeyword) aKeyword command:(NSString *) theCommand;

/// @name Mapping and execution

/**
 During the mapping process, this method is called to locate the mapping that matches this step. It does this by looping through each SIStepMapping
 in the passed NSArray and executing the [SIStepMapping regex] against it. If it's a match then this step will store a reference to the SIStepMapping.
 This will only map to the first SIStepMapping it finds.
 
 @param mappings the list of SIStepMappings to use when comparing.
 */
-(void) findMappingInList:(NSArray *) mappings;

/**
 Returns `YES` if the step has been mapping during the findMappingInList: method.
 */
-(BOOL) isMapped;

/**
 During executing the story, this is called to get the SIStepMapping to call the method using data from this step.
 
 @param object an instance of the class stored in [SIStepMapping targetClass]. This is created and cached by the SIStory which this step belongs to.
 @param error a reference to a pointer to an NSError object. If there is an error, the pointer will be set to point to an error object containing the details.
 @return YES if the execution was succcessful, NO if not.
 */
-(BOOL) invokeWithObject:(id) object error:(NSError **) error;

/**
 Called when we want to reset the state. Usually this is part of re-running a story.
 */
-(void) reset;

@end
