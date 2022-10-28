#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int v, t, w;
};

const int MAXN = 2e4;
int n, m;
int dist[MAXN + 1];
bool visited[MAXN + 1];
vector<Edge> edges[MAXN + 1];

void dijkstra() {
    memset(dist, -1, sizeof(dist));
    dist[1] = 0;

    priority_queue<pair<int, int> > pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [d, cur] = pq.top();
        pq.pop();

        if (visited[cur]) {
            continue;
        }
        visited[cur] = true;

        d = -d;

        for (auto [v, t, w] : edges[cur]) {
            if (visited[v]) {
                continue;
            }

            int new_d = ((d + w - 1) / w) * w + t;
            if (dist[v] == -1 || new_d < dist[v]) {
                dist[v] = new_d;
                pq.push({-new_d, v});
            }
        }
    }

    return;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);

    while (m--) {
        int u, v, t, w;
        scanf("%d %d %d %d", &u, &v, &t, &w);

        edges[u].push_back({v, t, w});
    }

    dijkstra();

    printf("%d", dist[n]);

    return 0;
}