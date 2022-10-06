#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3;
int n, m, k;
vector<int> edges[2 * MAXN + 1];
bool used[2 * MAXN + 1];
int connected[MAXN + 1];

bool kuhn(int cur) {
    if (used[cur]) {
        return false;
    }
    used[cur] = true;

    for (auto v : edges[cur]) {
        if (connected[v] == -1 || kuhn(connected[v])) {
            connected[v] = cur;
            return true;
        }
    }

    return false;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d %d", &n, &m, &k);

    for (int i = 1; i <= n; i++) {
        int cnt;
        scanf("%d", &cnt);

        while (cnt--) {
            int cur;
            scanf("%d", &cur);

            edges[i].push_back(cur);
            edges[n + i].push_back(cur);
        }
    }

    memset(connected, -1, sizeof(connected));
    for (int i = 1; i <= 2 * n; i++) {
        memset(used, 0, sizeof(used));
        kuhn(i);
    }

    int ret = 0;
    for (int i = 1; i <= m; i++) {
        if (connected[i] != -1) {
            if (connected[i] <= n) {
                ret++;
            } else {
                if (k) {
                    k--;
                    ret++;
                }
            }
        }
    }

    printf("%d", ret);

    return 0;
}