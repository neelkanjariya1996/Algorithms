#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int
mcm (int p[], int n)
{

    int **m;
    int max = 0;
    int i   = 0;
    int j   = 0;
    int k   = 0;
    int q   = 0;
    int L   = 0;

    m   = malloc (n * sizeof (int *));
    for (i = 0; i < n; i++) {
    
        m[i]    = malloc (n * sizeof (int));
    }

    for (i = 0; i < n; i++) {
    
        for (j = 0; j < n; j++) {
        
            m[i][j] = INT_MAX;
        }
    }

    for (i = 0; i < n; i++) {
    
        m[i][i] = 0;
    }

    for (L = 2; L < n; L++) {
    
        for (i = 1; i < (n - L + 1); i++) {
    
            j   = i + L - 1;
            for (k = i; k <= (j - 1); k++) {
            
                q   = m[i][k] + m[k + 1] [j] + (p[i - 1] * p[k] * p[j]);
                if (q < m[i][j]) {
                
                    m[i][j] = q;
                }
            }
        }
    }

    max = m[1][n - 1];

    for (i = 0; i < n; i++) {
    
        free (m[i]);
    }
    free (m);

    return max;

}

int
main ()
{

    int p[] = {1, 2, 3, 4};
    int n   = 0;

    n   = sizeof (p) / sizeof (int);

    printf ("Minimum number of multiplactions is: %d\n", mcm (p, n));

    return 0;

}
