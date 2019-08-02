#include <stdio.h>
#include <stdlib.h>



int
is_multiple_of_3 (int num)
{

    int odd_count   = 0;
    int even_count  = 0;

    if (num < 0) {
    
        num = -num;
    }

    if (num == 0) {
    
        return 1;
    }

    if (num == 1) {
    
        return 0;
    }

    while (num) {
    
        if (num & 1) {
        
            odd_count++;
        }

        if (num & 2) {
        
            even_count++;
        }

        num = num >> 2;
    }

    return (is_multiple_of_3 (odd_count - even_count));

}

int
main ()
{

    int n = 0;

    n = 309;

    if (is_multiple_of_3 (n)) {
    
        printf ("%d is a multiple of 3\n", n);
    } else {
    
        printf ("%d is not a multiple of 3\n", n);
    }

    return 0;

}
