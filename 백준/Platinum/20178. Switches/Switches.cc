#include <bits/stdc++.h>

using namespace std;

int n;
int num[500][500], ret[500][500];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            scanf("%d", &num[y][x]);
        }
        ret[y][y] = 1;
    }

    bool possible = true;
    for (int i = 0; i < n; i++) {
        int target = -1;
        for (int y = i; y < n; y++) {
            if (num[y][i] == 1) {
                target = y;
                break;
            }
        }

        if (target == -1) {
            possible = false;
            break;
        }

        for (int x = 0; x < n; x++) {
            swap(num[target][x], num[i][x]);
            swap(ret[target][x], ret[i][x]);
        }

        for (int y = 0; y < n; y++) {
            if (y != i && num[y][i] == 1) {
                for (int x = 0; x < n; x++) {
                    num[y][x] ^= num[i][x];
                    ret[y][x] ^= ret[i][x];
                }
            }
        }
    }

    if (possible) {
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < n; x++) {
                if (ret[y][x]) {
                    printf("%d ", x + 1);
                }
            }
            printf("\n");
        }
    } else {
        printf("-1");
    }

    return 0;
}