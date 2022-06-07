#include <bits/stdc++.h>

using namespace std;

int n;
int num[400][400], a[400][401], b[400][401];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            scanf("%d", &num[y][x]);
        }
    }

    int ret = 0;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            int len = 1;
            while (y + len - 1 != n && x + len - 1 != n) {
                a[x][len] = a[x][len - 1] + num[y + len - 1][x + len - 1];
                len++;
            }

            len = 1;
            while (y + len - 1 != n && x - len + 1 >= 0) {
                b[x][len] = b[x][len - 1] + num[y + len - 1][x - len + 1];
                len++;
            }
        }

        for (int x = 0; x < n; x++) {
            int len = 2;
            while (x + len - 1 != n) {
                ret = max(ret, a[x][len] - b[x + len - 1][len]);
                len++;
            }
        }
    }

    printf("%d", ret);

    return 0;
}
