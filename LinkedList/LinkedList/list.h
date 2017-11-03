#pragma once
#ifndef LIST_H
#define LIST_H
struct linked_list_node {
	int value;
	struct linked_list_node* next;
};
struct a
{
	int a;
	int b;
	struct private * ptr;
};
struct linked_list;
void list_add_front(const int value, struct linked_list** list);
void list_add_back(const int value, struct linked_list** list);
struct linked_list* list_create();
int list_get(const int index, const struct linked_list list);
void list_free(const struct linked_list list);
int list_length(const struct linked_list list);
struct linked_list_node* list_node_at(const int index, const struct linked_list list);
int list_sum(const struct linked_list list);
#endif
