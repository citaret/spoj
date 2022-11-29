#include <stdio.h>

/* https://www.spoj.com/problems/MERGSORT/ */

void merge(int a[], int aux[], int lo, int mid, int hi) {
    for (int k = lo; k <= hi; k++) {
        aux[k] = a[k];
    }

    int i = lo, j = mid+1;
    for (int k = lo; k <= hi; k++) {
        if      (i > mid)              a[k] = aux[j++];
        else if (j > hi)               a[k] = aux[i++];
        else if (aux[j] < aux[i])      a[k] = aux[j++];
        else                           a[k] = aux[i++];
    }
}

void sort(int a[], int aux[], int lo, int hi) {
    if (hi <= lo) return;
    int mid = lo + (hi - lo) / 2;
    sort(a, aux, lo, mid);
    sort(a, aux, mid + 1, hi);
    merge(a, aux, lo, mid, hi);
}

int main() {
    int MAX = 100000, n = 0;
    int A[MAX], AUX[MAX];
    while (scanf("%d", &A[n]) != EOF) n++;
    sort(A, AUX, 0, n-1);
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
}
