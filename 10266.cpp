#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500000;
int n;
int a[MAXN], b[MAXN];
int concat[3 * MAXN + 1];
int pi[3 * MAXN + 1];

int main() {
    freopen("input.txt", "r", stdin);
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    sort(a, a + n);
    sort(b, b + n);

    for (int i = 1; i < n; i++) {
        concat[i] = a[i] - a[i - 1];
    }
    concat[0] = 360000 + a[0] - a[n - 1];

    concat[n] = -1;

    for (int i = 1; i < n; i++) {
        concat[n + i] = b[i] - b[i - 1];
        concat[2 * n + i] = concat[n + i];
    }
    concat[2 * n] = 360000 + b[0] - b[n - 1];
    concat[3 * n] = concat[2 * n];

    for (int i = 1, j = 0; i <= 3 * n; i++) {
        while (j && (concat[j] != concat[i])) {
            j = pi[j - 1];
        }
        if (concat[j] == concat[i]) {
            j++;
        }
        pi[i] = j;

        if (j == n) {
            printf("possible");
            return 0;
        }
    }

    printf("impossible");
    return 0;
}