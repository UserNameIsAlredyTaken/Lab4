#include "stdafx.h"
#include <malloc.h>
#include "listH.h"


int main() {
	struct linked_list* the_list = list_create();
	int input=0;
	printf("Enter the array\n"); //input finishes with Cntrl+D	
	char c = ' ';
	while (c != '\n') {
		scanf_s("%d%c", &input, &c);
		list_add_front(input, &the_list);
	}
	printf("The summ is: %d\n", list_sum(*the_list));	
	list_free(*the_list);
}
