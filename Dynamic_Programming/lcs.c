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
lcs (char *a, char *b)
{

    int **dp;
    int len1    = 0;
    int len2    = 0;
    int i       = 0;
    int j       = 0;
    int max_len = 0;

    len1    = strlen (a);
    len2    = strlen (b);

    dp  = malloc ((len1 + 1) * sizeof (int *));
    for (i = 0; i <= len1; i++) {
    
        dp[i]   = malloc ((len2 + 1) * sizeof (int));
    }

    for (i = 0; i <= len1; i++) {
    
        for (j = 0; j <= len2; j++) {
        
            dp[i][j]    = 0;
            printf ("%d ", dp[i][j]);
        }
        printf ("\n");
    }
    printf ("\n");

    for (i = 0; i <= len1; i++) {
    
        for (j = 0; j <= len2; j++) {
        
            if (i == 0 || j == 0) {
            
                dp[i][j]    = 0;
            } else if (a[i] == b[j]) {
            
                dp[i][j]    = dp[i - 1][j - 1] + 1;
            } else {
            
                dp[i][j]    = max (dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    for (i = 0; i <= len1; i++) {
    
        for (j = 0; j <= len2; j++) {
        
            printf ("%d ", dp[i][j]);
        }
        printf ("\n");
    }

    max_len = dp[len1][len2];

    for (i = 0; i <= len1; i++) {
    
        free (dp[i]);
    }
    free (dp);

    return max_len;

}

int
main ()
{

    char a[]    = "ABCDABCD";
    char b[]    = "ABCD";

    printf ("The lenght of Longest Common Substring is: %d\n", lcs(a, b));

    return 0;

}
