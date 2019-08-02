#include <stdio.h>
#include <stdlib.h>

int
swap_bits (int n)
{

    unsigned int even_bits  = 0;
    unsigned int odd_bits   = 0;

    even_bits   = n & 0xAAAAAAAA;
    odd_bits    = n & 0x55555555;

    even_bits   = even_bits >> 1;
    odd_bits    = odd_bits << 1;

    return (even_bits | odd_bits);

}

int
main ()
{

    int n   = 0;

    n = 23;

    printf ("After swapping the even and odd bits of %d, we get %d \n", 
            n, swap_bits (n));

    return 0;

}
