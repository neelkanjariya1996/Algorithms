#include <stdio.h>
#include <stdlib.h>

unsigned int
reverse_bits (unsigned int num)
{

    unsigned int reverse_num    = 0;
    unsigned int count          = 0;

    reverse_num = num;
    count       = sizeof (num) * 8 - 1;

    num = num >> 1;
    while (num) {
    
        reverse_num = reverse_num << 1;
        reverse_num = reverse_num | (num & 1);
        num         = num >> 1;
        count--;
    }

    reverse_num = reverse_num << count;

    return reverse_num;

}

int
main ()
{

    unsigned int x  = 0;

    x = 5;

    printf ("After reversing the bits of %u, it becomes %u \n", x, reverse_bits (x));

    return 0;

}
