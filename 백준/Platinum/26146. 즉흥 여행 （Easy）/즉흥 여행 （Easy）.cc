#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5;
int n, m;
vector<int> edges[2][MAXN + 1];
bool used[MAXN + 1];

int dfs(int cur, int edge_sort) {
    int ret = 1;
    for (auto u : edges[edge_sort][cur]) {
        if (!used[u]) {
            used[u] = true;
            ret += dfs(u, edge_sort);
        }
    }

    return ret;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);

    while (m--) {
        int u, v;
        scanf("%d %d", &u, &v);

        edges[0][u].push_back(v);
        edges[1][v].push_back(u);
    }

    used[1] = true;
    if (dfs(1, 0) != n) {
        printf("No");
        return 0;
    }

    memset(used, 0, sizeof(used));
    used[1] = true;
    if (dfs(1, 1) != n) {
        printf("No");
        return 0;
    }

    printf("Yes");

    return 0;
}