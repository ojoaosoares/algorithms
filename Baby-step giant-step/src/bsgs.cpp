#include "bsgs.hpp"

long long bs_gs(long long a, long long b, long long p)
{
    // Input : a, b, p
    // Output : X (p mod log (a) b = x  /  a^x = b mod p) If it returns -1, it's because mdc(a,b) != 1

    unsigned long long m = std::ceil(std::sqrt(p)),
    precomp_ba[m]; precomp_ba[0] = b % p;
    unsigned long long inverse_a = inverso_modulo_n(a, p);

    // ( b * (a^-1) ^ i) mod p
    for (unsigned long long i = 1; i < m; i++)
        precomp_ba[i] = (precomp_ba[i - 1] * inverse_a) % p;
    
    unsigned long long pro = 1, am = ak_mod_n(a, m, p);

    // ((am) ^ j) mod p
    for (unsigned long long j = 0; j < m; j++)
    {
        for (unsigned long long i = 0; i < m; i++)
            if (precomp_ba[i] == pro)
                return (m * j) +  i;
        
        pro = (pro * am) % p;
    }
    
    return -1;
}