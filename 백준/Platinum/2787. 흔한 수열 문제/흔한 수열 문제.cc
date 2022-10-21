#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200;
int n, m;
int up[MAXN + 1], down[MAXN + 1];
int p[MAXN + 1], num[MAXN + 1];
bool visited[MAXN + 1];
int edges[MAXN + 1][MAXN + 1];

void init() {
    for (int i = 1; i <= n; i++) {
        up[i] = n;
        down[i] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            edges[i][j] = 1;
        }
    }
}

bool kuhn(int cur) {
    if (visited[cur]) {
        return false;
    }
    visited[cur] = true;

    for (int i = 1; i <= n; i++) {
        if (edges[cur][i]) {
            if (p[i] == -1 || kuhn(p[i])) {
                p[i] = cur;
                return true;
            }
        }
    }

    return false;
}

int match() {
    memset(p, -1, sizeof(p));

    int ret = 0;
    for (int i = 1; i <= n; i++) {
        memset(visited, 0, sizeof(visited));

        if (kuhn(i)) {
            ret++;
        }
    }

    return ret;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);

    init();

    while (m--) {
        int op, x, y, v;
        scanf("%d %d %d %d", &op, &x, &y, &v);

        for (int i = 1; i <= n; i++) {
            if (i < x || y < i) {
                edges[i][v] = 0;
            } else if (op == 1) {
                up[i] = min(up[i], v);
            } else {
                down[i] = max(down[i], v);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < down[i]; j++) {
            edges[i][j] = 0;
        }
        for (int j = up[i] + 1; j <= n; j++) {
            edges[i][j] = 0;
        }
    }

    if (match() == n) {
        for (int i = 1; i <= n; i++) {
            num[p[i]] = i;
        }

        for (int i = 1; i <= n; i++) {
            printf("%d ", num[i]);
        }
    } else {
        printf("-1");
    }

    return 0;
}