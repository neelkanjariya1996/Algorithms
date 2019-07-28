#include <stdio.h>
#include <stdlib.h>

int
is_power_of_4 (int x)
{

    if (x == 0) {
    
        return 0;
    }

    while (x != 1) {
    
        if ((x % 4) != 0) {
        
            return 0;
        }

        x = x / 4;
    }

    return 1;

}

int
main ()
{

    int x = 0;

    x = 1024;
    if (is_power_of_4 (x)) {
    
        printf ("%d is a power of 4\n", x);
    } else {
    
        printf ("%d is not a power of 4\n", x);
    }

    return 0;

}
