#include <stdio.h>
#include <stdlib.h>

void
bin (unsigned int n)
{

    if (n > 1) {
    
        bin (n / 2);
    }

    printf ("%d ", (n % 2));

}

int
main ()
{

    unsigned int n   = 0;

    n = 15;

    printf ("The binary representation of %d is: ", n);
    bin (n);
    printf ("\n");

    return 0;

}
