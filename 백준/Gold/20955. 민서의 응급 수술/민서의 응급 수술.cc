#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
int n, m;
int p[MAXN + 1];

int get_p(int cur) {
    while (cur != p[cur]) {
        p[cur] = p[p[cur]];
        cur = p[cur];
    }

    return cur;
}

void init_p() {
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);

    init_p();

    int ret = 0;
    while (m--) {
        int u, v;
        scanf("%d %d", &u, &v);

        int u_p = get_p(u);
        int v_p = get_p(v);

        if (u_p == v_p) {
            ret++;
        } else {
            p[u_p] = v_p;
        }
    }

    int u_p = get_p(1);
    for (int i = 2; i <= n; i++) {
        int v_p = get_p(i);

        if (u_p != v_p) {
            p[v_p] = u_p;
            ret++;
        }
    }

    printf("%d", ret);

    return 0;
}