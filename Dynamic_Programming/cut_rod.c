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
max_profit (int *arr, int n)
{

    int *dp;
    int i       = 0;
    int j       = 0;
    int max_val = 0;

    if (!arr) {
    
        return 0;
    }

    if (n == 0) {
    
        return 0;
    }

    dp  = malloc ((n + 1) * sizeof (int));
    memset (dp, 0, (n + 1) * sizeof (int));

    dp[0]   = 0;
    for (i = 1; i <= n; i++) {
    
        max_val = INT_MIN;
        for (j = 0; j < i; j++) {
        
            max_val = max (max_val, dp[i - j - 1] + arr[j]);
        }
        dp[i]   = max_val;
    }

    max_val = dp[n];

    free (dp);

    return max_val;

}

int
main ()
{

    int arr[]   = {1,5,8,9,10,17,17,20};
    int n       = 0;
    int max_val = 0;

    n   = sizeof (arr) / sizeof (int);

    max_val = max_profit (arr, n);

    printf ("The maximum profit that can be achieved is: %d\n", max_val);


    return 0;

}
