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
binomial_coefficient (int n, int k)
{

    int **dp;
    int i   = 0;
    int j   = 0;

    dp  = malloc ((n + 1) * sizeof (int *));
    for (i = 0; i < (n + 1); i++) {
    
        dp[i]   = malloc ((k + 1) * sizeof (int));
    }

    for (i = 0; i < (n + 1); i++) {
    
        for (j = 0; j < (k + 1); j++) {
        
            dp[i][j]    = 0;
        }
    } 

    for (i = 0; i < (n + 1); i++) {
    
        for (j = 0; j <= (min (i, k)); j++) {
        
            if (j == 0 || j == i) {
            
                dp[i][j]    = 1;
            } else {

                dp[i][j]    = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
    }

    return dp[n][k];

}

int
main ()
{

    int n   = 0;
    int k   = 0;

    n   = 5;
    k   = 2;

    printf ("The binomial coffecient of (%d, %d) is: %d\n", n, k, binomial_coefficient (n, k));

    return 0;

}
