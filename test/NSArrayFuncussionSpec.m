#import "Specta.h"

#define EXP_SHORTHAND

#import "Expecta.h"
#import "NSArray+Funcussion.h"

SpecBegin(NSArrayFuncussionSpec)

  __block NSArray *simpleArray;
  __block NSArray *nestedArray;

  before(^{
    simpleArray = @[@"one",@"two"];
    nestedArray = @[@"microphone", @"check", simpleArray, simpleArray];
  });

  after(^{
    simpleArray = nil;
    nestedArray = nil;
  });

  describe(@"each:", ^{
    __block NSUInteger count = 0;
    __block NSMutableString *accumulator = [NSMutableString string];
    
    it(@"iterates the correct number of times", ^{
      [simpleArray each:^(id obj) { count += 1; }];
      expect([simpleArray count]).to.equal(count);
    });
    it(@"yields consecutive objects to the block", ^{
      [simpleArray each:^(id obj) { [accumulator appendString:obj]; }];
      expect(accumulator).to.equal(@"onetwo");
    });
  });
SpecEnd