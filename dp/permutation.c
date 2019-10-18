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
permutation (int n, int k)
{

    int **dp;
    int p   = 0;
    int i   = 0;
    int j   = 0;

    dp  = malloc ((n + 1) * sizeof (int *));
    for (i = 0; i <= n; i++) {
    
        dp[i]   = malloc ((k + 1) * sizeof (int));
    }

    for (i = 0; i <= n; i++) {
    
        for (j = 0; j <= k; j++) {
        
            dp[i][j]    = 0;
        }
    }

    for (i = 0; i <= n; i++) {
    
        for (j = 0; j <= min (i, k); j++) {
        
            if (j == 0) {
            
                dp[i][j]    = 1;
            } else {
            
                dp[i][j]    = dp[i - 1][j] + (j * dp[i - 1][j - 1]);
            }
        }
    }

    p   = dp[n][k];

    for (i = 0; i <= n; i++) {
    
        free (dp[i]);
    } 
    free (dp);

    return p;

}

int
main ()
{

    int n   = 0;
    int k   = 0;

    n   = 10;
    k   = 2;

    printf ("The permutation of (%d, %d) is: %d\n", n, k, permutation (n, k));

    return 0;

}
