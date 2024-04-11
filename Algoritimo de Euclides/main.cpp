#include "inverso_a_modulo_n.hpp"
#include <iostream>

using namespace std;

int main ()
{
    long long a, n;
    cin >> a >> n;

    pair<long long, long long> p = divisao_extendida(a, n);
    

    cout << p.first << ' ' << p.second << '\n';
    cout << inverso_modulo_n(a, n) << '\n';
}