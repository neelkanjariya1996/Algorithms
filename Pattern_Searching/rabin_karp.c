#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define d   256

bool
rabin_karp_search (char txt[], char pat[], int q)
{

    bool pat_found  = false;
    int M           = 0;
    int N           = 0;
    int i           = 0;
    int j           = 0;
    int p           = 0;
    int t           = 0;
    int h           = 0;

    M   = strlen (pat);
    N   = strlen (txt);

    h   = 1;
    for (i = 0; i < (M - 1); i++) {
    
        h = (h * d) % q;
    }

    for (i = 0; i < M; i++) {
    
        t = (d * t + txt[i]) % q;
        p = (d * p + pat[i]) % q;
    }

    for (i = 0; i < (N - M); i++) {
    
        if (p == t) {
        
            for (j = 0; j < M; j++) {
            
                if (txt[i + j] != pat[j]) {
                
                    break;
                }
            }

            if (j == M) {
            
                printf ("Pattern found at index %d\n", i);
                pat_found = true;
            }
        }

        if (i < (N - M)) {
        
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;

            if (t < 0) {
            
                t = t + q;
            }
        }
    }

    return pat_found;

}

int
main ()
{

    char txt[]  = "geeks for geeks";
    char pat[]  = "geeks";
    int q       = 0;

    q = 101;

    if (!rabin_karp_search (txt, pat, q)) {
    
        printf ("Pattern Not Found\n");
    }

    return 0;

}
