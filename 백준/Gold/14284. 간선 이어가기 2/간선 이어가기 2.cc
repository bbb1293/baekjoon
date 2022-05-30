#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int v, cost;
};

const int MAXN = 5e3, INF = 987654321;
int n, m;
vector<Edge> edges[MAXN + 1];
bool used[MAXN + 1];
int cost[MAXN + 1];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);

    while (m--) {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);

        edges[u].push_back({v, c});
        edges[v].push_back({u, c});
    }

    int s, t;
    scanf("%d %d", &s, &t);

    for (int i = 1; i <= n; i++) {
        cost[i] = INF;
    }
    cost[s] = 0;

    while (true) {
        int target = -1;
        for (int i = 1; i <= n; i++) {
            if (!used[i] && (target == -1 || cost[i] < cost[target])) {
                target = i;
            }
        }

        if (cost[target] == INF) {
            break;
        }

        if (target == t) {
            printf("%d", cost[target]);
            return 0;
        }

        used[target] = true;

        for (auto [v, c] : edges[target]) {
            cost[v] = min(cost[v], cost[target] + c);
        }
    }

    return 0;
}
