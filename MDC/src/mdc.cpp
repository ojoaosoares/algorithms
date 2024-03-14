#include "mdc.hpp"

long long mdc(long long a, long long b) {
    
    long long big, small, r;

    if (a > b) { big = a; small = b; }

    else { big = b; small = a; }

    if (!small) return big;

    do
    {
        r = big%small;

        big = small;
        small = r;

    } while (r);

    return big; 
}