#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
int n, m;
int w[MAXN + 1];
vector<int> children[MAXN + 1];

void dfs(int cur) {
    for (auto v : children[cur]) {
        w[v] += w[cur];

        dfs(v);
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        int p;
        scanf("%d", &p);

        if (p == -1) {
            continue;
        }

        children[p].push_back(i);
    }

    while (m--) {
        int i, j;
        scanf("%d %d", &i, &j);

        w[i] += j;
    }

    dfs(1);

    for (int i = 1; i <= n; i++) {
        printf("%d ", w[i]);
    }

    return 0;
}
