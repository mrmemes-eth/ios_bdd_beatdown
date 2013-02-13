#import <SenTestingKit/SenTestingKit.h>
#import "NSDictionary+Funcussion.h"

@interface NSDictionaryFuncussionTest : SenTestCase
@property NSDictionary *simpleDict;
@property NSDictionary *biggerDict;
@end

@implementation NSDictionaryFuncussionTest

@synthesize simpleDict;

-(void)setUp {
  [self setSimpleDict:@{@"one": @1, @"two": @2}];
  [self setBiggerDict:@{@"one": @1, @"two": @2, @"three": @3, @"baz": @"BAZ!!", @"four": @1, @"boz": @[]}];
}

-(void)testMap {
  NSDictionary *mappedDict = [self.simpleDict map:^id(id key, id value) {
    return [NSDictionary dictionaryWithObject:[key stringByAppendingFormat:@":%@",value] forKey:key] ;
  }];
  NSDictionary *comparisonDict = [NSDictionary dictionaryWithObjectsAndKeys:@"one:1",@"one",@"two:2",@"two", nil];
  STAssertEqualObjects(mappedDict, comparisonDict, nil);
}

-(void)testFilter {
  NSDictionary *mappedDict = [self.simpleDict filter:^BOOL(id key, id value) {
    return [key isEqualToString:@"one"];
  }];
  NSDictionary *comparisonDict = @{@"one": @1};
  STAssertEqualObjects(mappedDict, comparisonDict, nil);
}

-(void)testFilterMany {
  NSDictionary *mappedDict = [self.biggerDict filter:^BOOL(id key, id value) {
    return [value isKindOfClass:[NSNumber class]];
  }];
  NSDictionary *comparisonDict = @{@"one": @1, @"two": @2, @"three": @3, @"four": @1};
  STAssertEqualObjects(mappedDict, comparisonDict, nil);
}

-(void)testNumericReduction {
  NSNumber *reduction = [self.simpleDict reduceWithAccumulator:@0 andBlock:^id(id acc, id key, id value) {
    return [NSNumber numberWithInt:([acc intValue] + [value intValue])];
  }];
  STAssertEqualObjects(reduction, @3, nil);
}

-(void)testStringReduction {
  NSNumber *reduction = [self.simpleDict reduceWithAccumulator:@"" andBlock:^id(id acc, id key, id value) {
    return [acc stringByAppendingFormat:@"%@:%@:",key,value];
  }];
  STAssertEqualObjects(reduction, @"one:1:two:2:", nil);
}

@end