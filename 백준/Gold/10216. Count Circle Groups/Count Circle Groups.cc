#include <bits/stdc++.h>

using namespace std;

int n;
int x[3000], y[3000], r[3000], used[3000];
vector<int> edges[3000];

bool connected(int i, int j) {
    int dist_2 = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
    int r_2 = (r[i] + r[j]) * (r[i] + r[j]);

    return dist_2 <= r_2;
}

void dfs(int cur) {
    used[cur] = true;

    for (auto v : edges[cur]) {
        if (!used[v]) {
            dfs(v);
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    while (t--) {
        memset(used, 0, sizeof(used));

        scanf("%d", &n);

        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &x[i], &y[i], &r[i]);
            edges[i].clear();
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (connected(i, j)) {
                    edges[i].push_back(j);
                    edges[j].push_back(i);
                }
            }
        }

        int ret = 0;
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                dfs(i);
                ret++;
            }
        }

        printf("%d\n", ret);
    }

    return 0;
}
