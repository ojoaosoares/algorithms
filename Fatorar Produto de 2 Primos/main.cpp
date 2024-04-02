#include <iostream>
#include <cmath>

typedef long long ll;

std::pair<ll, ll> fatorar(ll n) {

    ll x = std::ceil(sqrt(n));
    double y, z = x*x - n;

    while (true) {

        y = sqrt(z);

        if ((double) std::abs(y) == y) break;

        z += 2*x + 1;
        x++;
    }

    return std::pair<ll, ll>{x - y, x + y};
}

int main() {

    ll x;
    std::cin >> x;

    std::pair<ll, ll> p = fatorar(x);

    std::cout << p.first << ' ' << p.second << '\n';

}

