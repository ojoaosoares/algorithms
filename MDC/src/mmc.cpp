#include "mmc.hpp"

long long mmc(long long a, long long b) {
    return (a*b) / mdc(a, b);
}