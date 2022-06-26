#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
int n, m, k, s, t;
vector<pair<int, int> > down[MAXN + 1];
vector<int> up[MAXN + 1];
long long dist[MAXN + 1][11];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d %d %d %d", &n, &m, &k, &s, &t);

    while (m--) {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);

        down[u].push_back({v, c});
        up[v].push_back(u);
    }

    memset(dist, -1, sizeof(dist));
    dist[s][k] = 0;

    for (int i = s; i <= n; i++) {
        if (dist[i][k] != -1) {
            for (auto [v, c] : down[i]) {
                dist[v][k] = max(dist[v][k], dist[i][k] + c);
            }

            if (k != 0) {
                for (auto v : up[i]) {
                    dist[v][k - 1] = max(dist[v][k - 1], dist[i][k]);
                }
            }
        }
    }

    for (int rest = k - 1; rest >= 0; rest--) {
        for (int i = 1; i <= n; i++) {
            if (dist[i][rest] != -1) {
                for (auto [v, c] : down[i]) {
                    dist[v][rest] = max(dist[v][rest], dist[i][rest] + c);
                }

                if (rest != 0) {
                    for (auto v : up[i]) {
                        dist[v][rest - 1] =
                            max(dist[v][rest - 1], dist[i][rest]);
                    }
                }
            }
        }
    }

    long long ret = -1;
    for (int i = 0; i <= k; i++) {
        ret = max(ret, dist[t][i]);
    }

    printf("%lld", ret);

    return 0;
}
