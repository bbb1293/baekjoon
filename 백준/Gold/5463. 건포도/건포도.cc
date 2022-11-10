#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;
int n, m;
int r[51][51], dp[51][51][51][51], presum[51][51];

int get_dp(int left_y, int right_y, int left_x,
           int right_x) {
    int &ret = dp[left_y][right_y][left_x][right_x];

    if (ret != -1) {
        return ret;
    }

    if (left_y == right_y && left_x == right_x) {
        return ret = 0;
    }

    ret = INF;

    int add = presum[right_y][right_x] -
              presum[left_y - 1][right_x] -
              presum[right_y][left_x - 1] +
              presum[left_y - 1][left_x - 1];

    for (int div_y = left_y; div_y < right_y; div_y++) {
        ret = min(ret,
                  get_dp(left_y, div_y, left_x, right_x) +
                      get_dp(div_y + 1, right_y, left_x,
                             right_x));
    }

    for (int div_x = left_x; div_x < right_x; div_x++) {
        ret = min(ret,
                  get_dp(left_y, right_y, left_x, div_x) +
                      get_dp(left_y, right_y, div_x + 1,
                             right_x));
    }

    ret += add;
    return ret;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);
    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= m; x++) {
            scanf("%d", &r[y][x]);

            presum[y][x] = presum[y - 1][x] +
                           presum[y][x - 1] -
                           presum[y - 1][x - 1] + r[y][x];
        }
    }

    memset(dp, -1, sizeof(dp));

    printf("%d", get_dp(1, n, 1, m));

    return 0;
}