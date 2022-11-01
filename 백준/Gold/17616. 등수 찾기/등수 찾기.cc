#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
int n, m, x;
bool visited[MAXN + 1];
vector<int> edges[2][MAXN + 1];

int get_size(int cur, int idx) {
    visited[cur] = true;
    int ret = 1;
    for (auto v : edges[idx][cur]) {
        if (!visited[v]) {
            ret += get_size(v, idx);
        }
    }

    return ret;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d %d", &n, &m, &x);

    while (m--) {
        int u, v;
        scanf("%d %d", &u, &v);

        edges[0][v].push_back(u);
        edges[1][u].push_back(v);
    }

    int upper = get_size(x, 0) - 1;
    int lower = get_size(x, 1) - 1;

    printf("%d %d", upper + 1, n - lower);

    return 0;
}
