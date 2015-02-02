#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define UINT unsigned int

int stringcompare(const char* str1, const char* str2){
	UINT size1 = strlen(str1);
	UINT size2 = strlen(str2);

    if(size1 == size2) // If their lenght is equal
    {
        for(UINT i =0; i< size1; i++) // loop thru
        {
            if(str1[i] != str2[i]) // is they are not equals
            {
                return EXIT_FAILURE; // not continue.
            }
        }
		//We havent returned yet -> Success
        return EXIT_SUCCESS;
    }
	else 
		return EXIT_FAILURE;
}

int main(int argc, char *argv[])
{
	if (argc != 3) {
		printf("You need to supply two words as arguments");
		return EXIT_FAILURE;
	}

	int failed = 0;

	if (stringcompare(argv[1], argv[2]) == 0)
		printf("custom compare succeeded\n");
	else {
		printf("custom compare failed\n");
		failed = 1;
	}

	if (strcmp(argv[1], argv[2]) == 0)
		printf("strcmp succeeded\n");
	else {
		printf("strcmp failed\n");
		failed = 1;
	}

    return failed;
}







