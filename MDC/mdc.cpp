#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll mdc(ll a, ll b)
{
    ll big, small, r;

    if (a > b) { big = a; small = b; }

    else { big = b; small = a; }

    if (!small) return big;

    do
    {
        r = big%small;

        big = small;
        small = r;

    } while (r);

    return big; 
}

int main ()
{

    ll x, y;

    cin >> x >> y;

    cout << mdc(x, y) << '\n';
}