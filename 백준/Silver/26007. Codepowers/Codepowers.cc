#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
int n, m, k, x;
int presum[MAXN + 1];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d %d %d", &n, &m, &k, &x);

    for (int i = 1; i <= n; i++) {
        int add;
        scanf("%d", &add);

        x += add;
        if (x < k) {
            presum[i] = 1;
        }
        presum[i] += presum[i - 1];
    }

    while (m--) {
        int l, r;
        scanf("%d %d", &l, &r);

        printf("%d\n", presum[r - 1] - presum[l - 1]);
    }

    return 0;
}
