#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
int n;
int l[MAXN + 1], r[MAXN + 1];

int get_last(int cur) {
    if (r[cur] == -1) {
        return 0;
    }

    return get_last(r[cur]) + 1;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int cur;
        scanf("%d", &cur);
        scanf("%d %d", &l[cur], &r[cur]);
    }

    int ret = (n - 1) * 2 - get_last(1);
    printf("%d", ret);

    return 0;
}
