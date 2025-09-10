#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    
    char letter = 'A';

    printf("char letter ascii number %d\n", letter);
    printf("char letter %c\n", letter);

    letter = 135;

    printf("asigned number to letter %c\n", letter);

    printf("Input new letter:\n");
    letter = getchar(); 
    printf("Your letter: %c\n",letter);    
    letter = getchar(); 
    printf("Your letter: %c\n",letter);
    letter = getchar();
    printf("Your letter: %c\n",letter);


	return 0;
}