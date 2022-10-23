#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
int n, m;
vector<int> edges[2][MAXN];
bool visited[MAXN];

int get_cnt(int dir, int cur) {
    visited[cur] = true;

    int ret = 0;
    for (auto v : edges[dir][cur]) {
        if (!visited[v]) {
            ret += (1 + get_cnt(dir, v));
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

        edges[0][v].push_back(u);
        edges[1][u].push_back(v);
    }

    int th = n / 2;

    int ret = 0;
    for (int i = 1; i <= n; i++) {
        memset(visited, 0, sizeof(visited));
        int up_cnt = get_cnt(0, i),
            down_cnt = get_cnt(1, i);

        if (up_cnt > th || down_cnt > th) {
            ret++;
        }
    }

    printf("%d", ret);

    return 0;
}