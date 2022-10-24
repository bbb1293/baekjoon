#include <bits/stdc++.h>

using namespace std;

int r, c;
int state[500][500], cnt[500][500];
int dir_x[] = {1, 1, 1, 0, -1, -1, -1, 0},
    dir_y[] = {-1, 0, 1, 1, 1, 0, -1, -1};
pair<int, int> dp[500][500];

pair<int, int> get_dp(int y, int x) {
    pair<int, int> &ret = dp[y][x];

    if (ret.first != -1) {
        return ret;
    }

    ret = {y, x};

    for (int dir = 0; dir < 8; dir++) {
        auto [next_y, next_x] =
            make_pair(y + dir_y[dir], x + dir_x[dir]);

        if (next_y < 0 || next_x < 0 || next_y == r ||
            next_x == c) {
            continue;
        }

        if (state[next_y][next_x] <
            state[ret.first][ret.second]) {
            ret = {next_y, next_x};
        }
    }

    if (ret != make_pair(y, x)) {
        ret = get_dp(ret.first, ret.second);
    }

    return ret;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &r, &c);

    for (int y = 0; y < r; y++) {
        for (int x = 0; x < c; x++) {
            scanf("%d", &state[y][x]);
        }
    }

    memset(dp, -1, sizeof(dp));

    for (int y = 0; y < r; y++) {
        for (int x = 0; x < c; x++) {
            pair<int, int> ret = get_dp(y, x);
            cnt[ret.first][ret.second]++;
        }
    }

    for (int y = 0; y < r; y++) {
        for (int x = 0; x < c; x++) {
            printf("%d ", cnt[y][x]);
        }
        printf("\n");
    }

    return 0;
}