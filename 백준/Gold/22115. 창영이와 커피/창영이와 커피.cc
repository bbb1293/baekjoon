#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e2, INF = 1e5;
int n, k;
int c[MAXN], dp[100001];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }

    for (int i = 1; i <= k; i++) {
        dp[i] = INF;
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = sum; j >= 0; j--) {
            dp[j + c[i]] = min(dp[j + c[i]], dp[j] + 1);
        }

        sum += c[i];
    }

    if (dp[k] == INF) {
        dp[k] = -1;
    }

    printf("%d", dp[k]);

    return 0;
}
