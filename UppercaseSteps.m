#import <Foundation/Foundation.h>
#import <Simon/Simon.h>

@interface UppercaseSteps : NSObject; @end

@implementation UppercaseSteps

//SIMapStepToSelector(@"Given I enter \"(.*)\" into the \"(.*)\" input field", enterText:intoViewWithQuery:);
SIMapStepToSelector(@"Given I enter \"(.*)\" into the \"(.*)\" input field", foobly);
-(void)foobly {
  NSLog(@"Foobly");
}

SIMapStepToSelector(@"When I touch the \"(.*)\" button", clickAButtonCalled:)
-(void)clickAButtonCalled:(NSString *)buttonName {
  SITapButtonWithLabel(buttonName);
}

SIMapStepToSelector(@"Then I should see \"(.*)\"", viewWithText:)
-(void)viewWithText:(NSString*)text {
  NSString *query = [NSString stringWithFormat:@"//label[@text='%@'",text];
  SIFindView(query);
}

@end