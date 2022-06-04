#include <bits/stdc++.h>

using namespace std;

const int MAXN = 328000;
int n, s, p;
int h[MAXN + 1];
vector<int> edges[MAXN + 1];

void dfs(int cur, int prev = -1) {
    for (auto v : edges[cur]) {
        if (v != prev) {
            h[v] = h[cur] + 1;
            dfs(v, cur);
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d %d", &n, &s, &p);

    for (int i = 1; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    dfs(p);

    int a = min(h[1], h[2]), b = max(h[1], h[2]);
    for (int i = 3; i <= s; i++) {
        if (h[i] <= a) {
            b = a;
            a = h[i];
        } else if (h[i] <= b) {
            b = h[i];
        }
    }

    printf("%d", n - a - b - 1);

    return 0;
}
