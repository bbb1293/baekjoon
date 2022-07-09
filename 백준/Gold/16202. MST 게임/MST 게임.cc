#include <bits/stdc++.h>

using namespace std;

int n, m, k;
bool used[10001];
int p[1001];
pair<int, int> edge[10001];

void init_p() {
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }
}

int get_p(int a) {
    if (a == p[a]) {
        return a;
    }

    return p[a] = get_p(p[a]);
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &edge[i].first, &edge[i].second);
    }

    for (int i = 0; i < k; i++) {
        used[i] = true;

        init_p();

        int cnt = 0, cost = 0;
        for (int j = 1; j <= m; j++) {
            if (used[j]) {
                continue;
            }

            auto [u, v] = edge[j];
            int p_u = get_p(u);
            int p_v = get_p(v);

            if (p_u != p_v) {
                cnt++;
                p[p_u] = p_v;
                cost += j;
            }
        }

        if (cnt != n - 1) {
            cost = 0;
        }

        printf("%d ", cost);
    }

    return 0;
}
