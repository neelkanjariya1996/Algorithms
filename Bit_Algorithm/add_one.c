#include <stdio.h>
#include <stdlib.h>

int
add_one (int x)
{

    int m = 0;

    m = 1;
    while (x & m) {
    
        x = x ^ m;
        m = m << 1;
    }

    x = x ^ m;

    return x;

}

int
main ()
{

    int x = 0;

    x = 7;

    printf ("%d + 1 = %d\n", x, add_one (x));

    return 0;

}
