#ifndef SELECTION_SORT
#define SELECTION_SORT

#define troca(A,B) {T C = A; A = B; B = C;}

template<typename T> void selection_sort(T array[], long long n);

template <typename T> void recursiveSelectionSort(T arr[], long long  l, long long r);

#endif