#import <SenTestingKit/SenTestingKit.h>
#import "NSArray+Funcussion.h"

@interface NSArrayFuncussionTest : SenTestCase
@property NSArray *simpleArray;
@property NSArray *nestedArray;
@end

@implementation NSArrayFuncussionTest

@synthesize simpleArray, nestedArray;

-(void)setUp {
  [self setSimpleArray:@[@"one",@"two"]];
  [self setNestedArray:@[@"microphone", @"check", self.simpleArray, self.simpleArray]];
}

-(void)tearDown {
  [self setSimpleArray:nil];
  [self setNestedArray:nil];
}

-(void)testEachIteration {
  __block NSUInteger count = 0;
  __block NSMutableString *accumulator = [NSMutableString string];
  [self.simpleArray each:^(id obj) {
    count += 1;
    [accumulator appendString:obj];
  }];
  STAssertEquals([self.simpleArray count], count, nil);
  STAssertEqualObjects(@"onetwo", accumulator, nil);
}

-(void)testMap {
  NSArray *mappedArray = [self.simpleArray map:^id(id obj) {
    return [obj uppercaseString];
  }];
  NSArray *resultArray = @[@"ONE",@"TWO"];
  STAssertEqualObjects(mappedArray, resultArray, nil);
}

-(void)testFilter {
  NSArray *mappedArray = [self.simpleArray filter:^BOOL(id obj) {
    return [obj isEqualToString:@"two"];
  }];
  STAssertEqualObjects(mappedArray, @[@"two"], nil);
}

-(void)testNumericReduction {
  NSArray *array = @[@1,@2,@3,@4,@5];
  NSNumber *reduction = [array reduceWithAccumulator:@0 andBlock:^id(id acc, id obj) {
    return [NSNumber numberWithInt:[acc intValue] + [obj intValue]];
  }];
  STAssertEqualObjects(reduction, [NSNumber numberWithInt:15], nil);
}

-(void)testStringReduction {
  NSArray *array = @[@"chupa", @"cabra", @"nibre"];
  NSString *reduction = [array reduceWithAccumulator:@"el" andBlock:^id(id acc, id obj) {
    return [acc stringByAppendingFormat:@", %@", obj];
  }];
  STAssertEqualObjects(reduction, @"el, chupa, cabra, nibre", nil);
}

@end