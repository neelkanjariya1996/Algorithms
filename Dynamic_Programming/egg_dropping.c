#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int
max (int a, int b)
{

    return ((a > b) ? a : b);

}


/*
 * n: number of eggs
 * k: number of floors
 */
int
egg_drop (int n, int k)
{

    int **dp;
    int min = 0;
    int res = 0;
    int i   = 0;
    int j   = 0;
    int x   = 0;

    dp  = malloc ((n + 1) * sizeof (int *));
    for (i = 0; i < (n + 1); i++) {
    
        dp[i]   = malloc ((k + 1) * sizeof (int));
    }

    for (i = 0; i < (n + 1); i++) {
    
        for (j = 0; j < (k + 1); j++) {
        
            dp[i][j]    = INT_MAX;
        }
    }

    for (i = 1; i <= n; i++) {
    
        dp[i][0]    = 0;
        dp[i][1]    = 1;
    }

    for (j = 1; j <= k; j++) {
    
        dp[1][j]    = j;
    }

    for (i = 2; i <= n; i++) {
    
        for (j = 2; j <= k; j++) {

            for (x = 1; x <= j; x++) {
            
                res = 1 + max (dp[i - 1][x - 1], dp[i][j - x]);
                if (res < dp[i][j]) {
                
                    dp[i][j]    = res;
                }
            }
        }
    }

    min = dp[n][k];

    for (i = 0; i <= n; i++) {
    
        free (dp[i]);
    }
    free (dp);

    return min;

}

int
main ()
{

    int n   = 0;
    int k   = 0;

    n   = 2;
    k   = 36;
    printf ("The minimum number of trials required is: %d\n", egg_drop (n, k));

    return 0;

}
