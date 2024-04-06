#include "ak_mod_n.hpp"

long long ak_mod_n(long long a, long long k, long long n) {

    long long number = a % n, pow = k, ans = 1;

    if (pow & 1) ans = a;
    pow >>= 1;

    while (pow != 0)
    {
        number = (number*number) % n;

        if (pow & 1) ans = (number*ans) % n;
        pow >>= 1;
    }

    return ans;

}

