#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b;
    a = 0;
    b = a++ * 2 + 1;
    printf("after postincrementing:\n");
    printf("a %d\n", a);
    printf("b %d\n", b);


    a = 0;
    b = ++a * 2 + 1;
    printf("after preincrementing:\n");
    printf("a %d\n", a);
    printf("b %d\n", b);

    
}
