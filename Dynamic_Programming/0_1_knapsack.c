#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int
max (int a, int b)
{

    return ((a > b) ? a : b);

}

int
max_knapsack (int W, int val[], int wt[], int n)
{

    int **dp;
    int m_v = 0;
    int i   = 0;
    int j   = 0;

    dp  = malloc ((n + 1) * sizeof (int *));
    for (i = 0; i < (n + 1); i++) {
    
        dp[i]   = malloc ((W + 1) * sizeof (int));
    }

    for (i = 0; i < (n + 1); i++) {
    
        for (j = 0; j < (W + 1); j++) {
        
            dp[i][j]    = 0;
        }
    }

    for (i = 0; i < (n + 1); i++) {
    
        for (j = 0; j < (W + 1); j++) {
        
            if (i == 0 || j == 0) {
            
                dp[i][j]    = 0;
            } else if (wt[i - 1] < W) {
            
                dp[i][j]    = max ((val[i - 1] + dp[i - 1][j - wt[i - 1]]), dp[i - 1][j]);
            } else {
            
                dp[i][j]    = dp[i - 1][j];
            }
        }
    }

    m_v = dp[n][W];

    for (i = 0; i < (n + 1); i++) {
    
        free (dp[i]);
    }
    free (dp);

    return m_v;

}

int
main ()
{

    int val[]   = {60, 100, 120};
    int wt[]    = {10, 20, 30};
    int n       = 0;
    int W       = 0;

    n   = sizeof (val) / sizeof (int);
    W   = 50;

    printf ("The maximum knapsack value is: %d\n", max_knapsack (W, val, wt, n));

    return 0;

}
