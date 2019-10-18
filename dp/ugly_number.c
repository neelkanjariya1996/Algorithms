#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int
min (int a, int b)
{

    return ((a < b) ? a : b);

}

int
ugly_number (int n)
{

    int *dp;
    int next_2              = 0;
    int next_3              = 0;
    int next_5              = 0;
    int i2                  = 0;
    int i3                  = 0;
    int i5                  = 0;
    int i                   = 0;
    int next_ugly_number    = 0;

    if (n < 0) {
    
        return INT_MAX;
    }

    dp  = malloc (n * sizeof (int));
    memset (dp, 0, (n * sizeof (int)));

    dp[0]   = 1;

    next_2  = 2;
    next_3  = 3;
    next_5  = 5;
    
    for (i = 1; i < n; i++) {
    
        next_ugly_number    = min (next_2, min (next_3, next_5));
        dp[i]               = next_ugly_number;

        if (next_ugly_number == next_2) {
        
            i2      = i2 + 1;
            next_2  = dp[i2] * 2;
        }

        if (next_ugly_number == next_3) {
        
            i3      = i3 + 1;
            next_3  = dp[i3] * 3;
        }

        if (next_ugly_number == next_5) {
        
            i5      = i5 + 1;
            next_5  = dp[i5] * 5;
        }
    }

    return next_ugly_number;

}

int
main ()
{

    int n   = 0;
    
    n   = 150;

    printf ("The %dth ugly number is: %d\n", n, ugly_number (n));

    return 0;

}
