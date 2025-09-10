#include <stdio.h>
#include <stdbool.h>   
#include <math.h> 

void showbits( unsigned int x )
{
    int i=0;
    for (i = (sizeof(int) * 8) - 1; i >= 0; i--)
    {
       putchar(x & (1u << i) ? '1' : '0');

    }
    printf("\n");
}

int main( void )
{
    int j = 5225;
    printf("%d in binary \t\t ", j);
    showbits(j);

    /* the loop for right shift operation */
    for (int m = 0; m <= 5; m++)
    {
        int n = j >> m;
        printf("%d right shift %d gives ", j, m);
        showbits(n);
    }

    double a, b;
    bool compare;
    double epsilon = 0.000001; // Define a small tolerance value

    // Check if the absolute difference is within the tolerance
    compare = (fabs(a - b) < epsilon) ? 0 : 1;
    printf("%d",compare);
    return 0;
}