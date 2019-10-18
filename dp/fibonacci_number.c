#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int
fib (int n)
{

    int *f;
    int i   = 0;

    if (n < 0) {
    
        return INT_MIN;
    }

    f   = malloc ((n + 1) * sizeof (int));
    memset (f, 0, (n + 1) * sizeof (int));

    f[0]    = 0;
    f[1]    = 1;

    for (i = 2; i <= n; i++) {
    
        f[i]    = f[i - 1] + f[i - 2];
    }

    return f[n];

} 

int
main ()
{

    int n   = 0;

    n   = 3;

    printf ("The %dth fibonacci number is %d\n", n, fib(n));

    return 0;

}
