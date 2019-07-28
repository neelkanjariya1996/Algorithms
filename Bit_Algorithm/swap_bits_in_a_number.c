#include <stdio.h>
#include <stdlib.h>

int
swap_bits (int x, int p1, int p2, int n)
{

    unsigned int set1   = 0;
    unsigned int set2   = 0;
    unsigned int xor    = 0;
    unsigned int result = 0;

    set1 = (x >> p1) & ((1U << n) - 1);
    set2 = (x >> p2) & ((1u << n) - 1);

    xor = set1 ^ set2;

    xor = (xor << p1) | (xor << p2);

    result = x ^ xor;

    return result;

}

int
main ()
{

    int x   = 0;
    int p1  = 0;
    int p2  = 0;
    int n   = 0;

    x   = 47;
    p1  = 1;
    p2  = 5;
    n   = 3;

    printf ("After swapping the bits, the number becomes: %d\n", swap_bits (x, p1, p2, n));

    return 0;

}
