#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

bool
subset_sum (int set[], int n, int sum)
{

    bool **dp;
    bool is_present = false;
    int i           = 0;
    int j           = 0;

    dp  = malloc ((n + 1) * sizeof (bool *));
    for (i = 0; i < (n + 1); i++) {
    
        dp[i]   = malloc ((sum + 1) * sizeof (bool));
    }

    for (i = 0; i <= n; i++) {
    
        for (j = 0; j <= sum; j++) {
        
            dp[i][j]    = false;
        }
    }

    for (i = 0; i <= n; i++) {
    
        dp[i][0]    = true;    
    }

    for (j = 1; j <= sum; j++) {
    
        dp[0][j]    = false;
    }

    for (i = 1; i <= n; i++) {
    
        for (j = 1; j <= sum; j++) {
        
            if (j < set[i - 1]) {
            
                dp[i][j]    = dp[i - 1][j];
            } else {
            
                dp[i][j]    = dp[i - 1][j] || dp[i - 1][j - set[i - 1]];
            }
        }
    }

    is_present = dp[n][sum];

    for (i = 0; i <= n; i++) {
    
        free (dp[i]);
    }
    free (dp);

    return is_present;

}

int
main ()
{

    int set[]   = {3, 34, 4, 12, 5, 2};
    int n       = 0;
    int sum     = 10;

    n   = sizeof (set) / sizeof (int);
    sum = 9;

    if (subset_sum (set, n, sum)) {
    
        printf ("Found a subset with given sum\n");
    } else {
    
        printf ("No subset with given sum found\n");
    }

    return 0;

}
