#include <bits/stdc++.h>

using namespace std;

struct Info {
    int op, a, b;
};

const int MAXN = 2e5;
int n, q;
int e[MAXN + 1], p[MAXN + 1];
vector<Info> info;

void init_p() {
    e[1] = 1;
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

    scanf("%d %d", &n, &q);
    for (int i = 2; i <= n; i++) {
        scanf("%d", &e[i]);
    }

    for (int i = 0; i < n + q - 1; i++) {
        int op, a, b;
        scanf("%d", &op);

        if (op == 0) {
            scanf("%d", &a);
            info.push_back({op, a, 0});
        } else {
            scanf("%d %d", &a, &b);
            info.push_back({op, a, b});
        }
    }

    init_p();

    vector<int> ret;

    for (int i = info.size() - 1; i >= 0; i--) {
        auto [op, a, b] = info[i];
        if (op == 0) {
            p[a] = get_p(e[a]);
        } else {
            int p_a = get_p(a), p_b = get_p(b);
            if (p_a == p_b) {
                ret.push_back(1);
            } else {
                ret.push_back(0);
            }
        }
    }

    reverse(ret.begin(), ret.end());

    for (auto r : ret) {
        if (r == 1) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
