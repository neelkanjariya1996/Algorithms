#include <stdio.h>
#include <stdlib.h>

int
main ()
{

    unsigned int i  = 0;
    char *c         = 0;

    i   = 1;
    c   = (char *) &i;

    if (*c) {
    
        printf ("Little Endian\n");
    } else {
    
        printf ("Big Endian\n");
    }

    return 0;

}
