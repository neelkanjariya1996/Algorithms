#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
pattern_searching (char txt[], char pat[])
{

    int len1    = 0;
    int len2    = 0;
    int i       = 0;
    int j       = 0;

    len1    = strlen (txt);
    len2    = strlen (pat);

    for (i = 0; i <= (len1 - len2); i++) {
    
        for (j = 0; j < len2; j++) {
        
            if (txt[i + j] != pat[j]) {
            
                break;
            }
        }

        if (j == len2) {
        
            printf ("Pattern found at index %d\n", i);
        }
    }

}

int
main ()
{

    char txt[] = "AABAACAADAABAAABAA";
    char pat[] = "AABA";

    pattern_searching (txt, pat);

    return 0;

}
