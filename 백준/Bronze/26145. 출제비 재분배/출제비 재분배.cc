#include <bits/stdc++.h>

using namespace std;

int n, m;
int s[2001];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &s[i]);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n + m; j++) {
            int tmp;
            scanf("%d", &tmp);
            s[j] += tmp;
            s[i] -= tmp;
        }
    }

    for (int i = 1; i <= n + m; i++) {
        printf("%d ", s[i]);
    }

    return 0;
}