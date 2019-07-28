#include <stdio.h>
#include <stdlib.h>

#define CHAR_BITS   8

int
computing_absolute (int x)
{

    int mask    = 0;

    mask    = x >> (sizeof (int) * CHAR_BITS - 1);

    return ((mask + x) ^ mask);

}

int
main ()
{

    int x   = 0;

    x = -9;
    printf ("abs(%d) = %d\n", x, computing_absolute (x));

    return 0;

} 
