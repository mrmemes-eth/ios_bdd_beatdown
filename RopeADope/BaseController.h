#import <UIKit/UIKit.h>

@class BaseView;

@interface BaseController : UIViewController {
  BaseView *_baseview;
}

-(BaseView*)baseview;

@end