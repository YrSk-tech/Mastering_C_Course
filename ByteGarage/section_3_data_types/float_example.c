#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    
    double decimalDigits = 1.23456789;
    
    double worldPopulation = 7.801E9;

    double PlancConstant = 6.626E-34;

    printf("%12.1f   | 1 decimal digits \n", decimalDigits);
    printf("%12.3f   | decimal digits \n", decimalDigits);
    printf("%12.1f   | World Population  \n", worldPopulation);
    printf("%12.1e   | World Population scientific 1 digit of precision \n", worldPopulation);
    printf("%12.3e   | World Population scientific 3 digit of precision \n", worldPopulation);
    printf("%12.1E   | PlancConstant scientific 1 digit of precision \n", PlancConstant);
    printf("%12.3E   | PlancConstant scientific 3 digit of precision \n", PlancConstant);


	return 0;
}