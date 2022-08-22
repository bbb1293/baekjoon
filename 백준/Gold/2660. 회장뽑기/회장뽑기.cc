#include <bits/stdc++.h>

using namespace std;

const int MAXN = 50;
int n;
int dist[MAXN + 1];
bool visited[MAXN + 1];
vector<int> edges[MAXN + 1];

void set_dist(int cur) {
    memset(visited, 0, sizeof(visited));

    queue<pair<int, int> > q;
    q.push({cur, 0});
    visited[cur] = true;

    while (!q.empty()) {
        auto [u, cnt] = q.front();
        q.pop();

        for (auto v : edges[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push({v, cnt + 1});
            }
        }

        dist[cur] = cnt;
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);

    while (true) {
        int u, v;
        scanf("%d %d", &u, &v);

        if (u == -1) {
            break;
        }

        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    int min_dist = n;
    for (int i = 1; i <= n; i++) {
        set_dist(i);
        min_dist = min(min_dist, dist[i]);
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == min_dist) {
            cnt++;
        }
    }

    printf("%d %d\n", min_dist, cnt);
    for (int i = 1; i <= n; i++) {
        if (dist[i] == min_dist) {
            printf("%d ", i);
        }
    }

    return 0;
}
