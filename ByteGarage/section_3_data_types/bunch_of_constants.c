#include <stdio.h>
#include <stdlib.h>

int main()
{
    int moonLand = 1969;
    float speedOfLight = 299792458;
    float pi = 3.142;
    unsigned int hexaDead = 0xDEAD;
    unsigned int hexaSecret = 51966;

    printf("moonLand %10d, \n", moonLand);
    printf("moonLand %010d, \n", moonLand);

    printf("speedOfLight %.0f, \n", speedOfLight);
    printf("speedOfLight %.3e, \n", speedOfLight);

    printf("pi %.2f, \n", pi);
    printf("pi %+.1f, \n", pi);

    printf("hexaDead 0x%X, \n", hexaDead);
    printf("hexaDead %6d, \n", hexaDead);

    printf("hexaSecret %x, \n", hexaSecret);
    return 0;
}