#import <UIKit/UIKit.h>

@interface BaseView : UIView {
  UILabel *_outputLabel;
  UITextField *_inputField;
  UIButton *_uppercaseButton;
  UITapGestureRecognizer *_bgTapRecognizer;
}

-(UILabel*)outputLabel;
-(UITextField*)inputField;
-(UIButton*)uppercaseButton;
-(UITapGestureRecognizer*)bgTapRecognizer;

@end
