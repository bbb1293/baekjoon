#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e3;
int n;
int v[MAXN], dp[MAXN][MAXN + 1][2];

int get_dp(int cur, int rank, int dir) {
    if (rank == n) {
        return v[cur] * rank;
    }

    int &ret = dp[cur][rank][dir];
    if (ret != -1) {
        return ret;
    }

    ret = (v[cur] * rank);

    if (dir == 0) {
        int cnt = cur + 1;
        ret +=
            max(get_dp(cur + 1, rank + 1, 0),
                get_dp(n - (rank - cnt) - 1, rank + 1, 1));
    } else {
        int cnt = n - cur;
        ret += max(get_dp(cur - 1, rank + 1, 1),
                   get_dp(rank - cnt, rank + 1, 0));
    }

    return ret;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    memset(dp, -1, sizeof(dp));

    printf("%d", max(get_dp(0, 1, 0), get_dp(n - 1, 1, 1)));

    return 0;
}