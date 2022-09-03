#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[1001], b[1001], dp[1001][1001];

int get_dp(int men, int women, int op) {
    int &ret = dp[men][women];

    if (ret != -1) {
        return ret;
    }

    ret = 1e9;

    if (op == 0) {
        if (men == 0) {
            return ret = 0;
        }

        if (men < women) {
            ret = min(ret, get_dp(men, women - 1, op));
        }

        ret = min(ret, get_dp(men - 1, women - 1, op) + abs(a[men] - b[women]));

    } else {
        if (women == 0) {
            return ret = 0;
        }

        if (men > women) {
            ret = min(ret, get_dp(men - 1, women, op));
        }

        ret = min(ret, get_dp(men - 1, women - 1, op) + abs(a[men] - b[women]));
    }

    return ret;
}

int main() {
    // freopen("input.txt", "r", stdin);

    memset(dp, -1, sizeof(dp));

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 1; i <= m; i++) {
        scanf("%d", &b[i]);
    }

    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);

    int op = 0;
    if (n > m) {
        op = 1;
    }

    printf("%d", get_dp(n, m, op));

    return 0;
}
