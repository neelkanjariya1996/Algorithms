#include <stdio.h>
#include <stdlib.h>

void
change_to_zero (int a[2])
{

    a[a[1]] = a[!a[1]];

}

int
main ()
{

    int a[2] = {1, 0};
    
    printf ("Array before changing to zero: ");
    printf ("%d %d\n", a[0], a[1]);

    change_to_zero (a);

    printf ("Array after  changing to zero: ");
    printf ("%d %d\n", a[0], a[1]);

    return 0;

}
