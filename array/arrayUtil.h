#include <stdlib.h>

typedef struct {
	void * base;
	int length;
	int type_size; 
} ArrayUtil;

typedef int (MatchFunc)(void*, void*);
typedef void (ConvertFunc)(void*, void*, void*);
typedef void (OperationFunc)(void*, void*);
typedef void* (ReducerFunc)(void*, void*, void*);

ArrayUtil create(int, int);
int areEqual(ArrayUtil, ArrayUtil); 
ArrayUtil resize(ArrayUtil, int); 
void dispose(ArrayUtil);
int count(ArrayUtil, MatchFunc*, void*);

int filter(ArrayUtil, MatchFunc*, void*, void**, int);
void map(ArrayUtil, ArrayUtil, ConvertFunc*, void*);
void* reduce(ArrayUtil, ReducerFunc*, void*, void*);

void forEach(ArrayUtil, OperationFunc*, void*);
void* findFirst(ArrayUtil, MatchFunc *, void*);
void* findLast(ArrayUtil, MatchFunc *, void*);
int findIndex(ArrayUtil, void*);