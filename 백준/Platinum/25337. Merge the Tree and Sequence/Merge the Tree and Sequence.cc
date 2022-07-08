#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int c, v, idx;

    const bool operator<(const Edge &a) const {
        if (c == a.c) {
            return v < a.v;
        }
        return (c < a.c);
    }
};

const int MAXN = 2e5;
int n;
vector<Edge> edges[MAXN + 1];
int a[MAXN + 1], b[MAXN + 1];
long long c[MAXN + 1];
bool used_edges[MAXN];

int dfs1(int color, int cur, int prev = -1) {
    int ret = a[cur];

    Edge tmp = {color, 0, 0};
    auto it = lower_bound(edges[cur].begin(), edges[cur].end(), tmp);
    while (it != edges[cur].end() && it->c == color) {
        if (it->v != prev) {
            ret += dfs1(color, it->v, cur);
        }
        it++;
    }

    return ret;
}

void dfs2(int num, int color, int cur, int prev = -1) {
    c[cur] += num;

    Edge tmp = {color, 0, 0};
    auto it = lower_bound(edges[cur].begin(), edges[cur].end(), tmp);
    while (it != edges[cur].end() && it->c == color) {
        if (it->v != prev) {
            dfs2(num, color, it->v, cur);
            used_edges[it->idx] = true;
        }
        it++;
    }
}

void set_c() {
    for (int i = 1; i <= n; i++) {
        int cur = 0;
        while (cur < edges[i].size()) {
            if (!used_edges[edges[i][cur].idx]) {
                int cnt = dfs1(edges[i][cur].c, i);
                dfs2(cnt, edges[i][cur].c, i);
            }
            cur++;
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);

    for (int i = 1; i < n; i++) {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);

        edges[u].push_back({c, v, i});
        edges[v].push_back({c, u, i});
    }

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        sort(edges[i].begin(), edges[i].end());
    }

    set_c();
    sort(c + 1, c + (n + 1));

    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
    }
    sort(b + 1, b + (n + 1));

    long long min_ret = 0, max_ret = 0;
    for (int i = 1; i <= n; i++) {
        max_ret += (b[i] * c[i]);
        min_ret += (b[i] * c[n - i + 1]);
    }

    printf("%lld\n%lld", min_ret, max_ret);

    return 0;
}
