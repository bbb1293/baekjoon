#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
int n, k;
int way[MAXN + 1], p[MAXN + 1], in_deg[MAXN + 1];
vector<int> edges[MAXN + 1];

void dfs(int prev, int cur) {
    for (auto v : edges[cur]) {
        if (v != prev) {
            p[v] = cur;
            dfs(cur, v);
            in_deg[cur]++;
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &k);

    for (int i = 1; i < n; i++) {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    int root;
    while (k--) {
        scanf("%d", &root);
        way[root] = 1;
    }

    dfs(-1, root);

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (!in_deg[i]) {
            q.push(i);
        }
    }

    int ret = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (way[cur]) {
            ret++;
            way[p[cur]]++;
        }

        in_deg[p[cur]]--;

        if (!in_deg[p[cur]]) {
            q.push(p[cur]);
        }
    }

    printf("%d", ret);

    return 0;
}