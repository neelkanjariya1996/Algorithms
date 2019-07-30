#include <stdio.h>
#include <stdlib.h>

#define INT_BITS    32

int
left_rotate (int n, int d)
{

    return ((n << d) | (n >> (INT_BITS - d)));

}

int
right_rotate (int n, int d)
{

    return ((n >> d) | (n << (INT_BITS - d)));

}

int
main ()
{

    int n   = 0;
    int d   = 0;

    n = 16;
    d = 2;

    printf ("%d << %d = %d\n", n, d, left_rotate (n, d));
    printf ("%d >> %d = %d\n", n, d, right_rotate (n, d));

    return 0;

}
