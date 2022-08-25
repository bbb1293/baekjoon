#include <bits/stdc++.h>

using namespace std;

struct City {
    int idx, x, y, z;
};

const int MAXN = 2e5;
int n, k;
City c[MAXN];
long long dist[MAXN * 2];
vector<pair<int, int> > edges[MAXN * 2];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        c[i] = {i, x, y, z};

        edges[n + (k - (z % k)) % k].push_back({i, z});
        edges[i].push_back({n + (z % k), z});
    }

    sort(c, c + n, [](const City &a, const City &b) { return a.x < b.x; });
    for (int i = 1; i < n; i++) {
        edges[c[i].idx].push_back({c[i - 1].idx, c[i].x - c[i - 1].x});
        edges[c[i - 1].idx].push_back({c[i].idx, c[i].x - c[i - 1].x});
    }

    sort(c, c + n, [](const City &a, const City &b) { return a.y < b.y; });
    for (int i = 1; i < n; i++) {
        edges[c[i].idx].push_back({c[i - 1].idx, c[i].y - c[i - 1].y});
        edges[c[i - 1].idx].push_back({c[i].idx, c[i].y - c[i - 1].y});
    }

    priority_queue<pair<long long, int> > pq;
    pq.push({0, 0});

    memset(dist, -1, sizeof(dist));
    dist[0] = 0;

    while (!pq.empty()) {
        auto [d, cur] = pq.top();
        pq.pop();

        d = -d;
        if (d > dist[cur]) {
            continue;
        }

        for (auto [v, c] : edges[cur]) {
            if (dist[v] == -1 || dist[cur] + c < dist[v]) {
                dist[v] = dist[cur] + c;
                pq.push({-dist[v], v});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%lld\n", dist[i]);
    }

    return 0;
}
