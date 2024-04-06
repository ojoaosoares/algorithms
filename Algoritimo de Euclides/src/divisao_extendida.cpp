#include "divisao_extendida.hpp"

std::pair<long long, long long> divisao_extendida(long long a, long long b) 
{

    long long big = a, small = b, x = 1, x0 = 1, x1 = 0, y = 0, y0 = 0, y1 = 1;

    while (true)
    {
        long long q = big / small, r = big - q * small;
        
        if(!r) break;

        x = x0 - x1 * q;
        y = y0 - y1 * q;

        x0 = x1; x1 = x;
        y0 = y1; y1 = y;

        big = small;
        small = r;
    }


    
    return std::pair<long long, long long> {x, y};

}