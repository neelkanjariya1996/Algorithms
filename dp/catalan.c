#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int
catalan (int n)
{

    int *dp;
    int i   = 0;
    int j   = 0;

    if (n < 0) {

        return INT_MAX;
    }

    dp  = malloc ((n + 1) * sizeof (int));
    memset (dp, 0, (n + 1) * sizeof (int));

    dp[0]   = 1;
    dp[1]   = 1;

    for (i = 2; i <= n; i++) {
    
        for (j = 0; j < i; j++) {

            dp[i]   += dp[j] * dp[i - j - 1];
        }
    }

    return (dp[n]);

}

int
main ()
{

    int n   = 0;

    n   = 9;

    printf ("The %dth catalan number is: %d\n", n, catalan (n));

    return 0;

}
