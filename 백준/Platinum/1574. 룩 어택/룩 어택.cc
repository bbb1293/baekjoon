#include <bits/stdc++.h>

using namespace std;

int r, c, n;
int state[300][300];
vector<int> edges[300];
int p[300];
bool visited[300];

bool dfs(int cur) {
    if (visited[cur]) {
        return false;
    }
    visited[cur] = true;

    for (auto v : edges[cur]) {
        if (p[v] == -1 || dfs(p[v])) {
            p[v] = cur;
            return true;
        }
    }

    return false;
}

int kuhn() {
    memset(p, -1, sizeof(p));

    int ret = 0;
    for (int i = 0; i < r; i++) {
        memset(visited, 0, sizeof(visited));

        if (dfs(i)) {
            ret++;
        }
    }

    return ret;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d %d", &r, &c, &n);

    while (n--) {
        int x, y;
        scanf("%d %d", &y, &x);

        state[y - 1][x - 1] = 1;
    }

    for (int y = 0; y < r; y++) {
        for (int x = 0; x < c; x++) {
            if (state[y][x] == 0) {
                edges[y].push_back(x);
            }
        }
    }

    printf("%d", kuhn());

    return 0;
}