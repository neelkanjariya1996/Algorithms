#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define R   3
#define C   3

int
min (int a, int b)
{

    return ((a < b) ? a : b);

}

int
min_cost_path (int mat[R][C], int m, int n)
{

    if (!mat) {
    
        return 0;
    }

    int **dp;
    int cost    = 0;
    int i       = 0;
    int j       = 0;
    
    dp  = malloc (R * sizeof (int *));
    for (i = 0; i < R; i++) {
    
        dp[i]   = malloc (C * sizeof (int));
    }

    for (i = 0; i < R; i++) {
    
        for (j = 0; j < C; j++) {
        
            dp[i][j]    = 0;
            printf ("%d ", dp[i][j]);
        }
        printf ("\n");
    }
    printf ("\n");

    dp[0][0]    = mat[0][0];

    for (i = 1; i < R; i++) {
    
        dp[i][0]    = mat[i][0] + dp[i - 1][0];
    }

    for (j = 1; j < C; j++) {
    
        dp[0][j]    = mat[0][j] + dp[0][j - 1];
    }

    for (i = 1; i <= m; i++) {
    
        for (j = 1; j <= n; j++) {
        
            dp[i][j]    = min (dp[i - 1][j - 1],
                          min (dp[i][j - 1], 
                              dp[i - 1][j])) + mat[i][j];
        }
    }

    for (i = 0; i < R; i++) {
    
        for (j = 0; j < C; j++) {
        
            printf ("%d ", dp[i][j]);
        }
        printf ("\n");
    }
    printf ("\n");

    cost    = dp[m][n];

    for (i = 0; i < R; i++) {
    
        free (dp[i]);
    }
    free (dp);

    return cost;

}

int
main ()
{

    int mat[R][C]   = {
                      {1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3}
                      };
    int m           = 0;
    int n           = 0;

    m   = 2;
    n   = 2;

    printf ("The minimum cost path to reach (%d, %d) from (0, 0) is: %d\n",
            m, n, min_cost_path (mat, m, n));


    return 0;

}
