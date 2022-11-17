#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9, MAXN = 1000;
int v, e;
int p[2 * MAXN + 1], dist[2 * MAXN + 1];
int cap[2 * MAXN + 1][2 * MAXN + 1],
    cost[2 * MAXN + 1][2 * MAXN + 1];
vector<int> edges[2 * MAXN + 1];

void shortest_paths(int v0) {
    fill(dist, dist + 2 * v + 1, INF);
    dist[v0] = 0;

    memset(p, -1, sizeof(p));

    vector<bool> inq(2 * v + 1, false);
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

    printf("%d\n", cost);
}

int main() {
    // freopen("input.txt", "r", stdin);

    while (scanf("%d %d", &v, &e) > 0) {
        for (int i = 0; i <= 2 * v; i++) {
            edges[i].clear();
        }

        for (int i = 1; i <= v; i++) {
            edges[i].push_back(v + i);
            edges[v + i].push_back(i);

            cap[i][v + i] = 1;
            cap[v + i][i] = 0;

            cost[i][v + i] = cost[v + i][i] = 0;
        }

        edges[0].push_back(1);
        edges[1].push_back(0);

        cap[0][1] = 2;
        cap[1][0] = 0;

        cap[1][v + 1] = 2;

        while (e--) {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);

            edges[a + v].push_back(b);
            edges[b].push_back(a + v);

            cap[a + v][b] = 1;
            cap[b][a + v] = 0;

            cost[a + v][b] = c;
            cost[b][a + v] = -c;
        }

        min_cost_flow(0, v);
    }

    return 0;
}