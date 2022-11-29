#include <stdio.h>
#include <time.h>

/* ref: https://www.spoj.com/problems/LPS/ */

#define DEBUG 0

int mancher(char s[], int m) {
    int n = m*2 + 3;
    char t[n];
    t[0] = '^';
    t[1] = t[n-2] = '#';
    t[n-1] = '$';

    for (int i = 0; i < m; i++) {
        t[i*2+2] = s[i];
        t[i*2+3] = '#';
    }
    /* for (int i = 0; i < n; i++) printf("%c", t[i]); printf("\n"); */
    int p[n], c = 0, r = 0, maxlen = 0;
    for (int i = 0; i < n; i++) p[i] = 0;
    for (int i = 1; i < n-1; i++) {
        int mirror = c*2 - i;
        if (i < r) {
            p[i] = p[mirror];
            if (p[i] > r - i) p[i] = r - i;
        }
        while (t[i+1+p[i]] == t[i-1-p[i]]) p[i]++;
        if (i + p[i] > r) {
            c = i;
            r = i + p[i];
        }
        if (maxlen < p[i]) maxlen = p[i];
    }
    return maxlen;
}


int maincase() {
    int n;
    scanf("%d", &n);
    char s[n];
    scanf("%c", &s[0]); // skip the \n
    for (int i = 0; i < n; i++) {
        scanf("%c", &s[i]);
    }
    printf("%d\n", mancher(s, n));
}

int testcase() {
}

int main() {
    if (DEBUG) testcase();
    else       maincase();
}


