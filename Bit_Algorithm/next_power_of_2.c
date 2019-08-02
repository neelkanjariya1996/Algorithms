#include <stdio.h>
#include <stdlib.h>

unsigned int 
next_pwer_of_2 (unsigned int n)
{
    
    if (n && !(n & (n - 1))) {
    
        return n;
    }

    unsigned int p = 0;

    p = 1;
    while (p < n) {
    
        p = p << 1;
    }

    return p;

}

int
main ()
{

    unsigned int n  = 0;

    n = 0;

    printf ("The next power of %u is %u\n", n, next_pwer_of_2 (n));

    return 0;

}
