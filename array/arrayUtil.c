#include "arrayUtil.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ArrayUtil create(int sizeType, int length) {
	
	void * base_address = calloc(length, sizeType);
	ArrayUtil array;
	array.base = base_address;
	array.type_size = sizeType;
	array.length = length;
	return array;
};

ArrayUtil resize(ArrayUtil a, int length) {
	a.base = realloc(a.base, length * a.type_size);
	a.length = length;
	return a;
};

int areEqual(ArrayUtil a, ArrayUtil b) {
	int diff = memcmp(a.base, b.base, a.length * a.type_size);
	if(a.length != b.length || diff != 0)
		return 0;
	return 1;
};

void dispose(ArrayUtil util) {
	free(util.base);
};

int findIndex(ArrayUtil util, void* element) {
	int one_element_size = util.type_size;
	void * base = util.base;
	for (int i = 0; i < util.length; ++i){
		int r = memcmp(base, element, one_element_size);
		if(r == 0)
			return i;
		base = base + (one_element_size);
	}
	return -1;
}; 

void* findFirst(ArrayUtil util, MatchFunc* match, void* hint) {
	void *base = util.base;
	for (int i = 0; i < util.length; ++i){
		if(match(hint, base))
			return base;
		base = base + util.type_size;
	}
	return NULL;
};

void* findLast(ArrayUtil util, MatchFunc* match, void* hint) {
	void *base = util.base + (util.length * util.type_size);
	for (int i = 0; i < util.length; ++i){
		base = base - util.type_size;
		if(match(hint, base))
			return base;
	}
	return NULL;
};
int count(ArrayUtil util, MatchFunc* match, void* hint) {
	int counter = 0;
	void *base = util.base;
	for (int i = 0; i < util.length; ++i){
		if(match(hint, base))
			counter ++;
		base = base + util.type_size;
	}
	return counter;
};


int filter(ArrayUtil util, MatchFunc* match, void* hint, void** destination, int maxItems ){
	void * base = util.base;
	int length = 0;
	for (int i = 0; i < util.length; ++i){
		if(match(hint, base) && maxItems > length){
			destination[length++] = base;
		}
		base = base + util.type_size;
	}
	return length;
};

void map(ArrayUtil source, ArrayUtil destination, ConvertFunc* convert, void* hint) {
	void * base = source.base;
	void * destBase = destination.base;
	int length = 0;
	for (int i = 0; i < source.length; ++i){
		convert(hint, base, destBase);
		base = base + source.type_size;
		destBase = destBase + destination.type_size;
	}
};

void forEach(ArrayUtil util, OperationFunc* operation, void* hint) {
	void * base = util.base;
	for (int i = 0; i < util.length; ++i){
		operation(hint, base);
		base = base + util.type_size;
	}
};
void* reduce(ArrayUtil util, ReducerFunc* reducer, void* hint, void* intialValue){
	void * base = util.base;
	for (int i = 0; i < util.length; ++i){
		reducer(hint, intialValue, base);
		base = base + util.type_size;
	}	
	return intialValue;
};
