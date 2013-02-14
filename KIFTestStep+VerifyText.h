#import "KIFTestStep.h"

@interface KIFTestStep (VerifyText)

+(id)stepToVerifyUILabelText:(NSString *)text forElementWithAccessibilityLabel:(NSString *)accessibilityLabel;

@end
