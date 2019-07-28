#include <stdio.h>
#include <stdlib.h>

#define CHAR_BITS   8

int
min (int x, int y)
{

    return (y + ((x - y) & ((x - y) >> (sizeof (int) * CHAR_BITS - 1))));

}

int
min_of_three (int x, int y, int z)
{

    return (min (x, min (y, z)));

}

int
max (int x, int y)
{

    return (x - ((x - y) & (x - y) >> (sizeof (int) * CHAR_BITS - 1)));

}

int
max_of_three (int x, int y, int z)
{

    return (max (x, max (y, z)));

}

int
main ()
{

    int x = 0;
    int y = 0;
    int z = 0;

    x = 9;
    y = 2;
    z = 20;

    printf ("The minimum of 3 numbers %d, %d and %d is : %d\n", x, y, z, min_of_three (x, y, z));
    printf ("The maximum of 3 numbers %d, %d and %d is : %d\n", x, y, z, max_of_three (x, y, z));

    return 0;

}
