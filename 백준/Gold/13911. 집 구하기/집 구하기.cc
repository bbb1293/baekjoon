#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e4;
int v, e;
vector<pair<int, int> > edges[MAXN + 1];
long long dist1[MAXN + 1], dist2[MAXN + 1];
long long x, y;

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &v, &e);

    while (e--) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }

    priority_queue<pair<long long, int> > pq;

    int m;
    scanf("%d %lld", &m, &x);

    memset(dist1, -1, sizeof(dist1));
    while (m--) {
        int idx;
        scanf("%d", &idx);

        pq.push({0ll, idx});
        dist1[idx] = 0;
    }

    while (!pq.empty()) {
        auto [cur_dist, cur] = pq.top();
        pq.pop();

        if (dist1[cur] != -cur_dist) {
            continue;
        }
        cur_dist = -cur_dist;

        for (auto [v, c] : edges[cur]) {
            if ((dist1[v] == -1 ||
                 (cur_dist + c) < dist1[v]) &&
                (cur_dist + c <= x)) {
                dist1[v] = cur_dist + c;
                pq.push({-(cur_dist + c), v});
            }
        }
    }

    int s;
    scanf("%d %lld", &s, &y);

    memset(dist2, -1, sizeof(dist2));
    while (s--) {
        int idx;
        scanf("%d", &idx);

        pq.push({0ll, idx});
        dist2[idx] = 0;
    }

    while (!pq.empty()) {
        auto [cur_dist, cur] = pq.top();
        pq.pop();

        if (dist2[cur] != -cur_dist) {
            continue;
        }
        cur_dist = -cur_dist;

        for (auto [v, c] : edges[cur]) {
            if ((dist2[v] == -1 ||
                 (cur_dist + c) < dist2[v]) &&
                (cur_dist + c <= y)) {
                dist2[v] = cur_dist + c;
                pq.push({-(cur_dist + c), v});
            }
        }
    }

    long long ret = -1;
    for (int i = 1; i <= v; i++) {
        if (dist1[i] > 0 && dist2[i] > 0 &&
            (ret == -1 || dist1[i] + dist2[i] < ret)) {
            ret = dist1[i] + dist2[i];
        }
    }

    printf("%lld", ret);

    return 0;
}