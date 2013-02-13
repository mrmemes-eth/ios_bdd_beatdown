#import "AppDelegate.h"
#import "BaseController.h"

@implementation AppDelegate

-(BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
  [self setWindow:[[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]]];
  [self.window setBackgroundColor:[UIColor whiteColor]];
  [self.window setRootViewController:[[BaseController alloc] init]];
  [self.window makeKeyAndVisible];
  return YES;
}

@end
