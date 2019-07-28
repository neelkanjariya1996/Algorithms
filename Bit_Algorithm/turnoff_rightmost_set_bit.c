#include <stdio.h>
#include <stdlib.h>

int
turnoff_rightmost_set_bit (int x)
{

    return (x & (x - 1));

}

int
main ()
{

    int x = 0;

    x = 102;
    printf ("Result = %d\n", turnoff_rightmost_set_bit (x));

    return 0;

}
