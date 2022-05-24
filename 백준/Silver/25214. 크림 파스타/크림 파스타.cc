#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5;
int n;
int a[MAXN];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int ret = 0, cur_min = a[0];
    printf("%d ", ret);
    for (int i = 1; i < n; i++) {
        ret = max(ret, a[i] - cur_min);
        cur_min = min(cur_min, a[i]);
        printf("%d ", ret);
    }

    return 0;
}
