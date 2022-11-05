#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3;
int n;
int a[MAXN], dp[MAXN][MAXN];

int get_dp(int i, int t) {
    if (i == n) {
        return 0;
    }

    int &ret = dp[i][t];
    if (ret != -1) {
        return ret;
    }

    ret = get_dp(i + 1, t);

    if (a[i] - t > 0) {
        ret = max(ret, get_dp(i + 1, t + 1) + a[i] - t);
    }

    return ret;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    memset(dp, -1, sizeof(dp));

    printf("%d", get_dp(0, 0));

    return 0;
}