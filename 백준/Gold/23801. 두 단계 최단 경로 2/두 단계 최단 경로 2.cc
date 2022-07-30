#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
int n, m, x, z;
vector<pair<int, int> > edges[MAXN + 1];
long long dist[MAXN + 1][2];
set<int> mids;

struct State {
    long long cost;
    int cur, visited;

    const bool operator<(const State &a) const { return cost > a.cost; }
};

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);

    while (m--) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }

    scanf("%d %d", &x, &z);

    int p;
    scanf("%d", &p);

    while (p--) {
        int y;
        scanf("%d", &y);
        mids.insert(y);
    }

    memset(dist, -1, sizeof(dist));
    dist[x][0] = 0;

    priority_queue<State> pq;
    pq.push({0, x, 0});

    while (!pq.empty()) {
        auto [cost, cur, visited] = pq.top();
        pq.pop();

        if (dist[cur][visited] != cost) {
            continue;
        }

        for (auto [v, w] : edges[cur]) {
            int next_visited = visited | mids.count(v);

            if (dist[v][next_visited] == -1 ||
                cost + w < dist[v][next_visited]) {
                dist[v][next_visited] = cost + w;
                pq.push({cost + w, v, next_visited});
            }
        }
    }

    printf("%lld", dist[z][1]);

    return 0;
}
