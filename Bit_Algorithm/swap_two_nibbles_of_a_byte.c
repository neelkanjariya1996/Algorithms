#include <stdio.h>
#include <stdlib.h>

unsigned char
swap_nibbles (unsigned char x)
{

    return (((x & 0x0F) << 4) | ((x & 0xF0) >> 4));

}

int
main ()
{

    unsigned char x = 0;

    x = 10;

    printf ("After swapping the nibbles of %u, we get %u\n", 
            x, swap_nibbles (x));

    return 0;

}
