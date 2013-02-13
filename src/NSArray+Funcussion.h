#import <Foundation/Foundation.h>

typedef void (^VoidArrayIteratorBlock)(id obj);
typedef BOOL (^BoolArrayIteratorBlock)(id obj);
typedef id (^ObjectArrayIteratorBlock)(id obj);
typedef id (^ObjectArrayAccumulatorBlock)(id acc, id obj);

@interface NSArray (Funcussion)

-(void)each:(VoidArrayIteratorBlock)aBlock;
-(NSArray*)map:(ObjectArrayIteratorBlock)aBlock;
-(NSArray*)filter:(BoolArrayIteratorBlock)aBlock;
-(id)reduceWithAccumulator:(id)accumulator andBlock:(ObjectArrayAccumulatorBlock)aBlock;

@end
