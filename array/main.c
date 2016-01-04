#include "arrayUtil.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
	ArrayUtil a = create(sizeof(int), 3);
	int *arr = (int *)a.base;
	arr[0] = 6;
	arr[1] = 9;
	arr[2] = 4;
	int x = 4;
	int index = findIndex(a, &x);
	printf("%d\n", index);
	return 0;
}