#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int palindromecheck(const char* str1)
{
    int length = strlen(str1);

    for(int i =0; i< length; i++)
    {
        if(str1[i] != str1[length -1 - i])
        {
            printf("%c is not equal to %c\n",str1[i],str1[length - 1- i]);
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}
int main()
{
	char str1[255];
	printf("Enter a palindrome:\n");
	scanf("%s", str1);

    if(palindromecheck(str1) == 0)
    {
        printf("Correct!\n");
	}
	else {
		printf("Nope :(\n");
	}

	system("PAUSE");

    return EXIT_SUCCESS;
}
