#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int
max_num_path (int m, int n)
{

    int **dp;
    int mx  = 0;
    int i   = 0;
    int j   = 0;

    if (m == 0 && n == 0) {
   
        return 0;
    }

    dp  = malloc (m * sizeof (int *));
    for (i = 0; i < m; i++) {
    
        dp[i]   = malloc (n * sizeof (int));
    }

    for (i = 0; i < m; i++) {
    
        for (j = 0; j < n; j++) {
        
            dp[i][j]    = 0;
            printf ("%d ", dp[i][j]);
        }
        printf ("\n");
    }
    printf ("\n");

    for (i = 0; i < m; i++) {
    
        dp[i][0]    = 1;
    }

    for (j = 0; j < n; j++) {
    
        dp[0][j]    = 1;
    }

    for (i = 1; i < m; i++) {
    
        for (j = 1; j < n; j++) {
        
            dp[i][j]    = dp[i][j - 1] + dp[i - 1][j];
        }
    }

    for (i = 0; i < m; i++) {
    
        for (j = 0; j < n; j++) {
        
            printf ("%d ", dp[i][j]);
        }
        printf ("\n");
    }
    printf ("\n");
    mx  = dp[m - 1][n - 1];

    for (i = 0; i < m; i++) {
    
        free (dp[i]);
    }
    free (dp);

    return mx;

}

int 
main ()
{

    int m   = 0;
    int n   = 0;

    m   = 3;
    n   = 3;

    printf ("The number of paths to reach (%d, %d) from (0, 0) is: %d\n", 
            m, n, max_num_path (m, n));

    return 0;

}
