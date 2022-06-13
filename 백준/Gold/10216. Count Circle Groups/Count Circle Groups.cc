#include <bits/stdc++.h>

using namespace std;

int n;
int x[3000], y[3000], r[3000], p[3000];

bool connected(int i, int j) {
    int dist_2 = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
    int r_2 = (r[i] + r[j]) * (r[i] + r[j]);

    return dist_2 <= r_2;
}

void init_p() {
    for (int i = 0; i < n; i++) {
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

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        init_p();

        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &x[i], &y[i], &r[i]);
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (connected(i, j)) {
                    int p_i = get_p(i);
                    int p_j = get_p(j);

                    p[p_i] = p_j;
                }
            }
        }

        int ret = 0;
        for (int i = 0; i < n; i++) {
            if (get_p(i) == i) {
                ret++;
            }
        }

        printf("%d\n", ret);
    }

    return 0;
}
