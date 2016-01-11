#include <stdlib.h>
#include "linkedList.h"

LinkedList create(void) {
	LinkedList new_link;
	new_link.head = NULL;
	new_link.tail = NULL;
	new_link.length = 0;
	return new_link;
};

int add_to_list(LinkedList *list, void *value) {
	Element *ele = (Element *)malloc(sizeof(Element));
	ele -> value = value;
	ele -> next = NULL;
	if(list -> length == 0) {
		list -> head = list -> tail = ele;
	}
	else {
		list -> tail -> next = ele;
		list -> tail = ele;
	}
	list -> length ++;
	return list -> length;
};

void *get_first_element(LinkedList list) {
	return list.head;
};
void *get_last_element(LinkedList list) {
	return list.tail;
};