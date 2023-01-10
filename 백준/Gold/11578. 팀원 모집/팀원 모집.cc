#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> prb[10];
bool check[11];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int cnt;
        scanf("%d", &cnt);

        while (cnt--) {
            int p;
            scanf("%d", &p);
            prb[i].push_back(p);
        }
    }

    int ret = 11;
    for (int s = 0; s < (1 << m); s++) {
        int cand = 0;
        for (int i = 0; i < m; i++) {
            if (s & (1 << i)) {
                for (auto p : prb[i]) {
                    check[p] = true;
                }
                cand++;
            }
        }

        for (int i = 1; i <= n; i++) {
            if (!check[i]) {
                cand = 11;
                break;
            }
        }

        memset(check, 0, sizeof(check));

        ret = min(ret, cand);
    }

    if (ret == 11) {
        ret = -1;
    }

    printf("%d", ret);

    return 0;
}