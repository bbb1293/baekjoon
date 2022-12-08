#include <bits/stdc++.h>

using namespace std;

struct Present {
    int idx, a, b;

    const bool operator<(const Present &a) const {
        if (this->a != a.a) {
            return this->a > a.a;
        }

        return idx < a.idx;
    }
};

struct Answer {
    char op;
    int i, x;
};

const int MAXN = 2e5;
int n, m, ans_num = 0;
int b[MAXN];
Present p[MAXN];
Answer ans[2 * MAXN];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i].a);
        p[i].idx = i;
    }

    int base_idx = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i].b);
        b[i] = p[i].b;

        if (p[base_idx].b < p[i].b) {
            base_idx = i;
        }
    }

    sort(p, p + n);

    for (int i = 0; i < n; i++) {
        if (p[i].idx != base_idx && p[i].a) {
            ans[ans_num++] = {'+', base_idx + 1, p[i].a};
        }
    }

    for (int i = 0; i < n; i++) {
        if (i != base_idx && b[i]) {
            ans[ans_num++] = {'+', i + 1, b[i]};
        }
    }

    printf("%d\n", ans_num);
    for (int i = 0; i < ans_num; i++) {
        printf("%c %d %d\n", ans[i].op, ans[i].i, ans[i].x);
    }

    return 0;
}
