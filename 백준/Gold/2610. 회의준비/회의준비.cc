#include <bits/stdc++.h>

using namespace std;

const int MAXN = 101;
int n, m;
vector<int> edge[MAXN];
bool visited[MAXN];
int dist[MAXN];

void set_dist(int cur) {
    queue<pair<int, int> > q;
    q.push({0, cur});
    visited[cur] = true;

    while (!q.empty()) {
        auto [cnt, v] = q.front();
        q.pop();

        for (auto u : edge[v]) {
            if (!visited[u]) {
                visited[u] = true;
                q.push({cnt + 1, u});
                dist[cur] = cnt + 1;
            }
        }
    }
}

int get_ans(int cur) {
    int ret = cur;
    visited[cur] = true;

    queue<int> q;
    q.push(cur);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto v : edge[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);

                if (dist[ret] > dist[v]) {
                    ret = v;
                }
            }
        }
    }

    return ret;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    scanf("%d", &m);

    while (m--) {
        int u, v;
        scanf("%d %d", &u, &v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        set_dist(i);
        memset(visited, 0, sizeof(visited));
    }

    vector<int> ret;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            ret.push_back(get_ans(i));
        }
    }

    sort(ret.begin(), ret.end());

    printf("%d\n", ret.size());
    for (auto r : ret) {
        printf("%d\n", r);
    }

    return 0;
}
