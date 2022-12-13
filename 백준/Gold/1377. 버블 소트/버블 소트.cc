#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e5, MAXA = 1e6;
int n;
int fenwick[MAXA + 1];

void update(int cur) {
    for (int i = cur; i <= MAXA; i = (i | (i + 1))) {
        fenwick[i]++;
    }
}

int get_cnt(int cur) {
    int cnt = 0;
    for (int i = cur; i >= 0; i = (i & (i + 1)) - 1) {
        cnt += fenwick[i];
    }

    return cnt;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);

    int ret = 1;
    for (int i = 0; i < n; i++) {
        int cur;
        scanf("%d", &cur);

        ret = max(ret, i - get_cnt(cur) + 1);
        update(cur);
    }

    printf("%d", ret);

    return 0;
}