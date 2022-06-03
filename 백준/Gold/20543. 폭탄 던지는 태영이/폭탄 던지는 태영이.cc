#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e3;
int n, m;
long long h[MAXN + 1][MAXN + 1], ret[MAXN + 1][MAXN + 1],
    sum[MAXN + 1][MAXN + 1];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);

    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= n; x++) {
            scanf("%lld", &h[y][x]);
        }
    }

    for (int y = 1; y <= n - m + 1; y++) {
        for (int x = 1; x <= n - m + 1; x++) {
            sum[y + m / 2][x + m / 2] = sum[y + m / 2 - 1][x + m / 2] +
                                        sum[y + m / 2][x + m / 2 - 1] -
                                        sum[y + m / 2 - 1][x + m / 2 - 1];

            long long cur = sum[y + m / 2][x + m / 2];

            if (y + m / 2 - m >= 0) {
                cur -= sum[y + m / 2 - m][x + m / 2];

                if (x + m / 2 - m >= 0) {
                    cur += sum[y + m / 2 - m][x + m / 2 - m];
                }
            }

            if (x + m / 2 - m >= 0) {
                cur -= sum[y + m / 2][x + m / 2 - m];
            }

            ret[y + m / 2][x + m / 2] = h[y][x] - cur;

            sum[y + m / 2][x + m / 2] += ret[y + m / 2][x + m / 2];
        }
    }

    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= n; x++) {
            printf("%lld ", -ret[y][x]);
        }
        printf("\n");
    }

    return 0;
}
