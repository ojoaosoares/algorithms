#include <bits/stdc++.h>
#include "mdc.hpp"
#include "mmc.hpp"

typedef long long ll;

using namespace std;

int main ()
{
    ll x, y;

    cin >> x >> y;

    cout << mdc(x, y) << ' ' << mmc(x, y) << '\n';
}