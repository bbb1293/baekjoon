#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3;
int n, m;
int p[MAXN + 1];

void init_p() {
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }
}

int get_p(int cur) {
    while (cur != p[cur]) {
        p[cur] = p[p[cur]];
        cur = p[cur];
    }

    return cur;
}

int main() {
    // freopen("input.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d %d", &n, &m);

        init_p();

        bool possible = (m == n - 1);
        while (m--) {
            int u, v;
            scanf("%d %d", &u, &v);

            int u_p = get_p(u);
            int v_p = get_p(v);

            if (u_p != v_p) {
                p[u_p] = v_p;
            } else {
                possible = false;
            }
        }

        if (!possible) {
            printf("graph\n");
        } else {
            printf("tree\n");
        }
    }

    return 0;
}