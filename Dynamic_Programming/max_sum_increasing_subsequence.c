#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int
max_sum_increasing_subsequence (int *arr, int n)
{

    int *dp;
    int max = 0;
    int i   = 0;
    int j   = 0;

    if (!arr) {
    
        return 0;
    }

    if (n == 0) {
    
        return 0;
    }

    dp = malloc (n * sizeof (int));

    for (i = 0; i < n; i++) {
    
        dp[i]  = arr[i];
    }

    for (i = 1; i < n; i++) {
    
        for (j = 0; j < i; j++) {
        
            if ((arr[i] > arr[j]) && (dp[i] < (dp[j] + arr[i]))) {
            
                dp[i]  = dp[j] + arr[i];
            }
        }
    }

    max = dp[0];
    for (i = 1; i < n; i++) {
    
        if (max < dp[i]) {
        
            max = dp[i];
        }
    }

    free (dp);

    return max;

}

int
main ()
{

    int arr[]   = {1, 101, 2, 3, 100, 4, 5};
    int n       = 0;

    n   = sizeof (arr) / sizeof (int);

    printf ("The maximum sum of increasing subsequence is: %d\n", 
            max_sum_increasing_subsequence (arr, n));

    return 0;

}
