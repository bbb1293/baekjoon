#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5;
int n;
int color[MAXN + 1];
vector<int> edges[MAXN + 1];

int coloring(int prev, int cur) {
    int ret = 0;
    if (color[prev] != color[cur]) {
        ret++;
    }

    for (auto v : edges[cur]) {
        if (v != prev) {
            ret += coloring(cur, v);
        }
    }

    return ret;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &color[i]);
    }

    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    printf("%d", coloring(0, 1));

    return 0;
}
