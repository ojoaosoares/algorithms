#include "inverso_a_modulo_n.hpp"

long long inverso_modulo_n(long long a, long long n)
{
    // Description : computes the inverse module n of a
    // Input : a, n
    // Output : inverse module n o f a
    // Complexity log n
    if (a > n) { return divisao_extendida(a, n).first; }
    else return divisao_extendida(n, a).second;
}

