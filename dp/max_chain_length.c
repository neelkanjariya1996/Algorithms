#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pair_t_ {

    int a;
    int b;

} pair_t;

int
mcl (pair_t arr[], int n)
{

    int *dp;
    int max = 0;
    int i   = 0;
    int j   = 0;

    dp  = malloc (n * sizeof (int));

    for (i = 0; i < n; i++) {
    
        dp[i]   = 1;
    }

    for (i = 1; i < n; i++) {
    
        for (j = 0; j < i; j++) {
        
            if ((arr[i].a > arr[j].b) && (dp[i] < (dp[j]) + 1)) {
            
                dp[i]   = dp[j] + 1;
            }
        }
    }

    max = dp[0];
    for (i = 1; i < n; i++) {
    
        if (dp[i] > max) {
        
            max = dp[i];
        }
    }

    free (dp);

    return max;

}

int
main ()
{

    pair_t arr[]    = {{5, 24}, {15, 25}, {27, 40}, {50, 60}};
    int n           = 0;

    n   = sizeof (arr) / sizeof (pair_t);

    printf ("The length of the maximum chain that can be formed is: %d\n", mcl (arr, n));

    return 0;

}
