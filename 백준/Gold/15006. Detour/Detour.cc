#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int v, cost, idx;
};

const int MAXN = 2e5, MAXM = 2e6;
int n, m;
vector<Edge> edges[MAXN];
int prev_path[MAXN];
bool block[MAXM * 2];
long long dist[MAXN], update[MAXN];
priority_queue<pair<long long, int> > pq;

void dfs(int cur) {
    for (auto [v, c, idx] : edges[cur]) {
        if (prev_path[v] != -1 || v == prev_path[cur] ||
            block[idx]) {
            continue;
        }
        prev_path[v] = cur;
        dfs(v);
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);

        edges[u].push_back({v, c, i});
        edges[v].push_back({u, c, i + m});
    }

    memset(dist, -1, sizeof(dist));
    pq.push({0, 1});
    dist[1] = 0;

    while (!pq.empty()) {
        auto [cur_dist, cur] = pq.top();
        pq.pop();

        if (dist[cur] < -cur_dist) {
            continue;
        }

        if (cur != 1) {
            block[update[cur]] = true;
        }

        for (auto [v, c, idx] : edges[cur]) {
            long long next_dist = -cur_dist + c;

            if (dist[v] == -1 || next_dist < dist[v]) {
                dist[v] = next_dist;

                if (idx < m) {
                    update[v] = idx + m;
                } else {
                    update[v] = idx - m;
                }

                pq.push({-next_dist, v});
            }
        }
    }

    memset(prev_path, -1, sizeof(prev_path));
    dfs(0);

    if (prev_path[1] == -1) {
        printf("impossible");
    } else {
        vector<int> path;

        int cur = 1;
        while (cur != 0) {
            path.push_back(cur);
            cur = prev_path[cur];
        }
        path.push_back(0);

        printf("%d", path.size());

        for (int i = path.size() - 1; i >= 0; i--) {
            printf(" %d", path[i]);
        }
    }

    return 0;
}