#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 20

void copystring(char* to, char * from);

int main(void){
	/*   BUFFERS   */
    char buff1[MAX];
	char buff2[MAX];
	char buff3[MAX];

    fgets(buff1, MAX, stdin);		// Input >> Buff

	strcpy(buff2, buff1);			// Buff >> Buff2

	copystring(buff3, buff2);		//Buff2 >> Buff3

	/*   PRINT     */
	printf("BUFFER1: %s", buff1);
	printf("BUFFER2: %s", buff2);
	printf("BUFFER3: %s", buff3);

	return EXIT_SUCCESS;
}

void copystring (char* to, char * from){
    int i= 0;
	
    for (;from[i] != '\0'; i++ )	//Copy each char except ending
        to[i] = from[i];
	
	to[i] = '\0';					// Insert ending
}
