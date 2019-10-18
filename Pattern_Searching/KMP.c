#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void
compute_lps (char pat[], int M, int lps[])
{

    int len = 0;
    int i   = 0;

    lps[0]  = 0;

    i   = 1;
    while (i < M) {
    
        if (pat[i] == pat[len]) {
        
            len++;
            lps[i] = len;
            i++;
        } else {
        
            if (len != 0) {
            
                len = lps[len - 1];
            } else {
            
                lps[i] = 0;
                i++;
            }
        }
    }

}

bool
kmp_search (char txt[], char pat[])
{

    int N           = 0;
    int M           = 0;
    int i           = 0;
    int j           = 0;
    bool pat_found  = false;

    N   = strlen (txt);
    M   = strlen (pat);

    int lps[M];
    memset (lps, 0, sizeof (lps));

    compute_lps (pat, M, lps);

    while (i < N) {
    
        if (pat[j] == txt[i]) {
        
            i++;
            j++;
        }

        if (j == M) {
        
            printf ("Pattern Found at index: %d\n", (i - j));
            j           = lps[j - 1];
            pat_found   = true;
        } else if (i < N && pat[j] != txt[i]){
        
            if (j != 0) {
            
                j = lps[j - 1];
            } else {
            
                i++;
            }
        }
    }

    return pat_found;

}

int
main ()
{

    char txt[]  = "abbababbabanca";
    char pat[]  = "nca";

    printf ("Text    : %s\n", txt);
    printf ("Pattern : %s\n", pat);

    if (!(kmp_search (txt, pat))) {
    
        printf ("Pattern Not Found\n");
    }

    return 0;

}
