#include <stdlib.h>

typedef struct {
	void * base;
	int length;
	int type_size; 
} ArrayUtil;

ArrayUtil create(int, int);
int areEqual(ArrayUtil, ArrayUtil); 
ArrayUtil resize(ArrayUtil, int); 
void dispose(ArrayUtil);
// void ex(ArrayUtil);
int findIndex(ArrayUtil, void*);