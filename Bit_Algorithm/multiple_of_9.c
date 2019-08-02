#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool
is_multiple_of_9 (int n)
{

    if ((n == 0) || (n == 9)) {
    
        return true;
    }

    if (n < 9) {
    
        return false;
    }

    return is_multiple_of_9((n >> 3) - (n & 7));

}

int
main ()
{

    int n = 0;

    n = 901;

    if (is_multiple_of_9 (n)) {
    
        printf ("%d is a multiple of 9\n", n);
    } else {
    
        printf ("%d is not a multiple of 9\n", n);
    }

    return 0;

}
