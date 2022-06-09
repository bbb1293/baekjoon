#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e4, INF = 987654321;
int n, m;
vector<pair<int, int> > edges[MAXN + 1];
int cost[MAXN + 1];
bool used[MAXN + 1];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);
    while (m--) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    }

    cost[1] = 0;
    for (int i = 2; i <= n; i++) {
        cost[i] = INF;
    }

    priority_queue<pair<int, int> > pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [cur_c, cur] = pq.top();
        pq.pop();

        if (used[cur]) {
            continue;
        }

        cur_c = -cur_c;

        if (cur == n) {
            printf("%d", cur_c);
            return 0;
        }

        used[cur] = true;

        for (auto [v, c] : edges[cur]) {
            if (!used[v] && cur_c + c < cost[v]) {
                cost[v] = cur_c + c;
                pq.push({-cost[v], v});
            }
        }
    }

    return 0;
}
