#include "stdio.h"
void main(int argc, char const *argv[])
{
    int year, leap;
    scanf("%d", &year);
    if (year%4 == 0 && year != 0)
    {
        leap = 1;
    }
    else if (year %400 == 0)
    {
        leap = 1;
    }
    else   leap = 0;
    if (leap == 1)
    {
        printf("%d", year);

    }
    else
        printf("%d", year);
    
}
