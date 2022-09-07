#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);

    printf("%d\n", n * (n - 1) / 2);

    int cur = 1;
    for (int i = 0; i < n; i++) {
        printf("%d ", cur);
        cur *= 2;
    }
    printf("\n");

    printf("%d\n", n - 1);
    for (int i = 1; i <= n; i++) {
        printf("%d ", i);
    }

    return 0;
}
