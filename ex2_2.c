#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define MAX 5

void double_array(int * arr);

int main (void){
	int array[MAX];
	srand((int)time(0));
	
	for (int i = 0; i < MAX; i++) {
		array[i] = rand() % 100;
		/*	NOT ASKED BY ASSIGNMENT	*/
		printf("The original value inside array is: %d \n", array[i]);
	}

	printf("The adress of array is: %p \n", array);
	printf("The first value is: %d \n", array[0]);
	printf("The size of an integer in bytes: %d \n", sizeof(int));
	printf("The size of array in bytes : %d \n", sizeof(array));

	double_array(array);

	return EXIT_SUCCESS;
}

void double_array(int * begin) {
	for (int* p = begin; p != begin + MAX; p++) {
		*p = (*p) * 2;
		printf("The Doubled value is: %d \n", *p);
	}
}


