#include <stdio.h>
#include <stdlib.h>

int
modulus_divison (int n, int d)
{

    return (n & (d - 1));

}

int
main ()
{

    int n = 0;
    int d = 0;

    n = 9;
    d = 4;

    printf ("%d mod %d = %d\n", n, d, modulus_divison (n, d));

    return 0;

}
