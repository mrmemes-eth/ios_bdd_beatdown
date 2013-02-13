#import "NSDictionary+Funcussion.h"

@implementation NSDictionary (Funcussion)

-(void)each:(VoidDictIteratorBlock)aBlock {
  [self enumerateKeysAndObjectsUsingBlock:^(id key, id obj, BOOL *stop) {
    aBlock(key,obj);
  }];
}

-(NSDictionary*)map:(DictionaryDictIteratorBlock)aBlock {
  NSMutableDictionary *result = [NSMutableDictionary dictionary];
  [self each:^(id key, id value) {
    [result addEntriesFromDictionary:aBlock(key,value)];
  }];
  return result;
}

-(NSDictionary*)filter:(BoolDictIteratorBlock)aBlock {
  NSMutableDictionary *result = [NSMutableDictionary dictionary];
  [self each:^(id key, id value) {
    if (aBlock(key,value)) [result setObject:value forKey:key];
  }];
  return result;
}

-(id)reduceWithAccumulator:(id)accumulator andBlock:(ObjectAcumulatorDictBlock)aBlock {
  __block id outerAccumulator = accumulator;
  [self each:^(id key, id value) {
    outerAccumulator = aBlock(outerAccumulator, key, value);
  }];
  return outerAccumulator;
}

@end