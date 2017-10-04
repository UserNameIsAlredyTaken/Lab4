#include "stdafx.h"
#include <stdlib.h>
#include "list.h"
#include <stdbool.h>

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

bool save(const struct linked_list* list, const char* filename){
	FILE *f = fopen(filename, "w");
	if(f==NULL){
		return false;
	}
	struct linked_list_node* the_node = list->the_first;
	fprintf(f, "%d ", the_node->value);
	for (int i = 0; i<list->length - 1; i++) {
		the_node = the_node->next;
		fprintf(f, "%d ", the_node->value);
	}
	fclose(f);
	return true;
}

bool load(struct linked_list** list, const char* filename){
	FILE *f = fopen(filename, "r");
	if (f == NULL) {
		return false;
	}
	int input = 0;
	char c = ' ';
	while (fscanf(f, "%d%c", &input, &c)==2){		
		list_add_front(input, list);
	}
	fclose(f);
	return true;
}

bool serialize(const struct linked_list* list, const char* filename){
	FILE *f = fopen(filename, "wb");
	if (f == NULL) {
		return false;
	}
	struct linked_list_node* the_node = list->the_first;
	fwrite(&(the_node->value), sizeof(int), 1, f);
	for (int i = 0; i<(list->length)-1; i++) {
		the_node = the_node->next;
		fwrite(&(the_node->value), sizeof(int), 1, f);
	}
	fclose(f);
	return true;
}

bool deserialize(struct linked_list** list, const char* filename){
	FILE *f = fopen(filename, "rb");
	if (f == NULL) {
		return false;
	}
	int input = 0;
	while (fread(&input, sizeof(int), 1, f) == 1) {
		list_add_front(input, list);
	}
	fclose(f);
	return true;
}
