#include <stdio.h>
#include <stdlib.h>

int
add_numbers (int a, int b)
{
    
    int carry   = 0;

    while (b != 0) {
    
        carry   = a & b;
        a       = a ^ b;
        b       = carry << 1;
    }

    return a;

}

int
main ()
{

    int a = 0;
    int b = 0;

    a = 15;
    b = 30;

    printf ("%d + %d = %d\n", a, b, add_numbers (a, b));

    return 0;

}
