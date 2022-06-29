#include <bits/stdc++.h>

using namespace std;

int n, m;
string grid[14];
int dp[14][14][1 << 14];
int point[6][6] = {10, 8, 7, 5, 0, 1, 8, 6, 4, 3, 0, 1, 7, 4, 3, 2, 0, 1,
                   5,  3, 2, 2, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0};

int get_dp(int y, int x, int state) {
    if (x == m) {
        return get_dp(y + 1, 0, state);
    }

    if (y == n) {
        return 0;
    }

    int &ret = dp[y][x][state];

    if (ret != -1) {
        return ret;
    }

    ret = get_dp(y, x + 1, state >> 1);
    if (!(state & 1)) {
        if (x != m - 1 && !(state & 2)) {
            ret = max(ret, get_dp(y, x + 1, (state | 2) >> 1) +
                               point[grid[y][x] - 'A'][grid[y][x + 1] - 'A']);
        }

        if (y != n - 1) {
            ret = max(ret, get_dp(y, x + 1, (state >> 1) | (1 << (m - 1))) +
                               point[grid[y][x] - 'A'][grid[y + 1][x] - 'A']);
        }
    }

    return ret;
}

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));

    cin >> n >> m;
    for (int y = 0; y < n; y++) {
        cin >> grid[y];
    }

    cout << get_dp(0, 0, 0);

    return 0;
}
