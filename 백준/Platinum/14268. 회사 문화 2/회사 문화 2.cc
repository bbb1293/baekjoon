#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
int n, m, cnt = 0;
int fenwick[MAXN + 1];
int in[MAXN + 1], out[MAXN + 1];
vector<int> edges[MAXN + 1];

void update(int x, int val) {
    for (; x <= n; x += (x & -x)) {
        fenwick[x] += val;
    }
}

int query(int x) {
    int ret = 0;
    for (; x > 0; x -= (x & -x)) {
        ret += fenwick[x];
    }

    return ret;
}

void dfs(int cur = 1) {
    in[cur] = ++cnt;

    for (auto v : edges[cur]) {
        dfs(v);
    }
    out[cur] = cnt;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        int p;
        scanf("%d", &p);

        if (i == 1) {
            continue;
        }

        edges[p].push_back(i);
    }

    dfs();

    while (m--) {
        int op, x, y;
        scanf("%d %d", &op, &x);

        if (op == 1) {
            scanf("%d", &y);
            update(in[x], y);
            update(out[x] + 1, -y);
        } else {
            printf("%d\n", query(in[x]));
        }
    }

    return 0;
}
