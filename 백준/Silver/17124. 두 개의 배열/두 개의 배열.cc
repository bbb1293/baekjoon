#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;
int n, m;
int a[MAXN], b[MAXN];

int main() {
    // freopen("input.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d %d", &n, &m);

        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        for (int i = 0; i < m; i++) {
            scanf("%d", &b[i]);
        }

        sort(a, a + n);
        sort(b, b + m);

        long long ret = 0;
        int cur = 0;
        for (int i = 0; i < n; i++) {
            while (cur + 1 < m && abs(b[cur + 1] - a[i]) <
                                      abs(b[cur] - a[i])) {
                cur++;
            }

            ret += b[cur];
        }

        printf("%lld\n", ret);
    }

    return 0;
}