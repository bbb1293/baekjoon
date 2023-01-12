#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> edges[101], ret[2];
bool visited[101];

void set_team(int cur, int cur_team) {
    ret[cur_team].push_back(cur);
    visited[cur] = true;

    for (auto v : edges[cur]) {
        if (!visited[v]) {
            set_team(v, cur_team ^ 1);
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        int cnt;
        scanf("%d", &cnt);

        while (cnt--) {
            int u;
            scanf("%d", &u);

            edges[i].push_back(u);
            edges[u].push_back(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            set_team(i, 0);
        }
    }

    sort(ret[0].begin(), ret[0].end());
    sort(ret[1].begin(), ret[1].end());

    printf("%d\n", ret[0].size());
    for (auto r : ret[0]) {
        printf("%d ", r);
    }

    printf("\n%d\n", ret[1].size());
    for (auto r : ret[1]) {
        printf("%d ", r);
    }

    return 0;
}