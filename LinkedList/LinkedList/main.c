#include "stdafx.h"
#include "limits.h"
#include <stdbool.h>
#include "list.h"
#include "func.h"
#include <stdlib.h>

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

int map_mut_abs(const int value){
	if (value < 0) { return -value;}
	return value;
}

int iterate_double(const int value){
	return value * 2;
}

int multiplier(int a, int b){
	return a*b;
}

typedef int(*MyFunc)(int);

struct str {
	int a;
	int(*function)(int, int);
};

int call(struct str* st ,int b){
	int res = st->function(st->a, b);
	return res;
}


struct str* bind_second(int(*func)(int,int),int b){
	struct str* new_str = (struct str*)malloc(sizeof(struct str));
	new_str->a = b;
	new_str->function = *func;
	return new_str;
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
	printf("The summ is: %d\n", list_sum(*the_list));	

	printf("\nCheck \"foreach_spaces\"\n");
	foreach(the_list, foreach_spaces);
	printf("\nCheck \"foreach_new_line\"\n");
	foreach(the_list, foreach_new_line);

	printf("\nCheck \"map_square\"\n");
	struct linked_list cheking_map_list = map(the_list,map_square);
	foreach(&cheking_map_list, foreach_spaces);
	printf("\nCheck \"map_cube\"\n");
	cheking_map_list = map(the_list, map_cube);
	foreach(&cheking_map_list, foreach_spaces);

	printf("\n\nCheck \"foldel_sum\"\n");
	int acc = foldl(0, the_list, foldel_sum);
	printf("The summ is: %d\n", acc);
	printf("\nCheck \"foldel_min\"\n");
	int min = foldl(INT_MAX, the_list, foldel_min);
	printf("The min is: %d\n", min);
	printf("\nCheck \"foldel_max\"\n");
	int max = foldl(INT_MIN, the_list, foldel_max);
	printf("The max is: %d\n", max);

	printf("\nCheck \"map_mut_abs\"\n");
	map_mut(the_list, map_mut_abs);
	foreach(the_list, foreach_spaces);

	printf("\n\nCheck \"iterate_double\"\n");
	struct linked_list* cheking_iterate_list = iterate(1,10,iterate_double);
	foreach(cheking_iterate_list, foreach_spaces);

	printf("\n\nCheck \"save\" and \"load\"\n");
	save(the_list,"t.txt");	
	bool isOk = load(the_list, "t.txt");	
	foreach(the_list, foreach_spaces);

	printf("\n\nCheck \"serialize\" and \"desrialize\"\n");
	struct linked_list* new_list = list_create();
	serialize(the_list, "ser.txt");
	deserialize(&new_list, "ser.txt");
	foreach(new_list, foreach_spaces);	

	list_free(*the_list);
}
