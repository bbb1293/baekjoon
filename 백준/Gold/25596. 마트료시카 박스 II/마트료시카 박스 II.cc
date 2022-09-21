#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3;
int n, m, k;
queue<int> q[2 * MAXN + 1];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d %d", &n, &m, &k);

    for (int i = 1; i <= n; i++) {
        int num;
        scanf("%d", &num);

        while (num--) {
            int u;
            scanf("%d", &u);
            q[i].push(u);
        }
    }

    int s = 0;
    for (int i = 1; i <= n && s <= k; i++) {
        while (q[i].size() > m) {
            s++;
            for (int j = 0; j < m; j++) {
                q[n + s].push(q[i].front());
                q[i].pop();
            }
            q[i].push(n + s);
        }
    }

    if (s > k) {
        printf("0");
    } else {
        printf("1\n%d\n", s);

        for (int i = 1; i <= n + s; i++) {
            printf("%d", q[i].size());
            while (!q[i].empty()) {
                printf(" %d", q[i].front());
                q[i].pop();
            }
            printf("\n");
        }
    }

    return 0;
}
