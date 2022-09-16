#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
int n, m;
int dp[MAXN], deg[MAXN];
vector<int> edges[MAXN];

int get_dp(int cur) {
    int &ret = dp[cur];

    if (ret != -1) {
        return ret;
    }

    ret = 0;

    for (auto v : edges[cur]) {
        if (deg[v] < deg[cur]) {
            ret = max(ret, get_dp(v));
        }
    }

    ret++;
    return ret;
}

int main() {
    // freopen("input.txt", "r", stdin);

    memset(dp, -1, sizeof(dp));

    scanf("%d %d", &n, &m);

    while (m--) {
        int u, v;
        scanf("%d %d", &u, &v);

        edges[u].push_back(v);
        edges[v].push_back(u);

        deg[u]++;
        deg[v]++;
    }

    int ret = 0;
    for (int i = 0; i < n; i++) {
        ret = max(ret, get_dp(i));
    }

    printf("%d", ret);

    return 0;
}