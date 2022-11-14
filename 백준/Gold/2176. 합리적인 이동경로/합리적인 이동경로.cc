#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3;
int n, m;
int dist[MAXN + 1];
long long dp[MAXN + 1];
bool used[MAXN + 1];
vector<pair<int, int> > edges[MAXN + 1];

long long get_dp(int cur) {
    if (cur == 2) {
        return 1;
    }

    long long &ret = dp[cur];
    if (ret != -1) {
        return ret;
    }

    ret = 0;
    for (auto [v, c] : edges[cur]) {
        if (dist[cur] > dist[v]) {
            ret += get_dp(v);
        }
    }

    return ret;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);

    while (m--) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    }

    memset(dist, -1, sizeof(dist));
    dist[2] = 0;

    priority_queue<pair<int, int> > pq;
    pq.push({0, 2});

    while (!pq.empty()) {
        auto [cur_dist, cur] = pq.top();
        pq.pop();

        if (used[cur]) {
            continue;
        }
        used[cur] = true;

        cur_dist = -cur_dist;

        for (auto [v, c] : edges[cur]) {
            if (dist[v] == -1 || cur_dist + c < dist[v]) {
                dist[v] = cur_dist + c;
                pq.push({-dist[v], v});
            }
        }
    }

    memset(dp, -1, sizeof(dp));
    printf("%lld", get_dp(1));

    return 0;
}