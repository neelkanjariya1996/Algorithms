#include <stdio.h>
#include <stdlib.h>

int
count_set_bits (unsigned int num)
{

    int count = 0;

    while (num) {
    
        num = num & (num - 1);
        count++;
    }

    return count;

}

int
flip_count (int a, int b)
{

    return count_set_bits (a ^ b);

}

int
main ()
{

    int a = 0;
    int b = 0;

    a = 10;
    b = 20;

    printf ("To convert %d to %d, we need to flip %d bits\n", 
            a, b, flip_count (a, b));

    return 0;

}
