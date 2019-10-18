#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int
min (int a, int b)
{

    return ((a < b) ? a : b);

}

int
edit_distance (char *a, char *b, int m, int n)
{

    int **dp;
    int max = 0;
    int i   = 0;
    int j   = 0;

    dp  = malloc ((m + 1) * sizeof (int *));
    for (i = 0; i <= m; i++) {
    
        dp[i]   = malloc ((n + 1) * sizeof (int));
    }

    for (i = 0; i <= m; i++) {
    
        for (j = 0; j <= n; j++) {
        
            dp[i][j]    = 0;
            printf ("%d ", dp[i][j]);
        }
        printf ("\n");
    }
    printf ("\n");

    for (i = 0; i <= m; i++) {
    
        for (j = 0; j <= n; j++) {
        
            if (i == 0) {
            
                dp[i][j]    = j;
            } else if (j == 0) {
            
                dp[i][j]    = i;
            } else if (a[i - 1] == b[j - 1]) {
            
                dp[i][j]    = dp[i - 1][j - 1];
            } else {
            
                dp[i][j]    = 1 + min (dp[i][j - 1], 
                                  min (dp[i - 1][j],
                                      dp[i - 1][j - 1]));
            }
        }
    }

    max = dp[m][n];

    for (i = 0; i <= m; i++) {
    
        for (j = 0; j <= n; j++) {
        
            printf ("%d ", dp[i][j]);
        }
        printf ("\n");
    }
    printf ("\n");

    for (i = 0; i <= m; i++) {
    
        free (dp[i]);
    }
    free (dp);

    return max;

}

int
main ()
{

    char a[]    = "sunday";
    char b[]    = "saturday";
    int m       = 0;
    int n       = 0;

    m   = sizeof (a) / sizeof (char);
    n   = sizeof (b) / sizeof (char);

    printf ("The Edit Distance to convert a to b is: %d\n", edit_distance (a, b, m, n));

    return 0;

}
