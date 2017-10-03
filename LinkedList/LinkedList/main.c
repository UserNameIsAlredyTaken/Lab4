#include "stdafx.h"
#include <malloc.h>
#include "limits.h"
#include <stdbool.h>
#include "listH.h"
#include "funcH.h"

void foreach_spaces(const int value) {
	printf("%d ", value);
}
void foreach_new_line(const int value) {
	printf("%d\n", value);
}

int map_square(const int value){
	return value*value;
}

int map_cube(const int value) {
	return value*value*value;
}

int foldel_sum(int acc, int const value){
	acc = acc + value;
	return acc;
}

int foldel_min(int min, int const value){
	if (value < min) { min = value;}
	return min;
}

int foldel_max(int max, int const value) {
	if (value > max) { max = value; }
	return max;
}

int map_mut_abs(int value){
	if (value < 0) { return -value;}
	return value;
}

int iterate_double(int value){
	return value * 2;
}

bool serialize(const struct linked_list* list, const char* filename){
	FILE *f = fopen(filename, "wb");
	if (f == NULL) {
		return false;
	}
	struct linked_list_node* the_node = list->the_first;
	for (int i = 0; i<list->length - 1; i++) {
		the_node = the_node->next;
		fwrite(&(the_node->value), sizeof(int), 1, f);
	}
	fclose(f);
	return true;
}

bool deserialize(struct linked_list** list, const char* filename) {
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


int main() {
	struct linked_list* the_list = list_create();
	int input=0;
	printf("Enter the array\n");
	char c = ' ';
	while (c != '\n') {
		scanf("%d%c", &input, &c);
		list_add_front(input, &the_list);
	}
	/*printf("The summ is: %d\n", list_sum(*the_list));	

	/*foreach(the_list, foreach_spaces);
	printf("\n");
	foreach(the_list, foreach_new_line);
	printf("\n");

	struct linked_list cheking_map_list = map(the_list,map_square);
	foreach(&cheking_map_list, foreach_spaces);
	cheking_map_list = map(the_list, map_cube);
	foreach(&cheking_map_list, foreach_spaces);

	int acc = foldl(0, the_list, foldel_sum);
	printf("The summ is: %d\n", acc);
	printf("\n");

	int min = foldl(INT_MAX, the_list, foldel_min);
	printf("The min is: %d\n", min);
	printf("\n");

	int max = foldl(INT_MIN, the_list, foldel_max);
	printf("The max is: %d\n", max);
	printf("\n");

	map_mut(the_list, map_mut_abs);
	foreach(the_list, foreach_spaces);
	printf("\n");

	struct linked_list* cheking_iterate_list = iterate(1,10,iterate_double);
	foreach(cheking_iterate_list, foreach_spaces);

	save(the_list,"t.txt");
	
	bool isOk = load(&the_list, "input.txt");	
	foreach(the_list, foreach_spaces);*/

	deserialize(&the_list,"serializableFile.txt");
	foreach(the_list, foreach_spaces);

	list_free(*the_list);
}
