#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
int n, m, k, x;
int fenwick[MAXN + 1];

void update(int target) {
    for (int i = target; i <= n; i = (i | (i + 1))) {
        fenwick[i]++;
    }
}

int get_sum(int to) {
    int ret = 0;
    for (int i = to; i >= 0; i = (i & (i + 1)) - 1) {
        ret += fenwick[i];
    }

    return ret;
}

int get_query(int l, int r) {
    return get_sum(r) - get_sum(l - 1);
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d %d %d", &n, &m, &k, &x);

    for (int i = 1; i <= n; i++) {
        int add;
        scanf("%d", &add);

        x += add;
        if (x < k) {
            update(i);
        }
    }

    while (m--) {
        int l, r;
        scanf("%d %d", &l, &r);

        printf("%d\n", get_query(l, r - 1));
    }

    return 0;
}
