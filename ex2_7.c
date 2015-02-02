#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int days_per_month[12] = { 31,28,31,30,31,30,
							31,31,30,31,30,31 };

int addintsplit(int n);
void readPersnr(char* personumber);
void validatePersonalNumber(const char* persnr);
int controlDigit(const char* persnr);

/*
			----------------------------------------------------------
			-----------------------    MAIN    -----------------------
			----------------------------------------------------------
*/

int main(){
	printf("\t ~~ SWEDISH PERSONAL NUMBER VALIDATOR ~~ \n\n");
    char personumber [11] = "-";
	while (*personumber != 'q'){
		readPersnr(personumber);
		validatePersonalNumber(personumber);
	}

	return EXIT_SUCCESS;
}

/*
			---------------------------------------------------------
			----------------	READ PERSONAL NUMBER ----------------
			---------------------------------------------------------
*/

void readPersnr(char* personumber) {
	printf("Please input your personal number:  ");
	scanf("%s", personumber);
}

int addintsplit(int n) {
	if (n > 9) {
		int left = (n / 10);
		int right = n - left * 10;
		return left + right;
	}
	return n;
}

/*
			---------------------------------------------------
			----------------	VALIDATION     ----------------
			---------------------------------------------------
*/

void validatePersonalNumber(const char* persnr) {
	int year, month, day, digits, lastdigit;
	sscanf(persnr, "%2d %2d %2d %3d %d", &year, &month, &day, &digits, &lastdigit);
	if (month < 0 || month > 12) {
		printf("%s\n", "month is incorrect");
	}
	else if (day < 0 || day > days_per_month[month]) {
		printf("%s\n", "day is incorrect");
	}
	else if (lastdigit != controlDigit(persnr)) {
		printf("%s\n", "control digit incorrect");
	}
	else {
		printf("%s\n", "correct");
	}
}

/*
			------------------------------------------------------
			----------------	CONTROL DIGIT     ----------------
			------------------------------------------------------
*/

int controlDigit(const char* persnr) {
	int sum = 0;
	int multiplier = 2;

	for (int i = 0; i < 9; i++) {
		int n = (persnr[i] - '0')*multiplier;
		sum += addintsplit(n);
		if (multiplier == 2)
			multiplier = 1;
		else if (multiplier == 1)
			multiplier = 2;
	}

	int remain;
	if (sum > 9) {
		remain = 10 - (sum - (sum / 10) * 10);
	}
	else {
		remain = 10 - sum;
	}

	if (remain == 10)
		return 0;
	return remain;
}