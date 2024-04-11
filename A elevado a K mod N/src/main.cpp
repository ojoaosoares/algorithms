#include "ak_mod_n.hpp"
#include <iostream>

using namespace std;

typedef long long ll;

int main()
{   
    ll a, k, n;
    cin >> a >> k >> n;

    cout  << ak_mod_n(a, k, n) << '\n';
}
