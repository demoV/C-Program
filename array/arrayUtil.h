#include <stdlib.h>

typedef struct {
	void * base;
	int length;
	int type_size; 
} ArrayUtil;

typedef int (MatchFunc)(void*, void*);


ArrayUtil create(int, int);
int areEqual(ArrayUtil, ArrayUtil); 
ArrayUtil resize(ArrayUtil, int); 
void dispose(ArrayUtil);
void* findFirst(ArrayUtil, MatchFunc *, void*);
void* findLast(ArrayUtil, MatchFunc *, void*);
int findIndex(ArrayUtil, void*);