#include <bits/stdc++.h>

using namespace std;

int n, m;
int dp[10000][100][2];

int get_dp(int num, int turn, int who) {
    int &ret = dp[num][turn][who];

    if (turn == 0) {
        if (num > n) {
            return 1;
        } else {
            return 0;
        }
    }

    if (ret != -1) {
        return ret;
    }

    if (who == 0) {
        for (int i = 1; i <= 1000; i *= 10) {
            int cur_num = (num % (i * 10)) / i;
            int next_num = (cur_num + 1) % 10;

            if (get_dp(num - cur_num * i + next_num * i,
                       turn - 1, who ^ 1) == 1) {
                return ret = 1;
            }
        }

        return ret = 0;
    } else {
        for (int i = 1; i <= 1000; i *= 10) {
            int cur_num = (num % (i * 10)) / i;
            int next_num = (cur_num + 1) % 10;

            if (get_dp(num - cur_num * i + next_num * i,
                       turn - 1, who ^ 1) == 0) {
                return ret = 0;
            }
        }

        return ret = 1;
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    memset(dp, -1, sizeof(dp));

    scanf("%d %d", &n, &m);

    if (get_dp(n, m, 0) == 1) {
        printf("koosaga");
    } else {
        printf("cubelover");
    }

    return 0;
}