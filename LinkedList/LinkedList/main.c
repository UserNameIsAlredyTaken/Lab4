#include "stdafx.h"
#include <malloc.h>
#include "listH.h"
#include "funcH.h"
#include "limits.h"

void foreach_spaces(const int value){
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

int main() {
	struct linked_list* the_list = list_create();
	int input=0;
	printf("Enter the array\n");
	char c = ' ';
	while (c != '\n') {
		scanf_s("%d%c", &input, &c);
		list_add_front(input, &the_list);
	}
	printf("The summ is: %d\n", list_sum(*the_list));	

	foreach(the_list, foreach_spaces);
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

	list_free(*the_list);
}
