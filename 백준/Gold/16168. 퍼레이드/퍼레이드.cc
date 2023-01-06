#include <bits/stdc++.h>

using namespace std;

const int MAXV = 3e3;
int v, e;
vector<int> edges[MAXV + 1];
bool visited[MAXV + 1];

int dfs(int cur) {
    int ret = 1;
    for (auto v : edges[cur]) {
        if (!visited[v]) {
            visited[v] = true;
            ret += dfs(v);
        }
    }

    return ret;
}

bool is_possible() {
    int cnt = 0;
    for (int i = 1; i <= v; i++) {
        if (edges[i].size() & 1) {
            cnt++;
        }
    }

    if (cnt == 0 || cnt == 2) {
        return true;
    }

    return false;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &v, &e);

    while (e--) {
        int u, v;
        scanf("%d %d", &u, &v);

        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    for (int i = 1; i <= v; i++) {
        if (!edges[i].size()) {
            printf("NO");
            return 0;
        }
    }

    visited[1] = true;
    if (dfs(1) == v && is_possible()) {
        printf("YES");
    } else {
        printf("NO");
    }

    return 0;
}