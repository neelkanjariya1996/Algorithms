#include <stdio.h>
#include <stdlib.h>

int
is_power_of_2 (unsigned int n)
{

    return (n && (!(n & (n - 1))));

}

int
pos_of_set_bit (unsigned int n)
{

    if (!(is_power_of_2 (n))) {
    
        return -1;
    }

    unsigned int i  = 0;
    int pos         = 0;

    i   = 1;
    pos = 1;

    while (!(i & n)) {
    
        i = i << 1;
        pos++;
    }

    return pos;

}

int
main ()
{

    int n = 0;
    
    n = 10;

    printf ("The position of only set bit in %d is %d\n", 
            n, pos_of_set_bit (n));

    return 0;

}
