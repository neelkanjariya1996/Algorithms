#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int
add_overflow (int *result, int a, int b)
{

    *result = a + b;

    if ((a > 0) && (b > 0) && (*result < 0)) {
    
        return -1;
    } 

    if ((a < 0) && (b < 0) && (*result > 0)) {
    
        return -1;
    }

    return 0;

}

int
main ()
{

    int a       = 0;
    int b       = 0;
    int result  = 0;

    a = 2147483640;
    b = 10;

    printf ("%d \n", add_overflow (&result, a, b));

    printf ("%d \n", result);

    return 0;

}
