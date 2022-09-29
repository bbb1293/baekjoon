#include <bits/stdc++.h>

using namespace std;

const int MAXN = (1 << 9);
int n, m;
char state[100][11];
int dp[2][MAXN];

int convert_num2state(int cur_state[9], int cur_num) {
    int ret = 0;
    for (int i = 0; i < m - 1; i++) {
        cur_state[i] = (cur_num & 1);
        ret += cur_state[i];
        cur_num /= 2;
    }

    return ret;
}

bool is_cur_possible(int cur_state[9], int height) {
    for (int i = 0; i < m - 1; i++) {
        if (i && cur_state[i - 1] && cur_state[i]) {
            return false;
        }
    }

    for (int x = 0; x < m; x++) {
        if (state[height][x] == '#' ||
            state[height + 1][x] == '#') {
            bool possible = false;

            if (0 <= (x - 1) && cur_state[x - 1]) {
                possible = true;
            }

            if (cur_state[x]) {
                possible = true;
            }

            if (!possible) {
                return false;
            }
        }
    }

    return true;
}

bool is_possible(int prev_state[9], int cur_state[9]) {
    for (int i = 0; i < m - 1; i++) {
        if (prev_state[i]) {
            bool possible = cur_state[i];
            if (0 <= i - 1 && cur_state[i - 1]) {
                possible = true;
            }

            if (i + 1 < m - 1 && cur_state[i + 1]) {
                possible = true;
            }

            if (!possible) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);

    for (int y = 0; y < n; y++) {
        scanf("%s", &state[y]);
    }

    memset(dp, -1, sizeof(dp));
    dp[1][0] = 0;

    int cur_state[9], prev_state[9];

    int max_num = (1 << (m - 1));
    for (int height = 0; height < n; height += 2) {
        int dp_state = (height / 2) & 1;
        int prev_dp_state = dp_state ^ 1;

        for (int cur_num = 0; cur_num < max_num;
             cur_num++) {
            dp[dp_state][cur_num] = -1;
            int cnt = convert_num2state(cur_state, cur_num);

            if (!is_cur_possible(cur_state, height)) {
                continue;
            }

            for (int prev_num = 0; prev_num < max_num;
                 prev_num++) {
                if (dp[prev_dp_state][prev_num] == -1) {
                    continue;
                }

                convert_num2state(prev_state, prev_num);

                if (is_possible(prev_state, cur_state)) {
                    int cand =
                        cnt + dp[prev_dp_state][prev_num];

                    if (dp[dp_state][cur_num] == -1 ||
                        cand < dp[dp_state][cur_num]) {
                        dp[dp_state][cur_num] = cand;
                    }
                }
            }
        }
    }

    int ret = 1e8, dp_state = ((n - 2) / 2) & 1;
    for (int cur_num = 0; cur_num < max_num; cur_num++) {
        if (dp[dp_state][cur_num] != -1) {
            ret = min(ret, dp[dp_state][cur_num]);
        }
    }

    printf("%d", ret);

    return 0;
}