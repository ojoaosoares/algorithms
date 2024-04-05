#include "insertion_sort.hpp"
#include <iostream>

using namespace std;

int main ()
{

    int n; 
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    insertion_sort<int>(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';

    cout << '\n';

    delete[] arr;


}

