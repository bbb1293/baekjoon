#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[100][100];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            scanf("%d", &a[y][x]);
        }
    }

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            int tmp;
            scanf("%d", &tmp);
            a[y][x] += tmp;
        }
    }

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            printf("%d ", a[y][x]);
        }
        printf("\n");
    }

    return 0;
}
