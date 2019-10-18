#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
tiling_ways (int n)
{

    int *dp;
    int ways    = 0;
    int i       = 0;

    if (n < 0) {
    
        return 0;
    }

    dp  = malloc ((n + 1) * sizeof (int));
    memset (dp, 0, (n + 1) * sizeof (int));

    dp[0]   = 1;
    dp[1]   = 1;
    dp[2]   = 2;

    for (i = 3; i <= n; i++) {
    
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

    printf ("The number of ways the tiles can be aranged when the grid is 2 x %d is %d\n", n, tiling_ways (n));

    return 0;

}
