#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void)
{

    unsigned students = 25U;
    unsigned long long worldPopulation = 78621235945ULL;

	printf("%12u | students in the class \n", students);
    printf("%12llu | World population now \n", worldPopulation);

    uint8_t count = UINT8_MAX;
    printf("%12u | max value of 8 bit int \n", count);

    count = count +1;

    printf("%12u | overflowed value \n", count);

    printf("%12d | INT32_MIN \n",INT32_MIN );
    printf("%12d | INT32_MAX \n",INT32_MAX );
    printf("%12u | UINT32_MAX \n", UINT32_MAX );

	return 0;
}