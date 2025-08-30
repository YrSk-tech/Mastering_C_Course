#include <stdio.h>
#include <stdlib.h>

typedef enum 
{
    TEA_BLACK = 10,  
    COFFE = 22,     
    JUICE = 35,      
    BEER,       
}Menu;

int main (){

    Menu maria = TEA_BLACK;
    Menu andriy = BEER;
    
    printf("maria ordered: %d\n",maria);
    printf("andriy ordered: %d\n", andriy);

    return 0;
}
