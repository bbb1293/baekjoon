#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;
int n, k;
int a[MAXN], cnt[2], dp[2][2];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        a[i] &= 1;
    }

    for (int i = 0; i < k; i++) {
        cnt[0] = cnt[1] = 0;
        for (int j = i; j < n; j += k) {
            cnt[0] += (1 ^ a[j]);
            cnt[1] += a[j];
        }

        if (i == 0) {
            dp[i & 1][0] = cnt[1];
            dp[i & 1][1] = cnt[0];
        } else {
            dp[i & 1][0] = min(dp[(i & 1) ^ 1][0] + cnt[1],
                               dp[(i & 1) ^ 1][1] + cnt[0]);
            dp[i & 1][1] = min(dp[(i & 1) ^ 1][0] + cnt[0],
                               dp[(i & 1) ^ 1][1] + cnt[1]);
        }
    }

    printf("%d", dp[(k - 1) & 1][0]);

    return 0;
}
