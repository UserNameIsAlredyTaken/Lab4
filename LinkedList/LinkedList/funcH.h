#pragma once

void foreach(struct linked_list* list, void(*func)(int));
struct linked_list map(struct linked_list* old_list, int(*func)(int));
struct linked_list map_mut(struct linked_list* list, int(*func)(int));
int foldl(int acc, struct linked_list* list, int(*func)(int, int));
struct linked_list* iterate(const int initial, const int length, int(*func)(int));
bool save(struct linked_list* list, const char* filename);
bool load(struct linked_list* list, const char* filename);