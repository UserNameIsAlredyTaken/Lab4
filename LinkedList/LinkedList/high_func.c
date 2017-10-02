#include "stdafx.h"
#include <stdlib.h>
#include "listH.h"

void foreach(const struct linked_list* list, void(*func)(int)){
	struct linked_list_node* the_node = list->the_first;
	func(the_node->value);
	for (int i = 0; i<list->length - 1; i++) {
		the_node = the_node->next;
		func(the_node->value);
	}
}

struct linked_list map(const struct linked_list* old_list, int(*func)(int)){
	struct linked_list* new_list = list_create();
	struct linked_list_node* old_node = old_list->the_first;
	list_add_back(func(old_node->value), &new_list);
	for (int i = 0; i<old_list->length - 1; i++) {
		old_node = old_node->next;
		list_add_back(func(old_node->value), &new_list);
	}
	return *new_list;
}

struct linked_list map_mut(struct linked_list* list, int(*func)(int)){
	struct linked_list_node* the_node = list->the_first;
	the_node->value = func(the_node->value);
	for (int i = 0; i<list->length - 1; i++) {
		the_node = the_node->next;
		the_node->value = func(the_node->value);
	}
	return *list;
}

int foldl(int acc, const struct linked_list* list, int(*func)(int, int)){
	struct linked_list_node* the_node = list->the_first;
	acc = func(the_node->value, acc);
	for (int i = 0; i<list->length - 1; i++) {
		the_node = the_node->next;
		acc = func(the_node->value, acc);
	}
	return acc;
}

struct linked_list* iterate(const int initial, const int length, int(*func)(int)){
	struct linked_list* new_list = list_create();
	int s = initial;
	list_add_back(s, &new_list);
	for (int i = 0; i < length - 1; i++) {
		s = func(s);
		list_add_back(s, &new_list);
	}
	return new_list;
}