#include "inverso_a_modulo_n.hpp"
#include <iostream>

using namespace std;

int main ()
{
    long long a, n;
    cin >> a >> n;

    cout << inverso_modulo_n(a, n) << '\n';
}