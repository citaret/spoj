#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* https://www.spoj.com/problems/MAXSUMSQ/ */

#define DEBUG 1

const int INF = 0x3f3f3f3f;

int maxsum;
int maxsumsq_ref(int *a, int n) {
    int A[n];
    int count = 1;
    maxsum = a[0]-1;
    for (int i = 0; i < n; i++)
        A[i] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            A[j] += a[j-i];
            if (maxsum < A[j]) {
                maxsum = A[j];
                count = 1;
            } else if (maxsum == A[j]) {
                count++;
            }
        }
    }
    return count;
}

int maxsumsq(int *a, int n) {
    int A[n];
    maxsum = A[0] = a[0];
    for (int i = 1; i < n; i++) {
        A[i] = a[i];
        A[i] += A[i-1] > 0 ? A[i-1] : 0;
        if (maxsum < A[i]) maxsum = A[i];
    }
    /* for (int i = 0; i < n; i++) printf("%d ", A[i]); printf("\n"); */
    int count = 0, count_zero = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] == maxsum) count += count_zero+1;
        if (A[i] == 0)    count_zero++;
        else if (A[i] < 0) count_zero = 0;
    }
    return count;
}

int maxsumsq_onepass(int a[], int n) {
    int maxsum, sum, mn;
    int cnt, rct;
    maxsum = -INF;
    sum = mn = rct = 0;
    cnt = 1;
    for(int i = 0; i < n; i++) {
        sum += a[i];
        if(sum - mn > maxsum) {
            maxsum = sum - mn;
            rct = cnt;
        }
        else if(sum - mn == maxsum) {
            rct += cnt;
        }
        if(sum < mn) {
            mn = sum;
            cnt = 1;
        }
        else if(sum == mn) {
            cnt++;
        }
        /* printf("a: %d, sum: %d, mn: %d, maxsum: %d, cnt: %d, rct: %d\n", a, sum, mn, maxsum, cnt, rct); */
    }
    return rct;
}

int maincase() {
    int T, n, count;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int a[n];
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[j]);
        }
        count = maxsumsq(a, n);
        printf("%d %lld\n", maxsum, count);
    }
}

int testcase() {
    int m = 9, n = 7, count;
    srand(time(0));
    for (int i = 0; i < m; i++) {
        int a[n];
        for (int j = 0; j < n; j++) {
            a[j] = -1 + random() % 3;
            printf("%d ", a[j]);
        }
        printf("\n");
        count = maxsumsq_ref(a, n);
        printf("%d %d\n", maxsum, count);
        count = maxsumsq(a, n);
        printf("%d %d\n", maxsum, count);
        count = maxsumsq_onepass(a, n);
        printf("%d %d\n", maxsum, count);
        printf("\n");
    }
}

int main() {
    if (DEBUG) testcase();
    else       maincase();
}
