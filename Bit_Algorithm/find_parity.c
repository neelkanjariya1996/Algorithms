#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool
parity_check (unsigned int n)
{
    
    bool parity = 0;

    while (n) {
    
        parity  = !parity;
        n       = n & (n - 1);
    }

    return parity;

}

int
main ()
{

    unsigned int n = 0;

    n = 31;

    if (parity_check (n)) {
    
        printf ("Odd Parity\n");
    } else {
    
        printf ("Even Parity\n");
    }

    return 0;

}
