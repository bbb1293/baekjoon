#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5;
int c, p, x, l;
vector<int> edges[MAXN + 1];
int deg[MAXN + 1], cur_deg[MAXN + 1];
bool used[MAXN + 1];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d %d %d", &c, &p, &x, &l);

    while (p--) {
        int u, v;
        scanf("%d %d", &u, &v);

        edges[u].push_back(v);
        edges[v].push_back(u);

        deg[u]++;
        cur_deg[u]++;
        deg[v]++;
        cur_deg[v]++;
    }

    queue<int> q;
    q.push(l);
    used[l] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto v : edges[cur]) {
            cur_deg[v]--;

            if (!used[v] && cur_deg[v] <= deg[v] / 2) {
                q.push(v);
                used[v] = true;
            }
        }
    }

    if (used[x]) {
        printf("leave");
    } else {
        printf("stay");
    }

    return 0;
}