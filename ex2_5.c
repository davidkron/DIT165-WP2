#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 100
#define MAXNUMBER 20

void create_random(int *tab);
void count_frequency(int *tab, int *freq);
void draw_histogram(int *freq);

int main ( void)
{
	int table[MAX];
	int frequency[MAXNUMBER];

	/* INIT RANDOM TABLE */
	printf("\n\t - NUMBERS -\n\n");
    create_random(table);

	/* INIT FREQUANCY ARRAY */
    for(int j= 0; j <MAXNUMBER; j++){
         frequency[j] = 0;
    }

	/* COUNT FREQUENCY OF RANDOM NUMBERS */
	count_frequency(table, frequency);

	/* DRAW FREQUENCY */
	printf("\n\t - FREQUENCY -\n\n");
    draw_histogram(frequency);
}


void create_random(int* table) {
	srand((int)time(0));

	for (int i = 0; i < MAX; i++){
		int ran = rand() % MAXNUMBER;
		table[i] = ran;
		printf("%d", table[i]);
	}

	printf("\n");
}

void count_frequency(int* array, int* frequency)
{
	for (int i = 0; i< MAX; i++){
		frequency[array[i]] ++;
	}
}

void draw_histogram(int* frequency) {
	for (int i = 0; i < MAXNUMBER; i++) {
		if (frequency[i] != 0) {
			printf("\t%d\t", i);
			for (int j = 0; j < frequency[i]; j++) {
				printf("x");
			}
			printf("%s", "\n");
		}
	}
}