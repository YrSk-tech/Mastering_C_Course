#include <stdio.h>
#include <stdlib.h>

typedef enum 
{
    NONE = 0,  
    LOW = 5,     
    MEDIUM = 9,      
    HIGH = 12,
    MAXIMUM = 20,       
}ThrustLevel;

int main (){

    ThrustLevel userSelect;
    while(userSelect != HIGH)
    {
        printf("Select Thrust Level: \t");
        scanf("%d", &userSelect);
        

        switch (userSelect)
        {
        case 0:
            printf("ready to go: \n");
            break;
        case 20:
            printf("take off: \n");
            break;
        case 9:
            printf("entering into ionosphere: \n");
            break;
        case 5:
            printf("traveling to deep space: \n");
            break;
        case HIGH:
            printf("stop the program HIGH \n");
            userSelect = HIGH;
            break;
        default:
            userSelect = HIGH;
            break;
        }

    }

    return 0;
}
