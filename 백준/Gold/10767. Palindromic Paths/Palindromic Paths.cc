#include <bits/stdc++.h>

using namespace std;

int n;
char grid[18][19];
set<string> s[18], ans;

void set_set(int y, int x, string cur) {
    if (y + x == n - 1) {
        s[x].insert(cur);
    } else {
        if (y + 1 < n) {
            set_set(y + 1, x, cur + grid[y + 1][x]);
        }

        if (x + 1 < n) {
            set_set(y, x + 1, cur + grid[y][x + 1]);
        }
    }
}

void set_set2(int y, int x, string cur) {
    if (y + x == n - 1) {
        if (s[x].count(cur)) {
            ans.insert(cur);
        }
    } else {
        if (y - 1 >= 0) {
            set_set2(y - 1, x, cur + grid[y - 1][x]);
        }

        if (x - 1 >= 0) {
            set_set2(y, x - 1, cur + grid[y][x - 1]);
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    for (int y = 0; y < n; y++) {
        scanf("%s", grid[y]);
    }

    if (grid[0][0] != grid[n - 1][n - 1]) {
        printf("0");
        return 0;
    }

    set_set(0, 0, string(1, grid[0][0]));
    set_set2(n - 1, n - 1, string(1, grid[n - 1][n - 1]));

    printf("%d", ans.size());

    return 0;
}
