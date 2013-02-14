#import "KIFTestScenario+UpcaseTest.h"
#import "KIFTestStep.h"

@implementation KIFTestScenario (UpcaseTest)
+(id)scenarioToUpcaseText {
  KIFTestScenario *scenario = [KIFTestScenario scenarioWithDescription:@"Test that a user can upcase text."];
  [scenario addStep:[KIFTestStep stepToEnterText:@"lower" intoViewWithAccessibilityLabel:@"inputField"]];
  [scenario addStep:[KIFTestStep stepToTapViewWithAccessibilityLabel:@"uppercaseButton"]];
  
  // Verify that the login succeeded
  [scenario addStep:[KIFTestStep stepToWaitForViewWithAccessibilityLabel:@"outputLabel" value:@"LOWER" traits:UIAccessibilityTraitUpdatesFrequently]];

  return scenario;
}
@end
