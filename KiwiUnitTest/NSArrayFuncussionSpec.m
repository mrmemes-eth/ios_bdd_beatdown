#import "Kiwi.h"
#import "NSArray+Funcussion.h"

SPEC_BEGIN(NSArrayFuncussion)

__block NSArray *simpleArray;
__block NSArray *nestedArray;

beforeEach(^{
  simpleArray = @[@"one",@"two"];
  nestedArray = @[@"microphone",@"check",simpleArray,simpleArray];
});

afterEach(^{
  simpleArray = nil;
  nestedArray = nil;
});

describe(@"each:", ^{
  __block NSUInteger count;
  __block NSMutableString *accumulator;
  
  beforeEach(^{
    count = 0;
    accumulator = [NSMutableString string];
    [simpleArray each:^(id obj) {
      count += 1;
      [accumulator appendString:obj];
    }];
  });
  
  it(@"iterates the correct number of times", ^{
    [[theValue(count) should] equal:theValue(2)];
  });
  
  it(@"yields consecutive objects to the block", ^{
    [[accumulator should] equal:@"onetwo"];
  });
});

describe(@"map:", ^{
  it(@"returns a new array with the function applied to each element", ^{
    NSArray *mappedArray = [simpleArray map:^id(id obj) {
      return [obj uppercaseString];
    }];
    [[mappedArray should] equal:@[@"ONE",@"TWO"]];
  });
});

describe(@"filter:", ^{
  it(@"returns only elements the block evaluates to YES for", ^{
    NSArray *filteredArray = [simpleArray filter:^BOOL(id obj) {
      return [obj isEqualToString:@"two"];
    }];
    [[filteredArray should] equal:@[@"two"]];
  });
  it(@"returns an empty array in case of no evaluations to YES", ^{
    [[[simpleArray filter:^BOOL(id obj) { return NO; }] should] equal:@[]];
  });
});

describe(@"reduceWithAccumulator:andBlock:", ^{
  it(@"handles numeric reduction", ^{
    NSArray *array = @[@1,@2,@3,@4,@5];
    NSNumber *reduction = [array reduceWithAccumulator:@0 andBlock:^id(id acc, id obj) {
      return [NSNumber numberWithInt:[acc intValue] + [obj intValue]];
    }];
    [[reduction should] equal:@15];
  });
  it(@"handles string reduction", ^{
    NSArray *array = @[@"chupa",@"cabra",@"nibre"];
    NSNumber *reduction = [array reduceWithAccumulator:@"el" andBlock:^id(id acc, id obj) {
      return [acc stringByAppendingFormat:@", %@",obj];
    }];
    [[reduction should] equal:@"el, chupa, cabra, nibre"];
  });
});

SPEC_END