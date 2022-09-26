#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
int n, s, t, a[MAXN + 1];
long long dist[MAXN + 1], water[MAXN + 1];
vector<pair<int, int> > edges[MAXN + 1];
priority_queue<pair<pair<long long, long long>, int> > pq;

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    int m;
    scanf("%d", &m);

    while (m--) {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);

        edges[u].push_back({v, c});
        edges[v].push_back({u, c});
    }

    scanf("%d %d", &s, &t);

    memset(dist, -1, sizeof(dist));
    memset(water, -1, sizeof(water));

    pq.push({{0, a[s]}, s});
    dist[s] = 0;
    water[s] = a[s];

    while (!pq.empty()) {
        auto [cur_d, cur_w] = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dist[cur] < -cur_d ||
            (dist[cur] == -cur_d && cur_w < water[cur])) {
            continue;
        }

        for (auto [v, c] : edges[cur]) {
            long long next_d = -cur_d + c;
            long long next_w = cur_w + a[v];

            if (dist[v] == -1 ||
                (next_d < dist[v] || (next_d == dist[v] &&
                                      water[v] < next_w))) {
                dist[v] = next_d;
                water[v] = next_w;

                pq.push({{-next_d, next_w}, v});
            }
        }
    }

    if (dist[t] == -1) {
        printf("-1");
    } else {
        printf("%lld %lld", dist[t], water[t]);
    }

    return 0;
}