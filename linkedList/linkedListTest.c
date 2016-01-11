#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
#include <assert.h>
void test_add_to_list_add_to_last(void){
	LinkedList list = create();
	int x = 3;
	int y = 5;
	add_to_list(&list, &x);
	Element *a = (Element *)list.head;
	int *e = a -> value;
	assert(*e == 3);
	add_to_list(&list, &y);
	Element *second = (Element *)list.tail;
	int *value = second -> value;
	assert(*value == 5);
};

void test_get_first_element(void) {
	LinkedList list = create();
	int x = 3;
	int y = 5;
	add_to_list(&list, &x);
	add_to_list(&list, &y);
	Element *ele = get_first_element(list);
	int *value = ele -> value;
	assert(*value == 3);
};

void test_get_last_element(void) {
	LinkedList list = create();
	int x = 3;
	int y = 5;
	add_to_list(&list, &x);
	add_to_list(&list, &y);
	Element *ele = get_last_element(list);
	int *value = ele -> value;
	assert(*value == 5);
};