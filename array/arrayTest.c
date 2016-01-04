#include "arrayUtil.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


void create_array(){
	ArrayUtil a = create(sizeof(int), 4);
	assert(a.length == 4);
	assert(a.type_size == 4);
	free(a.base);
}

void resize_array(){
	ArrayUtil a = create(sizeof(int), 4);
	a = resize(a, 2);
	assert(a.length == 2);
	free(a.base);
};

void array_are_not_equal(){
	ArrayUtil a = create(sizeof(char), 2);
	char * first = (char *)a.base;
	ArrayUtil b = create(sizeof(char), 2);
	char * second = (char *)b.base;
	first[0] = 'A';
	first[1] = 'B';

	second[0] = 'A';
	second[1] = 'C';

	int res = areEqual(a,b);

	assert(res == 0);
	free(a.base);
	free(b.base);
};

void diffrent_length_array_are_not_equal(){
	ArrayUtil a = create(sizeof(char), 3);
	char * first = (char *)a.base;
	ArrayUtil b = create(sizeof(char), 2);
	char * second = (char *)b.base;
	first[0] = 'A';
	first[1] = 'B';
	first[2] = 'C';

	second[0] = 'A';
	second[1] = 'C';

	int res = areEqual(a,b);

	assert(res == 0);
	free(a.base);
	free(b.base);
};
void array_are_equal() {
	ArrayUtil a = create(sizeof(char), 3);
	char * first = (char *)a.base;
	ArrayUtil b = create(sizeof(char), 3);
	char * second = (char *)b.base;
	first[0] = 'A';
	first[1] = 'B';
	first[2] = 'C';

	second[0] = 'A';
	second[1] = 'B';
	second[2] = 'C';

	int res = areEqual(a,b);

	assert(res == 1);
	free(a.base);
	free(b.base);
};

void int_array_are_equal() {
	ArrayUtil a = create(sizeof(int), 3);
	int * first = (int *)a.base;
	ArrayUtil b = create(sizeof(int), 3);
	int * second = (int *)b.base;
	first[0] = 45;
	first[1] = 46;
	first[2] = 29;

	second[0] = 45;
	second[1] = 46;
	second[2] = 29;

	int res = areEqual(a,b);

	assert(res == 1);
	free(a.base);
	free(b.base);
};

void int_array_are_not_equal() {
	ArrayUtil a = create(sizeof(int), 3);
	int * first = (int *)a.base;
	ArrayUtil b = create(sizeof(int), 3);
	int * second = (int *)b.base;
	first[0] = 45;
	first[1] = 98;
	first[2] = 29;

	second[0] = 45;
	second[1] = 46;
	second[2] = 29;

	int res = areEqual(a,b);

	assert(res == 0);
	free(a.base);
	free(b.base);
};

void find_index_of_gives_index(){
	ArrayUtil a = create(sizeof(int), 3);
	int * first = (int *)a.base;
	first[0] = 45;
	first[1] = 98;
	first[2] = 29;
	int x = 29;

	int index = findIndex(a, &x);

	assert(index == 2);
}

void find_index_of_gives_index_minus1_if_element_not_present(){
	ArrayUtil a = create(sizeof(int), 3);
	int * first = (int *)a.base;
	first[0] = 45;
	first[1] = 98;
	first[2] = 29;
	int x = 56;

	int index = findIndex(a, &x);

	assert(index == -1);
}
void find_index_of_gives_index_for_char_array(){
	ArrayUtil a = create(sizeof(char), 3);
	char * first = (char *)a.base;
	first[0] = 'a';
	first[1] = 'b';
	first[2] = 'b';
	char x = 'b';

	int index = findIndex(a, &x);

	assert(index == 1);
}

void find_index_of_gives_index_for_double_array(){
	ArrayUtil a = create(sizeof(double), 3);
	double * first = (double *)a.base;
	first[0] = 345.565;
	first[1] = 345.566;
	first[2] = 345.567;
	double x = 345.566;

	int index = findIndex(a, &x);

	assert(index == 1);
};

void find_index_of_gives_index_for_unsigned_char_array(){
	ArrayUtil a = create(sizeof(unsigned char), 3);
	unsigned char * first = (unsigned char *)a.base;
	first[0] = 'a';
	first[1] = 'v';
	first[2] = 'n';
	unsigned char x = 'n';

	int index = findIndex(a, &x);

	assert(index == 2);
};

int main(int argc, char const *argv[]) {
	create_array();
	resize_array();
	array_are_not_equal();
	diffrent_length_array_are_not_equal();
	array_are_equal();
	int_array_are_equal();
	find_index_of_gives_index();
	find_index_of_gives_index_for_char_array();
	find_index_of_gives_index_minus1_if_element_not_present();
	find_index_of_gives_index_for_double_array();
	find_index_of_gives_index_for_unsigned_char_array();
	return 0;
}