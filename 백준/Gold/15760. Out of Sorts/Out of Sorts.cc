#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
int n, a[MAXN];
int fenwick[MAXN];
map<int, int> m;

void update(int cur) {
    for (int i = cur; i < n; i = (i | (i + 1))) {
        fenwick[i]++;
    }
}

int get_cnt(int to) {
    int cnt = 0;
    for (int i = to; i >= 0; i = (i & (i + 1)) - 1) {
        cnt += fenwick[i];
    }

    return cnt;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        m[a[i]] = 0;
    }

    int idx = 0;
    for (auto &p : m) {
        p.second = idx++;
    }

    int ret = 1;
    for (int i = 0; i < n; i++) {
        ret =
            max(ret, get_cnt(n - 1) - get_cnt(m[a[i]]) + 1);
        update(m[a[i]]);
    }

    printf("%d", ret);

    return 0;
}