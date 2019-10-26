#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int
coin_change (int *s, int m, int n)
{

    int **dp;
    int max = 0;
    int i   = 0;
    int j   = 0;
    int x   = 0;
    int y   = 0;

    dp  = malloc ((n + 1) * sizeof (int *));
    for (i = 0; i < (n + 1); i++) {
    
        dp[i]   = malloc (m * sizeof (int));
    }

    for (i = 0; i < (n + 1) ; i++) {
    
        for (j = 0; j < m; j++) {
        
            dp[i][j]    = 0;
            printf ("%d ", dp[i][j]);
        }
        printf ("\n");
    }
    printf ("\n");

    for (i = 0; i < m; i++) {
    
        dp[0][i]    = 1;
    }

    for (i = 1; i < (n + 1); i++) {
    
        for (j = 0; j < m; j++) {
        
            x   = (i - s[j] >= 0) ? dp[i - s[j]][j] : 0;
            y   = (j >= 1) ? dp[i][j - 1] : 0;

            dp[i][j]    = x + y;
        }
    }

    for (i = 0; i < (n + 1) ; i++) {
    
        for (j = 0; j < m; j++) {
        
            printf ("%d ", dp[i][j]);
        }
        printf ("\n");
    }
    printf ("\n");

    max = dp[n][m - 1];

    for (i = 0; i < (n + 1); i++) {
    
        free (dp[i]);
    }
    free (dp);

    return max;

}

int
main ()
{

    int s[] = {1, 2, 3};
    int n   = 0;
    int m   = 0;

    m   = sizeof (s) / sizeof (int);
    n   = 4;

    printf ("The number of ways to exchange coins is: %d\n", coin_change (s, m, n));

    return 0;

}
