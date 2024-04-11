#include "mmc.hpp"

long long mmc(long long a, long long b) {
    // Description : computes the lsn of two numbers, a, b
    // Input : A, B
    // Output : lsn(A.B)
    // Complexity : log min(a, b)
    return (a*b) / mdc(a, b);
}