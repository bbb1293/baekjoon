#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
int n, x;
vector<pair<int, int> > edges[MAXN + 1];
int cnt[20], on[MAXN + 1][20];

void dfs(int prev, int signal, int cur) {
    for (int i = 0; i < 20; i++) {
        if (signal & (1 << i)) {
            on[cur][i] = 1;
            cnt[i]++;
        }
    }

    for (auto [v, c] : edges[cur]) {
        if (v == prev) {
            continue;
        }

        dfs(cur, signal ^ c, v);
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &x);

    for (int i = 1; i < n; i++) {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);

        edges[u].push_back({v, c});
        edges[v].push_back({u, c});
    }

    dfs(-1, 0, 1);

    int ret = 1e9;
    for (int i = 1; i <= n; i++) {
        int cand = 0;

        for (int j = 0; j < 20; j++) {
            int bit = 0;
            if (x & (1 << j)) {
                bit = 1;
            }

            if (on[i][j]) {
                cand += (bit * cnt[j] +
                         (1 ^ bit) * (n - cnt[j]));
            } else {
                cand += ((1 ^ bit) * cnt[j] +
                         bit * (n - cnt[j]));
            }
        }

        ret = min(ret, cand);
    }

    printf("%d", ret);

    return 0;
}
