#import "AppDelegate.h"
#import "BaseController.h"

#if RUN_KIF_TESTS
#import "UpcaseTestController.h"
#endif

@implementation AppDelegate

-(BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
  [self setWindow:[[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]]];
  [self.window setBackgroundColor:[UIColor whiteColor]];
  [self.window setRootViewController:[[BaseController alloc] init]];
  [self.window makeKeyAndVisible];

#if RUN_KIF_TESTS
  [[UpcaseTestController sharedInstance] startTestingWithCompletionBlock:^{
    // Exit after the tests complete so that CI knows we're done
    exit([[UpcaseTestController sharedInstance] failureCount]);
  }];
#endif

  return YES;
}

@end
