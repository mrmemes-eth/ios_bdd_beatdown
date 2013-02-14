#import "UpcaseTestController.h"
#import "KIFTestScenario+UpcaseTest.h"

@implementation UpcaseTestController
-(void)initializeScenarios {
  [self addScenario:[KIFTestScenario scenarioToUpcaseText]];
}
@end
