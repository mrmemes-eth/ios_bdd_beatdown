#import "NSArray+Funcussion.h"

@implementation NSArray (Funcussion)

-(void)each:(VoidArrayIteratorBlock)aBlock {
  [self enumerateObjectsUsingBlock:^(id object, NSUInteger idx, BOOL *stop) {
    aBlock(object);
  }];
}

-(NSArray*)map:(ObjectArrayIteratorBlock)aBlock {
  NSMutableArray *result = [NSMutableArray array];
  [self each:^(id object) {
    [result addObject:aBlock(object)];
  }];
  return result;
}

-(NSArray*)filter:(BoolArrayIteratorBlock)aBlock {
  NSMutableArray *result = [NSMutableArray array];
  [self each:^(id object) {
    if (aBlock(object)) [result addObject: object];
  }];
  return result;
}

-(id)reduceWithAccumulator:(id)accumulator andBlock:(ObjectArrayAccumulatorBlock)aBlock {
  __block id outerAccumulator = accumulator;
  [self each:^(id obj) {
    outerAccumulator = aBlock(outerAccumulator,obj);
  }];
  return outerAccumulator;
}

@end