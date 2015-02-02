#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int initQue (int list [MAX] ){
    for (int i =0 ; i < MAX; i++){
        list[i] = -1;
    }
}
int input (int list [] , int number){
    for(int i = 0 ; i < MAX; i++){
        if( list[i] == -1){
            list [i] = number;
            return EXIT_SUCCESS;
        }
    }
	return EXIT_FAILURE;
}
void pop(int queue []){
    for(int i = 0 ; i < MAX -1; i++){
		if (queue[i] != -1) {
			queue[i] = queue[i + 1];
		}
    }
	queue[MAX-1] = -1;
}

void print_func(int list []){
    for( int i = 0; i < MAX ; i++){
        printf("%d ", list[i]);
	}
    printf("%s", "\n");
}


int main(){
	int queue[MAX];
	
	initQue(queue);
	printf("INIT QUEUE:\n");
    print_func(queue);

	printf("FILLING IN ORDER:\n");
	for (int i = 1;; i++) {
		if (input(queue, i) == EXIT_FAILURE) {
			printf("Whoops full! Stopping...\n");
			break;
		}
		print_func(queue);
	}

	printf("EMPTIYNG:\n");
	for (int i = 0; i < MAX; i++) {
		pop(queue);
		print_func(queue);
	}
}

