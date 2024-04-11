#include "shell_sort.hpp"
#include <iostream>

using namespace std;

typedef long long ll;

int main() {

    ll n;
    cin >> n;

    ll *arr = new ll[n];

    for (ll i = 0; i < n; i++)
        cin >> arr[i];

    shell_sort(arr, n);

    for (ll i = 0; i < n; i++)
        cout << arr[i] << ' ';

    cout << '\n';

}