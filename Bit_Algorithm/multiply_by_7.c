#include <stdio.h>
#include <stdlib.h>

int
multiply_by_7 (int n)
{

    return ((n << 3) - n);

}

int
main ()
{

    int n = 0;

    n = 0;

    printf ("%d multiplied by 7 gives %d\n", n, multiply_by_7 (n));

    return 0;

}
