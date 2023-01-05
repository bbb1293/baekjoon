#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
int n;
int order[MAXN];
set<int> edges[MAXN + 1];

bool dfs(int cur, int idx) {
    int sz = edges[cur].size();
    if (cur != 1) {
        sz--;
    }

    bool ret = true;
    while (sz-- && ret) {
        if (!edges[cur].count(order[idx])) {
            ret = false;
        } else {
            ret &= dfs(order[idx], idx + 1);
        }
    }

    return ret;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        edges[u].insert(v);
        edges[v].insert(u);
    }

    for (int i = 0; i < n; i++) {
        int u;
        scanf("%d", &u);
        order[i] = u;
    }

    if (order[0] != 1) {
        printf("0");
        return 0;
    }

    if (dfs(1, 1)) {
        printf("1");
    } else {
        printf("0");
    }

    return 0;
}
