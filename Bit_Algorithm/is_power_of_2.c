#include <stdio.h>
#include <stdlib.h>

int
is_power_of_2 (int n)
{

    return (n && (!(n & (n - 1))));

}

int
main ()
{

    int n = 0;

    n = 9;

    if (is_power_of_2 (n)) {

        printf ("%d is power of 2\n", n);
    } else {
    
        printf ("%d is not a power of 2\n", n);
    }

    return 0;

}
