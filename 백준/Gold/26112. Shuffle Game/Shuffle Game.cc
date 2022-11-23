#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500;
int n, p, q;
int dp[MAXN + 1][MAXN + 1][MAXN + 1];
string x[MAXN + 1], p1[MAXN + 1], p2[MAXN + 1];

int get_dp(int i, int j, int k) {
    if (i == 0) {
        return 0;
    }

    int &ret = dp[i][j][k];
    if (ret != -1) {
        return ret;
    }

    ret = 0;
    if (0 < j) {
        int add = 0;
        if (x[i] == p1[j]) {
            add = 1;
        }
        ret = max(ret, get_dp(i - 1, j - 1, k) + add);
        ret = max(ret, get_dp(i, j - 1, k));
    }

    if (0 < k) {
        int add = 0;
        if (x[i] == p2[k]) {
            add = 1;
        }
        ret = max(ret, get_dp(i - 1, j, k - 1) + add);
        ret = max(ret, get_dp(i, j, k - 1));
    }

    ret = max(ret, get_dp(i - 1, j, k));

    return ret;
}

int main() {
    // freopen("input.txt", "r", stdin);

    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> p >> q;

    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }

    for (int i = 1; i <= p; i++) {
        cin >> p1[i];
    }

    for (int i = 1; i <= q; i++) {
        cin >> p2[i];
    }

    memset(dp, -1, sizeof(dp));

    printf("%d", get_dp(n, p, q));

    return 0;
}
