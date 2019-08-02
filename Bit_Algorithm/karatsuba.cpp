#include <stdio.h>
#include <iostream>

using namespace std;

int
make_equal_lenght (string &X, string &Y)
{

    int len1    = 0;
    int len2    = 0;
    int i       = 0;

    len1 = X.size();
    len2 = Y.size();

    if (len1 < len2) {
    
        for (i = 0; i < (len2 - len1); i++) {
        
            X = '0' + X;
        }

        return len2;
    }

    if (len2 < len1) {
    
        for (i = 0; i < (len1 - len2); i++) {
        
            Y = '0' + Y;
        }
    }

    return len1;

}

string
add_bit_strings (string first, string second)
{

    string result;
    int len         = 0;
    int carry       = 0;
    int first_bit   = 0;
    int second_bit  = 0;
    int sum         = 0;
    int i           = 0;

    len = make_equal_lenght (first, second);

    for (i = (len - 1); i >= 0; i--) {
    
        first_bit   = first.at(i) - '0';
        second_bit  = second.at(i) - '0';

        sum = (first_bit ^ second_bit ^ carry) + '0';

        result = (char) sum + result;

        carry = (first_bit & second_bit) | (first_bit & carry) | (second_bit & carry);

    }

    if (carry) {
    
        result = '1' + result;
    }

    return result;

}

int
multiply_single_bits (string a, string b)
{

    return ((a[0] - '0') * (b[0] - '0'));

}

long int
multiply (string X, string Y)
{

    int n       = 0;
    int fh      = 0;
    int sh      = 0;
    long int p1 = 0;
    long int p2 = 0;
    long int p3 = 0;
    string Xl;
    string Xr;
    string Yl;
    string Yr;

    n = make_equal_lenght (X, Y);

    if (n == 0) {
    
        return 0;
    }

    if (n == 1) {
    
        return multiply_single_bits (X, Y);
    }

    fh = n/2;
    sh = n - fh;

    Xl = X.substr (0, fh);
    Xr = X.substr (fh, sh);

    Yl = Y.substr (0, fh);
    Yr = Y.substr (fh, sh);

    p1 = multiply (Xl, Yl);
    p2 = multiply (Xr, Yr);
    p3 = multiply (add_bit_strings (Xl, Xr), add_bit_strings (Yl, Yr));

    return ((p1 * (1 << (2 * sh)) + ((p3 - p1 - p2) * (1 << sh)) + p2));

}

int
main ()
{

    printf ("%ld \n", multiply ("1010", "1100"));

    return 0;

}
