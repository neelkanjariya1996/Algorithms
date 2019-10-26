#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

int
min (int a, int b)
{

    return ((a < b) ? a : b);

}

int
palindrome_partitioning (char *s)
{

    int **dp;
    int **p;
    int n   = 0;
    int i   = 0;
    int j   = 0;
    int k   = 0;
    int L   = 0;
    int m_v = 0;

    n   = strlen (s);
    printf ("n: %d\n", n);

    if (!s) {
    
        return 0;
    }

    if (n == 0) {
    
        return 0;
    }

    dp  = malloc (n * sizeof (int *));
    for (i = 0; i < n; i++) {
    
        dp[i]   = malloc (n * sizeof (int));
    }

    p   = malloc (n * sizeof (bool *));
    for (i = 0; i < n; i++) {
    
        p[i]    = malloc (n * sizeof (bool));
    }

    for (i = 0; i < n; i++) {
    
        for (j = 0; j < n; j++) {
        
            dp[i][j]    = INT_MAX;
            p[i][j]     = false;
        }
    }

    /*
    for (i = 0; i < n; i++) {
    
        for (j = 0; j < n; j++) {
        
            printf ("%d ", dp[i][j]);
        }
        printf ("\n");
    }
    printf ("\n");

    for (i = 0; i < n; i++) {
    
        for (j = 0; j < n; j++) {
        
            printf ("%d ", p[i][j]);
        }
        printf ("\n");
    }
    printf ("\n");
    */
    for (i = 0; i < n; i++) {
    
        p[i][i]     = true;
        dp[i][i]    = 0;
    }

    for (L = 2; L <= n; L++) {
    
        for (i = 0; i < (n - L + 1); i++) {
        
            j   = i + L - 1;

            if (L == 2) {
            
                p[i][j] = (s[i] == s[j]);
            } else {
            
                p[i][j] = ((s[i] == s[j]) && (p[i + 1][j - 1]));
            }

            if (p[i][j] == true) {
            
                dp[i][j]    = 0;
            } else {
            
                for (k = i; k <= (j - 1); k++) {
                
                    dp[i][j]    = min (dp[i][j], dp[i][k] + dp[k + 1][j] + 1);
                }
            }
        }
    }

    m_v = dp[0][n - 1];

    /*
    for (i = 0; i < n; i++) {
    
        free (dp[i]);
        free (p[i]);
    }
    free (dp);
    free (p);
    */

    return m_v;

}

int
main ()
{

    char s[]    = "ababbbabbababa";

    printf ("Minimum number of cuts needed for palindrome partitioning: %d\n",
            palindrome_partitioning (s));

    return 0;

}
