#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9, MAXN = 100;
int n, m;
int p[2 * MAXN + 2], dist[2 * MAXN + 2];
int cap[2 * MAXN + 2][2 * MAXN + 2],
    cost[2 * MAXN + 2][2 * MAXN + 2];
vector<int> edges[2 * MAXN + 2];

void shortest_paths(int v0) {
    fill(dist, dist + n + m + 2, INF);
    dist[v0] = 0;

    memset(p, -1, sizeof(p));

    vector<bool> inq(n + m + 2, false);
    queue<int> q;
    q.push(v0);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;

        for (int v : edges[u]) {
            if (cap[u][v] > 0 &&
                dist[v] > dist[u] + cost[u][v]) {
                dist[v] = dist[u] + cost[u][v];
                p[v] = u;

                if (!inq[v]) {
                    inq[v] = true;
                    q.push(v);
                }
            }
        }
    }
}

void min_cost_flow(int s, int t) {
    int flow = 0, cost = 0;

    while (true) {
        shortest_paths(s);
        if (dist[t] == INF) {
            break;
        }

        int f = INF, cur = t;
        while (cur != s) {
            f = min(f, cap[p[cur]][cur]);
            cur = p[cur];
        }

        flow += f;
        cost += f * dist[t];
        cur = t;
        while (cur != s) {
            cap[p[cur]][cur] -= f;
            cap[cur][p[cur]] += f;
            cur = p[cur];
        }
    }

    printf("%d\n%d", flow, cost);
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &cap[0][i]);

        edges[0].push_back(i);
        edges[i].push_back(0);
    }

    for (int i = 1; i <= m; i++) {
        scanf("%d", &cap[n + i][n + m + 1]);

        edges[n + i].push_back(n + m + 1);
        edges[n + m + 1].push_back(n + i);
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &cap[j][n + i]);
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &cost[j][n + i]);
            cost[n + i][j] = -cost[j][n + i];

            edges[i + n].push_back(j);
            edges[j].push_back(n + i);
        }
    }

    min_cost_flow(0, n + m + 1);

    return 0;
}