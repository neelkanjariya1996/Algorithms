#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool
are_signs_opposite (int x, int y)
{

    return ((x ^ y) < 0);

}

int
main ()
{

    int x   = 10;
    int y   = -20;

    if ((are_signs_opposite (x, y)) == true) {
    
        printf ("Signs are opposite\n");
    } else {
    
        printf ("Signs are not opposite\n");
    }

    return 0;

}
