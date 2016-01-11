#include "arrayUtil.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


void test_create_array(){
	ArrayUtil a = create(sizeof(int), 4);
	assert(a.length == 4);
	assert(a.type_size == 4);
	free(a.base);
}

void test_resize_array(){
	ArrayUtil a = create(sizeof(int), 4);
	a = resize(a, 2);
	assert(a.length == 2);
	free(a.base);
};

void test_array_are_not_equal(){
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

void test_diffrent_test_length_array_are_not_equal(){
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
void test_array_are_equal() {
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

void test_int_array_are_equal() {
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

void test_int_array_are_not_equal() {
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

void test_find_index_of_gives_index(){
	ArrayUtil a = create(sizeof(int), 3);
	int * first = (int *)a.base;
	first[0] = 45;
	first[1] = 98;
	first[2] = 29;
	int x = 29;

	int index = findIndex(a, &x);

	assert(index == 2);
}

void test_find_index_of_gives_index_minus1_if_element_not_present(){
	ArrayUtil a = create(sizeof(int), 3);
	int * first = (int *)a.base;
	first[0] = 45;
	first[1] = 98;
	first[2] = 29;
	int x = 56;

	int index = findIndex(a, &x);

	assert(index == -1);
}
void test_find_index_of_gives_index_for_char_array(){
	ArrayUtil a = create(sizeof(char), 3);
	char * first = (char *)a.base;
	first[0] = 'a';
	first[1] = 'b';
	first[2] = 'b';
	char x = 'b';

	int index = findIndex(a, &x);

	assert(index == 1);
}

void test_find_index_of_gives_index_for_double_array(){
	ArrayUtil a = create(sizeof(double), 3);
	double * first = (double *)a.base;
	first[0] = 345.565;
	first[1] = 345.566;
	first[2] = 345.567;
	double x = 345.566;

	int index = findIndex(a, &x);

	assert(index == 1);
};

void test_find_index_of_gives_index_for_unsigned_char_array(){
	ArrayUtil a = create(sizeof(unsigned char), 3);
	unsigned char * first = (unsigned char *)a.base;
	first[0] = 'a';
	first[1] = 'v';
	first[2] = 'n';
	unsigned char x = 'n';

	int index = findIndex(a, &x);

	assert(index == 2);
};
int isLessThan_for_test(void* hint, void* item) {
	int *h = (int*)hint;
	int *i = (int *)item;

	if(*h > *i)
		return 1;
	return 0;
}
void test_findFirst_can_find(){
	ArrayUtil a = create(sizeof(int), 3);
	int *first = (int*)a.base;

	first[0] = 23;
	first[1] = 24;
	first[2] = 13;

	int hint = 20;
	MatchFunc *func = &isLessThan_for_test;
	int *foundValue = findFirst(a, func, &hint);

	assert(*foundValue == 13);
}

void test_findFirst_gives_NULL_if_not_find(){
	ArrayUtil a = create(sizeof(int), 3);
	int *first = (int*)a.base;

	first[0] = 23;
	first[1] = 24;
	first[2] = 23;

	int hint = 20;
	MatchFunc *func = &isLessThan_for_test;
	int *foundValue = findFirst(a, func, &hint);

	assert(foundValue == NULL);
}

void test_findLast_gives_last_match_value(){
	ArrayUtil a = create(sizeof(int), 3);
	int *first = (int*)a.base;

	first[0] = 23;
	first[1] = 24;
	first[2] = 39;

	int hint = 30;
	MatchFunc *func = &isLessThan_for_test;
	int *foundValue = findLast(a, func, &hint);
	assert(*foundValue == 24);
}
void test_count_gives_number_of_match_element(){
	ArrayUtil a = create(sizeof(int), 3);
	int *first = (int*)a.base;

	first[0] = 23;
	first[1] = 19;
	first[2] = 23;

	int hint = 20;
	MatchFunc *func = &isLessThan_for_test;
	int foundValue = count(a, func, &hint);

	assert(foundValue == 1);
};

void test_filter_gives_match_elements(){
	ArrayUtil a = create(sizeof(int), 3);
	int *first = (int*)a.base;

	ArrayUtil b = create(sizeof(int), 5);
	first[0] = 2147;
	first[1] = 19;
	first[2] = 23;

	int hint = 21;

	MatchFunc *func = &isLessThan_for_test;
	int foundValue = filter(a, func, &hint, &b.base, b.length);
	int *destination=(int *)b.base;
	assert(destination[0] == 19);
	assert(foundValue == 1);
};

int isSame(void* hint, void* item) {
	char *h = (char *)hint;
	char *itm = (char *)item;
	if(*h == *itm)
		return 1;
	return 0;
}
int isDivisible(void *hint, void *item){
  int *hint_ = (int *)hint;  
  int *item_ = (int *)item;
  if(*item_ == 0) return 0;
  return (*item_ % *hint_ == 0);   
};  

void test_filter(){
	ArrayUtil a = create(sizeof(int), 7);
	int *initial = (int *)a.base;

	ArrayUtil b = create(sizeof(void *), 5);

	initial[0] = 5;
	initial[1] = 5;
	initial[2] = 50;
	initial[3] = 5;
	initial[4] = 5;
	initial[5] = 5;
	// initial[6] = 5;

	int hint = 5;

	MatchFunc *func = &isSame;
	// void **lala = &b.base;
	int foundValue = filter(a, func, &hint, b.base, b.length);
	int **destination = (int **)b.base;
	assert(*destination[0] == 5);
	assert(*destination[1] == 5);
	assert(*destination[2] == 5);
	assert(*destination[3] == 5);
	assert(*destination[4] == 5);
	// assert(destination[5] == 5);
	assert(foundValue == 5);

};
void test_filter_can_gives_char_match_elements (){
	ArrayUtil a = create(sizeof(char), 3);
	char *first = (char*)a.base;

	ArrayUtil b = create(sizeof(char), 5);
	first[0] = 'd';
	first[1] = 'B';
	first[2] = 'B';

	char hint = 'B';

	MatchFunc *func = &isSame;
	int foundValue = filter(a, func, &hint, &b.base, b.length);
	char *destination=(char *)b.base;
	assert(destination[0] == 'B');
	assert(destination[1] == 'B');
	assert(foundValue == 2);
};


void increament_one(void* hint, void * sourceItm, void * destinationItm){
	int source = *(int *)(sourceItm);
	int * dest = (int *)destinationItm;
	*dest = source + 3;
}
void test_map(){
	ArrayUtil a = create(sizeof(int), 3);
	int *first = (int*)a.base;

	ArrayUtil b = create(sizeof(int), 5);

	first[0] = 12;
	first[1] = 12;
	first[2] = 8;

	int hint = 3;

	ConvertFunc *func = &increament_one;
	map(a, b, func, &hint);
	int *destination=(int *)b.base;
	assert(destination[0] == 15);
}
void * sum(void *hint, void *initial, void *number){
	int *num1 = (int *)initial;
	int *num2 = (int *)number;
	*num1 += *num2;
	return num1;
}
void test_reduce(){
	ArrayUtil a = create(sizeof(int), 3);
	int *first = (int*)a.base;

	ArrayUtil b = create(sizeof(int), 5);

	first[0] = 12;
	first[1] = 14;
	first[2] = 8;

	int hint = 3;
	int initial = 0;
	ReducerFunc *func = &sum;
	int ans = *(int *)reduce(a, func, &hint, &initial);
	assert(ans == 34);
}
// int main(int argc, char const *argv[]) {
	// test_create_array();
	// test_resize_array();
	// test_array_are_not_equal();
	// test_diffrent_length_array_are_not_equal();
	// test_array_are_equal();
	// test_int_array_are_equal();
	// test_find_index_of_gives_index();
	// test_find_index_of_gives_index_for_char_array();
	// test_find_index_of_gives_index_minus1_if_element_not_present();
	// test_find_index_of_gives_index_for_double_array();
	// test_find_index_of_gives_index_for_unsigned_char_array();
	// test_findFirst_can_find();
	// test_findFirst_gives_NULL_if_not_find();
	// test_count_gives_number_of_match_element();
	// test_filter_gives_match_elements();
	// test_filter_can_gives_char_match_elements();
	// test_findLast_gives_last_match_value();
	// test_filter_can_gives_char_match_elements();
	// test_filter();
	// test_reduce();
	// return 0;
// }