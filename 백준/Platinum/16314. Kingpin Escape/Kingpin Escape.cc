#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
int n, root;
vector<int> edges[MAXN], leaves;

void dfs(int cur, int prev = -1) {
    if (edges[cur].size() == 1) {
        leaves.push_back(cur);
    }

    for (auto v : edges[cur]) {
        if (v != prev) {
            dfs(v, cur);
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &root);

    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    dfs(root);

    int cnt = leaves.size(), ret = (cnt + 1) / 2,
        half = cnt / 2;

    printf("%d\n", ret);
    for (int i = 0; i < ret; i++) {
        printf("%d %d\n", leaves[i],
               leaves[(i + half) % cnt]);
    }

    return 0;
}