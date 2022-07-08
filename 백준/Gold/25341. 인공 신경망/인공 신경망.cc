#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e3;
int n, m, q;
int c[MAXN], p[MAXN][MAXN], w[MAXN][MAXN], b[MAXN];
long long sum[MAXN];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d %d", &n, &m, &q);

    for (int i = 0; i < m; i++) {
        scanf("%d", &c[i]);

        for (int j = 0; j < c[i]; j++) {
            scanf("%d", &p[i][j]);
        }

        for (int j = 0; j < c[i]; j++) {
            scanf("%d", &w[i][j]);
        }

        scanf("%d", &b[i]);
    }

    long long ret = 0;
    for (int i = 0; i < m; i++) {
        int cur_w;
        scanf("%d", &cur_w);

        ret += (b[i] * cur_w);

        for (int j = 0; j < c[i]; j++) {
            sum[p[i][j] - 1] += (w[i][j] * cur_w);
        }
    }

    int cur_b;
    scanf("%d", &cur_b);

    ret += cur_b;

    while (q--) {
        long long tmp = 0;
        for (int i = 0; i < n; i++) {
            int a;
            scanf("%d", &a);

            tmp += (a * sum[i]);
        }

        printf("%lld\n", ret + tmp);
    }

    return 0;
}
