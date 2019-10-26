#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int
max (int a, int b)
{

    return ((a > b) ? a : b);

}

int
lps (char *s, int n)
{

    int **dp;
    int m_l = 0;
    int i   = 0;
    int j   = 0;
    int L   = 0;

    dp  = malloc (n * sizeof (int *));
    for (i = 0; i < n; i++) {
    
        dp[i]   = malloc (n * sizeof (int));
    }

    for (i = 0; i < n; i++) {
    
        for (j = 0; j < n; j++) {
        
            dp[i][j]    = 0;
            printf ("%d ", dp[i][j]);
        }
        printf ("\n");
    }
    printf ("\n");

    for (i = 0; i < n; i++) {
    
        dp[i][i]    = 1;
    }

    for (L = 2; L <= n; L++) {
    
        for (i = 0; i < (n - L + 1); i++) {
        
            j   = i + L - 1;

            if (s[i] == s[j] && L == 2) {
            
                dp[i][j]    = 2;
            } else if (s[i] == s[j]) {
            
                dp[i][j]    = dp[i + 1][j]  + 2;
            } else {
            
                dp[i][j]    = max (dp[i][j - 1], dp[i + 1][j]);
            }
        }
    }

    m_l = dp[0][n - 1];

    for (i = 0; i < n; i++) {
    
        free (dp[i]);
    }
    free (dp);

    return m_l;

}

int
main ()
{

    char s[]    = "ABCBA";
    int n       = 0;

    n   = sizeof (s) / sizeof (char);

    printf ("The length of longest palindromic subsequence is: %d\n", lps (s, n));

    return 0;

}
