#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3, MAXC = 1e5;
int n, c;
int w[MAXN + 1], presum[MAXN + 1];
bool dp[MAXC + 1];

int main() {
    // reopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &c);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
    }
    sort(w + 1, w + n + 1);

    for (int i = 1; i <= n; i++) {
        presum[i] = presum[i - 1] + w[i];
    }

    if (presum[n] <= c) {
        printf("%d", presum[n]);

        return 0;
    }

    int ret = c;

    dp[0] = true;
    for (int i = n; i >= 1; i--) {
        int cand = max(0, c - presum[i] + 1);
        if (cand) {
            while (cand < c - presum[i - 1] && !dp[cand]) {
                cand++;
            }
        }

        ret = min(ret, cand + presum[i - 1]);
        for (int j = c; j >= w[i]; j--) {
            dp[j] |= dp[j - w[i]];
        }
    }

    printf("%d", ret);

    return 0;
}