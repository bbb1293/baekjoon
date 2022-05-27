#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
const long long MOD = 1e9 + 7;
int n;
int num[MAXN + 1];
long long dp[MAXN + 1][10];
vector<int> edges[MAXN + 1];

long long get_dp(int cur, int max_num, int prev = -1) {
    long long &ret = dp[cur][max_num];

    if (ret != -1) {
        return ret;
    }

    ret = 0;
    for (auto next : edges[cur]) {
        if (next != prev) {
            ret += get_dp(next, max_num, cur);
            ret %= MOD;
        }
    }

    if (max_num <= num[cur]) {
        ret++;
        ret %= MOD;

        for (auto next : edges[cur]) {
            if (next != prev) {
                ret += get_dp(next, num[cur], cur);
                ret %= MOD;
            }
        }
    }

    return ret;
}

int main() {
    // freopen("input.txt", "r", stdin);

    memset(dp, -1, sizeof(dp));

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &num[i]);
    }

    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    printf("%lld", get_dp(1, 0));

    return 0;
}
