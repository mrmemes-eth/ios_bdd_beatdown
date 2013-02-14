#import "KIFTestStep+VerifyText.h"
#import "UIAccessibilityElement-KIFAdditions.h"
#import "UIApplication-KIFAdditions.h"

@implementation KIFTestStep (VerifyText)

+(id)stepToVerifyUILabelText:(NSString *)text forElementWithAccessibilityLabel:(NSString *)accessibilityLabel {
  return [KIFTestStep stepWithDescription:[NSString stringWithFormat:@"Match string \"%@\" against view with accessibility label \"%@\"", text, accessibilityLabel] executionBlock:^(KIFTestStep *step, NSError **error) {

    UIAccessibilityElement *element = [[UIApplication sharedApplication] accessibilityElementWithLabel:accessibilityLabel accessibilityValue:nil traits:UIAccessibilityTraitNone];
    
    if (!element) {
      return KIFTestStepResultWait;
    }
    
    UILabel *label = (UILabel*)[UIAccessibilityElement viewContainingAccessibilityElement:element];
    KIFTestCondition([text isEqualToString:[label text]], error, @"Text doesn't match.");
    
    return KIFTestStepResultSuccess;
  }];
}

@end
