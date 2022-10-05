#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5;
int c, p, x, l;
vector<int> edges[MAXN + 1];
int deg[MAXN + 1];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d %d %d", &c, &p, &x, &l);

    while (p--) {
        int u, v;
        scanf("%d %d", &u, &v);

        edges[u].push_back(v);
        edges[v].push_back(u);

        deg[u]++;
        deg[v]++;
    }

    for (int i = 1; i <= c; i++) {
        deg[i] = (deg[i] + 1) / 2;
    }

    queue<int> q;
    q.push(l);
    deg[l] = -1;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto v : edges[cur]) {
            deg[v]--;

            if (deg[v] == 0) {
                deg[v] = -1;
                q.push(v);
            }
        }
    }

    if (deg[x] <= 0) {
        printf("leave");
    } else {
        printf("stay");
    }

    return 0;
}