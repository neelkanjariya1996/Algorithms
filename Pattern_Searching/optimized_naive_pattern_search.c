#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool
pattern_search (char txt[], char pat[])
{

    int M       = 0;
    int N       = 0;
    int i       = 0;
    int j       = 0;
    bool found  = false;

    N   = strlen (txt);
    M   = strlen (pat);

    while (i <= (N -M)) {
    
        for (j = 0; j < M; j++) {
        
            if (txt[i + j] != pat[j]) {
            
                break;
            }
        }

        if (j == M) {
        
            printf ("Pattern Found at Index: %d\n", i);
            i       = i + M;
            found   = true;
        } else if (j == 0) {
        
            i   = i + 1;
        } else {
        
            i   = i + j;
        }
    }

    return found;

}

int
main ()
{

    char txt[]  = "my name is neel";
    char pat[]  = "name";

    printf ("Text   : %s\n", txt);
    printf ("Pattern: %s\n", pat);

    if (!pattern_search (txt, pat)) {
    
        printf ("Pattern Not Found\n");
    }

    return 0;

}
