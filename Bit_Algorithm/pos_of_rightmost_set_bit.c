#include <stdio.h>
#include <stdlib.h>

#define INT_SIZE    32
int
position_of_rightmost_set_bit (int n)
{

    int pos = 0;
    int i   = 0;

    if (n == 0) {
    
        return 0;
    }

    pos = 1;
    for (i = 0; i < INT_SIZE; i++) {
    
        if (!(n & (1 << i))) {
            
            pos++;
        } else {
        
            break;
        }
    }

    return pos;

}

int
main ()
{

    int n = 0;

    n = 0;

    printf ("The position of rightmost set bit is %d in %d\n", 
            position_of_rightmost_set_bit (n), n);

    return 0;

}
