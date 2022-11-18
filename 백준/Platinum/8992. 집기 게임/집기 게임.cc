#include <bits/stdc++.h>

using namespace std;

struct Segment {
    int from, to, fixed, w;
};

const int INF = 1e9, MAXN = 200;
int n, m;
Segment h[MAXN + 1], v[MAXN + 1];
int p[2 * MAXN + 2], dist[2 * MAXN + 2];
int cap[2 * MAXN + 2][2 * MAXN + 2],
    cost[2 * MAXN + 2][2 * MAXN + 2];
bool inq[2 * MAXN + 2];
vector<int> edges[2 * MAXN + 2];

void shortest_paths(int v0) {
    fill(dist, dist + n + m + 2, INF);
    fill(p, p + n + m + 2, -1);
    fill(inq, inq + n + m + 2, false);
    dist[v0] = 0;

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

    printf("%d %d\n", flow, -cost);
}

bool is_cross(int i, int j) {
    return (h[i].from <= v[j].fixed) &&
           (v[j].fixed <= h[i].to) &&
           (v[j].from <= h[i].fixed) &&
           (h[i].fixed <= v[j].to);
}

int main() {
    // freopen("input.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d %d", &n, &m);

        for (int i = 0; i <= n + m + 1; i++) {
            edges[i].clear();
        }

        for (int i = 1; i <= n; i++) {
            scanf("%d %d %d %d %d", &h[i].from, &h[i].fixed,
                  &h[i].to, &h[i].fixed, &h[i].w);

            if (h[i].to < h[i].from) {
                swap(h[i].to, h[i].from);
            }

            edges[0].push_back(i);
            edges[i].push_back(0);

            cap[0][i] = 1;
            cap[i][0] = 0;

            cost[0][i] = 0;
            cost[i][0] = 0;
        }

        for (int i = 1; i <= m; i++) {
            scanf("%d %d %d %d %d", &v[i].fixed, &v[i].from,
                  &v[i].fixed, &v[i].to, &v[i].w);

            if (v[i].to < v[i].from) {
                swap(v[i].to, v[i].from);
            }

            edges[n + i].push_back(n + m + 1);
            edges[n + m + 1].push_back(n + i);

            cap[n + i][n + m + 1] = 1;
            cap[n + m + 1][n + i] = 0;

            cost[n + i][n + m + 1] = 0;
            cost[n + m + 1][n + i] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (is_cross(i, j)) {
                    edges[i].push_back(n + j);
                    edges[n + j].push_back(i);

                    cap[i][n + j] = 1;
                    cap[n + j][i] = 0;

                    cost[i][n + j] = -h[i].w * v[j].w;
                    cost[n + j][i] = h[i].w * v[j].w;
                } else {
                    cap[i][n + j] = 0;
                    cap[n + j][i] = 0;
                }
            }
        }
        min_cost_flow(0, n + m + 1);
    }

    return 0;
}