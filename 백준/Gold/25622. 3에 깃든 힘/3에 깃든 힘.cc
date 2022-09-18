#include <bits/stdc++.h>

using namespace std;

const int MAXN = 333333;
int n;
int deg[MAXN + 1];
bool used[MAXN + 1];
vector<int> edges[MAXN + 1], group[MAXN + 1];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);

    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        edges[u].push_back(v);
        edges[v].push_back(u);

        deg[u]++;
        deg[v]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 1) {
            q.push(i);
        }
        group[i].push_back(i);
    }

    bool possible = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        used[cur] = true;
        if (group[cur].size() > 3) {
            possible = false;
            break;
        }

        for (auto v : edges[cur]) {
            deg[v]--;
            if (group[cur].size() != 3 && !used[v]) {
                for (auto g : group[cur]) {
                    group[v].push_back(g);
                }
            }

            if (deg[v] == 1) {
                q.push(v);
            }
        }
    }

    if (possible) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (group[i].size() == 3) {
                cnt++;
            }
        }

        if (cnt == n / 3) {
            printf("S\n");
            for (int i = 1; i <= n; i++) {
                if (group[i].size() == 3) {
                    for (auto g : group[i]) {
                        printf("%d ", g);
                    }
                    printf("\n");
                }
            }
        } else {
            printf("U");
        }

    } else {
        printf("U");
    }

    return 0;
}
