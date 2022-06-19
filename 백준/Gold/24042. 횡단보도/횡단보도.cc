#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
const long long INF = 1e17;
int n, m;
bool used[MAXN + 1];
long long dist[MAXN + 1];
vector<pair<int, int> > edges[MAXN + 1];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        edges[u].push_back({v, i});
        edges[v].push_back({u, i});
    }

    for (int i = 2; i <= n; i++) {
        dist[i] = INF;
    }
    dist[1] = -1;

    priority_queue<pair<long long, int> > pq;
    pq.push({-1, 1});

    while (!pq.empty()) {
        int cur = pq.top().second;
        pq.pop();

        if (used[cur]) {
            continue;
        }
        used[cur] = true;

        for (auto [next_area, next_time] : edges[cur]) {
            if (!used[next_area]) {
                long long next_dist = (dist[cur] / m) * m + next_time;
                if (next_dist <= dist[cur]) {
                    next_dist += m;
                }

                if (next_dist < dist[next_area]) {
                    dist[next_area] = next_dist;
                    pq.push({-next_dist, next_area});
                }
            }
        }
    }

    printf("%lld", dist[n] + 1);

    return 0;
}
