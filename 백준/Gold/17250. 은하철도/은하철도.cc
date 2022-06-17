#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
int n, m;
int p[MAXN + 1];
long long cnt[MAXN + 1];

void init_p() {
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }
}

int get_p(int cur) {
    if (cur == p[cur]) {
        return cur;
    }

    return p[cur] = get_p(p[cur]);
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%lld", &cnt[i]);
    }

    init_p();

    while (m--) {
        int u, v;
        scanf("%d %d", &u, &v);

        int u_p = get_p(u), v_p = get_p(v);

        if (u_p != v_p) {
            cnt[u_p] += cnt[v_p];
            p[v_p] = u_p;
        }

        printf("%lld\n", cnt[u_p]);
    }

    return 0;
}
