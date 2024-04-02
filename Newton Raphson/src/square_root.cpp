#include "square_root.hpp"

double square_root_NR (double n)
{
    double n0 = n/2, n1;

    while (true)
    {
        n1 = ((n - n0*n0)/ (2 *n0)) + n0;

        if (n1 - n0 < tolerancia) break;

        n0 = n1;
    }
    
    return n1;
}
