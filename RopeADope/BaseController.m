#import "BaseController.h"
#import "BaseView.h"

@implementation BaseController

-(id)init {
  if (self = [super init]) {
    [self.view addSubview:self.baseview];
  }
  return self;
}

-(BaseView*)baseview {
  if (!_baseview) {
    _baseview = [[BaseView alloc] init];
  }
  return _baseview;
}

-(void)emitUppercasedInput {
  [self.baseview.inputField.text uppercaseString];
}

@end