#include <bits/stdc++.h>

using namespace std;

int n, m;
int grid[1000][1000];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);

    int cnt[2] = {
        0,
    };

    bool check = true;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            scanf("%d", &grid[y][x]);
            cnt[grid[y][x]]++;

            if (y != 0) {
                if (grid[y - 1][x] == grid[y][x]) {
                    check = false;
                }

            } else {
                if (x != 0) {
                    if (grid[y][x - 1] == grid[y][x]) {
                        check = false;
                    }
                }
            }
        }
    }

    if (check || (cnt[0] & 1) || (cnt[1] & 1)) {
        printf("-1");
    } else {
        printf("1");
    }

    return 0;
}