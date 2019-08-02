#include <stdio.h>
#include <stdlib.h>

void
swap_number (int *a, int *b)
{

    if (a == b) {
    
        return;
    }

    *a  = *a ^ *b;
    *b  = *b ^ *a;
    *a  = *a ^ *b;

}

int
main ()
{

    int a = 0;
    int b = 0;

    a = 5;
    b = 51;

    printf ("a = % d and b = %d\n", a, b);
    printf ("After swapping: ");
    swap_number (&a, &a);
    printf ("a = % d and b = %d\n", a, b);

    return 0;

}
