#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
climbing_stairs (int n)
{

    int *dp;
    int ways    = 0;
    int i       = 0;

    dp  = malloc ((n + 1) * sizeof (int));
    memset (dp, 0, (n + 1) * sizeof (int));

    dp[0]   = 1;
    dp[1]   = 1;

    for (i = 2; i <= n; i++) {
    
        dp[i]   = dp[i - 1] + dp[i - 2];
    }

    ways    = dp[n];

    free (dp);

    return ways;

}

int
main ()
{

    int n   = 0;

    n   = 4;

    printf ("The number of ways to climb %d stairs is: %d\n", n, climbing_stairs (n));

    return 0;

}
