#include <stdio.h>
#include <stdlib.h>

int
count_set_bits (unsigned int n)
{

    int count   = 0;

    while (n > 0) {
    
        n = n & (n - 1);
        count++;
    }

    return count;

}

int
main ()
{

    unsigned int n  = 3;

    printf ("The number of set bits in %u is %d\n", n, count_set_bits (n));

    return 0;

}
