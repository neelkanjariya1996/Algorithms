#include <stdio.h>
#include <stdlib.h>

int
multiply (int x)
{

    return ((x << 1) + x + (x >> 1));

}

int
main ()
{

    int x   = 0;

    x = 2;

    printf ("%d * 3.5 = %d\n", x, multiply(x));

    return 0;

}
