#include "stdafx.h"
#include <malloc.h>


struct linked_list_node {
	int value;
	struct linked_list_node* next;
};
struct linked_list{
	int length;
	struct linked_list_node* the_first;
	struct linked_list_node* the_last;
};

void list_add_front(const int value, struct linked_list** list) {
	struct linked_list_node* another_node = (struct linked_list_node*)malloc(sizeof(struct linked_list_node));
	another_node->next = (*list)->the_first;
	(*list)->the_first = another_node;
	(*list)->length++;
	another_node->value = value;
}

void list_add_back(const int value, struct linked_list** list){
	struct linked_list_node* another_node = (struct linked_list_node*)malloc(sizeof(struct linked_list_node));
	((*list)->the_last)->next = another_node;
	another_node->next = 0;
	(*list)->length++;
	another_node->value = value;
}

struct linked_list* list_create(/*const int value*/){
	struct linked_list* new_list = (struct linked_list*)malloc(sizeof(struct linked_list));
	new_list->length = 0;
	new_list->the_first = NULL;
	new_list->the_last = NULL;
	//list_add_front(value, &new_list);
	return new_list;
}

int list_get(const int index, const struct linked_list list){
	if(list.length<=index){
		return 0;
	}
	struct linked_list_node* the_node = list.the_first;
	for (int i = 0; i<index;i++) {
		the_node = the_node->next;
	}
	return the_node->value;
}

void list_free(const struct linked_list list){
	struct linked_list_node* the_next_node = list.the_first;
	for (int i = 0; i<=list.length-1; i++) {
		struct linked_list_node* the_previous_node = the_next_node;
		the_next_node = the_next_node->next;
		free(the_previous_node);
	}
}

int list_length(const struct linked_list list){
	return list.length;
}

struct linked_list_node* list_node_at(const int index, const struct linked_list list) {
	if (list.length <= index) {
		return NULL;
	}
	struct linked_list_node* the_node = list.the_first;
	for (int i = 0; i<index; i++) {
		the_node = the_node->next;
	}
	return the_node;
}

int list_sum(const struct linked_list list){
	struct linked_list_node* the_node = list.the_first;
	int sum = the_node->value;
	for (int i = 0; i<list.length-1; i++) {
		the_node = the_node->next;
		sum += the_node->value;
	}
	return sum;
}

void foreach(struct linked_list* list, void (*func)(int)){
	struct linked_list_node* the_node = list->the_first;
	func(the_node->value);
	for(int i =0; i<list->length-1; i++)	{
		the_node = the_node->next;
		func(the_node->value);
	}
}

struct linked_list map(struct linked_list* old_list, int (*func)(int)){
	struct linked_list* new_list = list_create();
	struct linked_list_node* old_node = old_list->the_first;
	list_add_back(func(old_node->value), &new_list);
	for (int i = 0; i<old_list->length - 1; i++) {
		old_node = old_node->next;
		list_add_back(func(old_node->value), &new_list);
	}
	return *new_list;
}

struct linked_list map_mut(struct linked_list* list, int (*func)(int)){
	struct linked_list_node* the_node = list->the_first;
	the_node->value = func(the_node->value);
	for(int i =0; i<list->length-1; i++){
		the_node = the_node->next;
		the_node->value = func(the_node->value);
	}
	return *list;
}

int foldl(int acc, struct linked_list* list, int (*func)(int, int)) {
	struct linked_list_node* the_node = list->the_first;
	acc = func(the_node->value, acc);
	for (int i = 0; i<list->length - 1; i++) {
		the_node = the_node->next;
		acc = func(the_node->value, acc);
	}
	return acc;
}



int main() {
	struct linked_list* the_list = list_create();
	int input=0;
	printf("Enter the array\n"); //input finishes with Cntrl+D
	while(scanf_s("%d", &input)!=0){
		list_add_front(input, &the_list);
	}
	printf("The summ is: %d\n", list_sum(*the_list));	
	list_free(*the_list);
}
