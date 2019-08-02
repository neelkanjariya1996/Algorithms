#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool
is_kth_bit_set (unsigned int n, unsigned int k)
{

    if (n & (1 << (k - 1))) {
    
        return true;
    }

    return false;

}

bool
is_palindrome (unsigned int x)
{

    int l = 0;
    int r = 0;

    l = 1;
    r = sizeof (unsigned int) * 8;

    while (l < r) {
    
        if (is_kth_bit_set (x, l) != (is_kth_bit_set (x, r))) {
        
            return false;
        }

        l++;
        r--;
    }

    return true;

}

int 
main ()
{

    unsigned int n = 0;

    n = (1 << 15) + (1 << 16);

    if (is_palindrome (n)) {
    
        printf ("%d is a palindrome in binary representation\n", n);
    } else {
    
        printf ("%d is not a palindrome in binary representation\n", n);
    }

    return 0;

}
