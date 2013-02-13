#import "BaseView.h"

static CGFloat kControlWidth = 150;
static CGFloat kControlHeight = 28;

@interface BaseView()
-(void)emitUppercasedInput;
@end

@implementation BaseView

-(id)init {
  if (self = [super init]) {
    [self addGestureRecognizer:self.bgTapRecognizer];
    [self addSubview:self.outputLabel];
    [self addSubview:self.inputField];
    [self addSubview:self.uppercaseButton];
  }
  return self;
}

-(UILabel*)outputLabel {
  if (!_outputLabel) {
    _outputLabel = [[UILabel alloc] init];
    [_outputLabel setTextAlignment:NSTextAlignmentCenter];
    [_outputLabel setNumberOfLines:0];
  }
  return _outputLabel;
}

-(UITextField*)inputField {
  if (!_inputField) {
    _inputField = [[UITextField alloc] init];
    [_inputField setBorderStyle:UITextBorderStyleRoundedRect];
  }
  return _inputField;
}

-(UIButton*)uppercaseButton {
  if (!_uppercaseButton) {
    _uppercaseButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    [_uppercaseButton setTitle:@"uppercase it" forState:UIControlStateNormal];
    [_uppercaseButton addTarget:self
                         action:@selector(emitUppercasedInput)
               forControlEvents:UIControlEventTouchUpInside];
  }
  return _uppercaseButton;
}

-(UITapGestureRecognizer*)bgTapRecognizer {
  if (!_bgTapRecognizer) {
    _bgTapRecognizer = [[UITapGestureRecognizer alloc] initWithTarget:self.inputField
                                                               action:@selector(resignFirstResponder)];
  }
  return _bgTapRecognizer;
}

-(void)emitUppercasedInput {
  [self.outputLabel setText:[self.inputField.text uppercaseString]];
}

-(void)layoutSubviews {
  CGSize superSize  = self.superview.frame.size;
  CGFloat xOffset   = (superSize.width - kControlWidth) / 2;
  CGFloat yOffset   = (superSize.height - kControlHeight) / 3;
  [self.outputLabel setFrame:CGRectMake(0, 0, superSize.width, yOffset)];
  [self.inputField setFrame:CGRectMake(xOffset, yOffset, kControlWidth, kControlHeight)];
  [self.uppercaseButton setFrame:CGRectOffset(self.inputField.frame, 0, kControlHeight * 1.5)];
  [self setFrame:self.superview.bounds];
}

@end
