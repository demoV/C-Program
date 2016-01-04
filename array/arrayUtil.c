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





