//
//  SIMacros.h
//  Simon
//
//  Created by Derek Clarkson on 7/1/11.
//  Copyright 2011. All rights reserved.
//
#import <dUsefulStuff/DCCommon.h>
#import <Simon/SIStepMapping.h>
#import <Simon/SIUIApplication.h>
#import <Simon/SIConstants.h>
#import <Simon/SIStory.h>

/**
 These two are used to convert a sequence of chars to a string constant. We used this to convert a selector to a string constant within a macro when part of the macro name is the current line number macro __LINE__. Again we need that extra level of indirection to fix the translation of the parameter when stringification is involved.
 */
#define toNSString(chars) _toNSString(chars)
#define _toNSString(chars) @#chars

#pragma mark - Runners

/**
 This macro must be placed in your startup code. 
 */
#define SIRun() DC_LOG(@"Starting backpack"); \
[SIAppBackpack backpack];

#pragma mark - Step mapping

/**
 This macro maps a regex to a selector in the current class. Simon expects that the order and type of any groups in the regex will
 match the order and types of arguments in the selector. So we recommend that this is used before the selector like this
 `
 SIMapStepToSelector(@"then use \"(.*)\" as the string value", thisIsMyMethod:);
 -(void) thisIsMyMethod:(NSString *) stringValue {
 ...
 }
 `
 */
#define SIMapStepToSelector(theRegex, aSelector) \
+(SIStepMapping *) DC_CONCATINATE(SI_STEP_METHOD_PREFIX, __LINE__):(Class) class { \
   DC_LOG(@"Creating mapping \"%@\" -> %@::%@", theRegex, NSStringFromClass(class), toNSString(aSelector)); \
   NSError *error = nil; \
   SIStepMapping *mapping = [SIStepMapping stepMappingWithClass:class selector:@selector(aSelector) regex:theRegex error:&error]; \
   if (mapping == nil) { \
      @throw [NSException exceptionWithName:@"SIMappingException" reason:error.localizedDescription userInfo:error.userInfo]; \
   } \
   return mapping; \
}

#pragma mark - Storing data

/**
 * Macro which stores data in the story so it can be passed between implmentation classes. 
 */
#define SIStoreInStory(key, value) [(SIStory *) objc_getAssociatedObject(self, SI_INSTANCE_STORY_REF_KEY) storeObject:value withKey:key]

/**
 * The opposite of SISToreInStory(key, value) this macro retrieves a previously stored value.
 */
#define SIRetrieveFromStory(key) [(SIStory *) objc_getAssociatedObject(self, SI_INSTANCE_STORY_REF_KEY) retrieveObjectWithKey:key]

#pragma mark - Accessing the UI
/// @name UI interactions

/**
 Prints a tree view of the current window's UIView hirachy to the console. This is very useful for debugging and working out queries to location controls. 
 */
#define SIPrintCurrentWindowTree() [[SIUIApplication application] logUITree]

/**
 Simple wrapper around dNodi's query facilities which returns a simple object from the display. This will trigger an error if the control is not found, so it is both a find and assert in one wrapper. 
 
 @param path a NSString containing the path to follow.
 @return a single UIView instance.
 */
#define SIFindView(path) [[SIUIApplication application] findViewWithQuery:path]

/**
 Finds and returns an array of views. This does not assert anything about the views it is looking for.
 
 @param query a NSString containing the path to follow.
 @return a NSArray containing the found views.
 */
#define SIFindViews(query) [[SIUIApplication application] findViewsWithQuery:query]

/**
 Returns YES if the query returns one or more UIViews.
 
 @param query a NSString containing the path to follow.
 @return YES if one or more views are found, otherwise NO.
 */
#define SIIsViewPresent(query) [[SIUIApplication application] isViewPresent:query]

/**
 Taps a UIView in a given direction and distance. The passed view can be either a UIView or a NSString containing a query which will locate it in the UI.
 
 @param view a NSString containing the path to the view or a UIView reference to the view.
 @return the UIView that was tapped.
 */
#define SITapView(view) \
	[(view) isKindOfClass:[NSString class]] ? \
	[[SIUIApplication application] tapViewWithQuery:(NSString *)view] : \
	[[SIUIApplication application] tapView:(UIView *)view]

/**
 Locates the button with the matching label and taps it.
 
 @param label the text label on the button to find.
 */
#define SITapButtonWithLabel(label) [[SIUIApplication application] tapButtonWithLabel:label]

/**
 Locates the button with the matching label and taps it, then waits for the specified seconds before continuing.

 @param label the text label on the button to find.
 @param seconds how many seconds and/or part seconds to wait after tapping the button.
 */
#define SITapButtonWithLabelAndWait(label, seconds) [[SIUIApplication application] tapButtonWithLabel:label andWait:seconds]

/**
 Locates the tab bar button with the matching label and taps it.
 
 @param label the text label of the tab bar button we want to tap.
 */
#define SITapTabBarButtonWithLabel(label) [[SIUIApplication application] tapTabBarButtonWithLabel:label]

/**
 Swipes a UIView in a given direction and distance. The passed view can be either a UIView or a NSString containing a query which will locate it in the UI.
 
 @param view a NSString containing the path to the view or a UIView reference to the view.
 @param direction a SIUISwipeDirection value which indicates which direction to swipe in.
 @param distance how far to swipe in display points.
 @return the UIView that was swiped.
 */
#define SISwipeView(view, direction, distance) \
[(view) isKindOfClass:[NSString class]] ? \
[[SIUIApplication application] swipeViewWithQuery:(NSString *)view inDirection:direction forDistance: distance] : \
[[SIUIApplication application] swipeView:(UIView *)view inDirection:direction forDistance: distance]

/**
 Pauses the current thread for the specified time. Note that this will only work on a background thread.
 
 @param seconds how many seconds to pause for.
 */
#define SIPauseFor(seconds) [[SIUIApplication application] pauseFor:seconds]

/**
 Checks for the existance of a query path on the UI periodically, up to a specified number of retries. Returns the control found (can be only one) or throws an
 exception if it is not found before the max number of retries is exected.
 
 @param query the query path that should locate the control.
 @param retryEvery the time interval between retries.
 @param maxRetryAttempts how many times to attempt to find the control before throwing an exception.
 */
#define SIWaitForView(query, retryEvery, maxRetryAttempts) [[SIUIApplication application] waitForViewWithQuery:query retryInterval:retryEvery maxRetries:maxRetryAttempts]

/**
 Finds the view defined by path and waits until any animations which are active on it finish processing. This is tested periodically as defined by the checkEvery argument.
 Note that this takes into account any animations running on super views as well. So you can check a control which is on a view which is sliding on and it will be 
 regarded as being animated even though the control itself is not.

 @param query the query path that should locate the control.
 @param checkEvery the time interval to wait before checking for animations.
*/
#define SIWaitForViewAnimationsToFinish(query, checkEvery) [[SIUIApplication application] waitForAnimationEndOnViewWithQuery:query retryInterval:checkEvery];

/**
 Brings up the keyboard and enters text into the field. If a query is passed this first finds the field before activating the keyboard.
 A SIUINotAnInputFieldException will be thrown if the passed view does not implement the UITextInput protocol.
 
 @param query the query path that should locate the control.
 @param text the text that you want entered. It is assumed that the text can be entered. I.e. that the field accepts it.
 */ 
#define SIEnterText(view, text) \
[(view) isKindOfClass:[NSString class]] ? \
[[SIUIApplication application] enterText: text intoViewWithQuery:(NSString *)view] : \
[[SIUIApplication application] enterText: text intoView:(UIView *)view]
 
/**
 But first some reuseable logic embedded in a macro.
 */

/// @name Basic Assertions

// These have been written because the others I was modelling off only worked within their respective frameworks. They take two forms. The base form is a simple macro. The *M form takes an addition set of parameters where you can specify a custom message. 

#pragma mark - Basic assertions

#define ASSERTION_EXCEPTION_NAME @"SIAssertionException"

#define SIThrowException(name, msgTemplate, ...) \
do { \
   NSString *_message = [NSString stringWithFormat:msgTemplate, ## __VA_ARGS__]; \
   NSString *_finalMessage = [NSString stringWithFormat:@"%s(%d) %@", __PRETTY_FUNCTION__, __LINE__, _message]; \
   DC_LOG(@"Throwing exception with message: %@", _finalMessage); \
   @throw [NSException exceptionWithName:name reason:_finalMessage userInfo:nil]; \
} while (NO)

/** 
 Generates a failure unconditionally. 
 */
#define SIFail() SIFailM(@"SIFail executed, throwing failure exception.")

/**
 Fail if the passed object variable is not a nil value.
 
 @param obj a variable of type id or NSObject* to test.
 */
#define SIAssertNotNil(obj) SIAssertNotNilM(obj, @"SIAssertNotNil(" #obj ") '" #obj "' should be a valid object.")

/**
 Fail if the passed object variable is a nil value.
 
 @param obj a variable of type id or NSObject* to test.
 */
#define SIAssertNil(obj) SIAssertNilM(obj, @"SIAssertNil(" #obj ") Expecting '" #obj "' to be nil.")

/**
 Fail if the passed BOOL variable is NO.
 
 @param exp an expression that is expected to resolve to a BOOL value. The expression can just be a simple BOOL variable name.
 */ 
#define SIAssertTrue(exp) SIAssertTrueM(exp, @"SIAssertTrue(" #exp ") Expecting '" #exp "' to be YES, but it was NO.")

/**
 Fail if the passed query does not find a UIView.
 */
#define SIAssertViewPresent(query) SIAssertViewPresentM(query, @"SIAssertViewPresent(" #query ") Expected '" query "' to find a UIView.")

/**
 Fail if the passed query finds a UIView.
 */
#define SIAssertViewNotPresent(query) SIAssertViewNotPresentM(query, @"SIAssertViewNotPresent(" #query ") Expected '" query "' to not find a UIView.")

/**
 Fail if the passed BOOL variable is YES.
 
 @param exp an expression that is expected to resolve to a BOOL value. The expression can just be a simple BOOL variable name.
 */ 
#define SIAssertFalse(exp) SIAssertFalseM(exp, @"SIAssertFalse(" #exp ") Expecting '" #exp "' to be NO, but it was YES.")

/*
 Fails if the two values are not equal. This works for all primitive numbers.
 
 @param x the first value to compare.
 @parma y the second value to compare.
 */
#define SIAssertEquals(x, y) SIAssertEqualsM(x, y, @"SIAssertEquals(" #x ", " #y ") failed: " #x @" != " #y)

/*
 Fails if the label does not have the specified text. Label can be either a UILabel pointer or a dNodi query that will return a label.
 
 @param label a dNodi query that will return a UILabel or a reference to a UILabel.
 @parma expectedText the text we expect the label to be displaying.
 */
#define SIAssertLabelTextEquals(label, expectedText) SIAssertLabelTextEqualsM(label, expectedText, @"SIAssertLabelTextEquals(" #label ", " #expectedText ") failed: label text does equal '" expectedText "'")

/*
 Fails if the two objects are not equal. This basically calls the Object:isEquals: method on x giving y as a parameter.
 
 @param x the first object to compare.
 @parma y the second value to compare.
 */
#define SIAssertObjectEquals(x, y) \
   do { \
      id xValue = (x) == nil ? @"nil" : (x); \
      id yValue = (y) == nil ? @"nil" : (y); \
      SIAssertObjectEqualsM(x, y, @"SIAssertObjectEquals(%s, %s) failed: %@ != %@", #x, #y, xValue, yValue); \
   } while (NO)

/*
 Same as above assertions but have extra parameters which are passed to NSString:stringWithFormat:
 */

#pragma mark - Main assertions
/// @name Main assertions

#define SIFailM(msgTemplate, ...) SIThrowException(ASSERTION_EXCEPTION_NAME, msgTemplate, ## __VA_ARGS__)

#define SIAssertNotNilM(obj, msgtemplate, ...) \
   if (obj == nil) { \
      SIThrowException(ASSERTION_EXCEPTION_NAME, msgtemplate, ## __VA_ARGS__); \
   }

#define SIAssertNilM(obj, msgTemplate, ...) \
   if (obj != nil) { \
      SIThrowException(ASSERTION_EXCEPTION_NAME, msgTemplate, ## __VA_ARGS__); \
   }

#define SIAssertTrueM(exp, msgTemplate, ...) \
   do { \
      BOOL _exp = exp; \
      if (!_exp) { \
         SIThrowException(ASSERTION_EXCEPTION_NAME, msgTemplate, ## __VA_ARGS__); \
      } \
   } while (NO)

#define SIAssertViewPresentM(query, msgTemplate, ...) \
	do { \
		if (!SIIsViewPresent(query)) { \
			SIThrowException(ASSERTION_EXCEPTION_NAME, msgTemplate, ## __VA_ARGS__); \
		} \
	} while (NO)

#define SIAssertViewNotPresentM(query, msgTemplate, ...) \
	do { \
		if (SIIsViewPresent(query)) { \
			SIThrowException(ASSERTION_EXCEPTION_NAME, msgTemplate, ## __VA_ARGS__); \
		} \
	} while (NO)

#define SIAssertFalseM(exp, msgTemplate, ...) \
   do { \
      BOOL _exp = exp; \
      if (_exp) { \
         SIThrowException(ASSERTION_EXCEPTION_NAME, msgTemplate, ## __VA_ARGS__); \
      } \
   } while (NO)

#define SIAssertEqualsM(x, y, msgTemplate, ...) \
   SIAssertTrueM((x) == (y), msgTemplate, ## __VA_ARGS__);

// Compares if at least one is an object. Otherwise both are nil and that is ok too.
#define SIAssertObjectEqualsM(x, y, msgTemplate, ...) \
   if ((x) != nil || (y) != nil) { \
		SIAssertTrueM([(id)(x) isEqual:(id)(y)], msgTemplate, ## __VA_ARGS__); \
   } 

#define SIAssertLabelTextEqualsM(label, expectedText, msgTemplate, ...) \
	do { \
		UILabel *theLabel = nil; \
		if ([label isKindOfClass:[NSString class]]) { \
			theLabel = (UILabel *)SIFindView((NSString *) label); \
		} else { \
			theLabel = (UILabel *) label; \
		} \
		NSString *labelText = theLabel.text; \
		SIAssertObjectEqualsM(labelText, expectedText, msgTemplate, ## __VA_ARGS__); \
	} while (NO)

