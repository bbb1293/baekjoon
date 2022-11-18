#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9, MAXN = 1000;
int n, m;
int p[MAXN + 1], dist[MAXN + 1];
int cost[MAXN + 1][MAXN + 1];
bool inq[MAXN + 1];
vector<int> edges[MAXN + 1];

void shortest_paths(int v0) {
    fill(dist, dist + n + 1, INF);
    fill(p, p + n + 1, -1);
    fill(inq, inq + n + 1, false);
    dist[v0] = 0;

    queue<int> q;
    q.push(v0);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;

        for (int v : edges[u]) {
            if (dist[v] > dist[u] + cost[u][v]) {
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
    shortest_paths(s);

    int ret = dist[t];

    int cur = t;
    while (cur != s) {
        cost[p[cur]][cur] = -cost[p[cur]][cur];
        cost[cur][p[cur]] = INF;

        cur = p[cur];
    }

    shortest_paths(t);

    ret += dist[s];

    printf("%d", ret);
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);

    while (m--) {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);

        edges[u].push_back(v);
        edges[v].push_back(u);

        cost[u][v] = c;
        cost[v][u] = c;
    }

    min_cost_flow(1, n);

    return 0;
}