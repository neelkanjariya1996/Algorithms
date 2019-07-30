#include <stdio.h>
#include <stdlib.h>

#define CHAR_BITS   8

int
min (int x, int y)
{

    return (y + ((x- y) & ((x - y) >> (sizeof (int) * CHAR_BITS - 1))));

}

int
max (int x, int y)
{

    return (x - ((x - y) & ((x - y) >> (sizeof (int) * CHAR_BITS - 1))));

}

int
main ()
{

    int x = 0;
    int y = 0;

    x = 9;
    y = 5;

    printf ("Minimum of %d and %d is %d\n", x, y, min (x, y));
    
    printf ("Maximum of %d and %d is %d\n", x, y, max (x, y));

    return 0;

}
