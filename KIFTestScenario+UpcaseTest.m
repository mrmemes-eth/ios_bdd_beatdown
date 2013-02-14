#import "KIFTestScenario+UpcaseTest.h"
#import "KIFTestStep.h"
#import "KIFTestStep+VerifyText.h"

@implementation KIFTestScenario (UpcaseTest)
+(id)scenarioToUpcaseText {
  KIFTestScenario *scenario = [KIFTestScenario scenarioWithDescription:@"Test that a user can upcase text."];
  [scenario addStep:[KIFTestStep stepToEnterText:@"lower" intoViewWithAccessibilityLabel:@"inputField"]];
  [scenario addStep:[KIFTestStep stepToTapViewWithAccessibilityLabel:@"uppercaseButton"]];
  [scenario addStep:[KIFTestStep stepToVerifyUILabelText:@"LOWER" forElementWithAccessibilityLabel:@"outputLabel"]];
  return scenario;
}
@end
