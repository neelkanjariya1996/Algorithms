#include <stdio.h>
#include <stdlib.h>

int
turnoff_bit (int n, int k)
{

    if (k <= 0) {
    
        return n;
    }
    return (n & ~(1 << (k - 1)));

}

int
main ()
{

    int n = 0;
    int k = 0;

    n = 15;
    k = 4;

    printf ("After turning off %d bit in %d, we get %d\n",
            k, n, turnoff_bit (n, k));

    return 0;

}
