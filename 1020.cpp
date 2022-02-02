#include <bits/stdc++.h>

using namespace std;

int n = 0, num[15];
vector<vector<long long> > dp(16, vector<long long>(106, 1e15));
int line_cnt[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 5};

void init_dp() {
    dp[0][0] = 0;

    long long times = 1;
    for (int pos = 1; pos <= n; pos++) {
        int start = pos * 2, end = pos * 7;
        for (int line = start; line <= end; line++) {
            for (int cur = 0; cur < 10; cur++) {
                if (line_cnt[cur] > line) {
                    continue;
                }
                long long prev = dp[pos - 1][line - line_cnt[cur]];
                if (prev < 1e15) {
                    dp[pos][line] = min(dp[pos][line], prev + cur * times);
                }
            }
        }
        times *= 10;
    }
}

int main() {
    freopen("input.txt", "r", stdin);

    char tmp[16];
    scanf("%s", tmp);

    long long ori_num = 0;
    n = strlen(tmp);
    for (int i = n - 1; i >= 0; i--) {
        num[i] = tmp[n - i - 1] - '0';
        ori_num *= 10;
        ori_num += num[i];
    }

    init_dp();

    long long cur_num = 0, times = 1, ret = -1, small_ret = 1e15;
    int cur_cnt = 0;
    for (int pos = 0; pos < n; pos++) {
        int cur = num[pos];
        cur_cnt += line_cnt[cur];
        cur_num += cur * times;

        for (int i = cur + 1; i < 10; i++) {
            if (line_cnt[i] <= cur_cnt) {
                long long cand = dp[pos][cur_cnt - line_cnt[i]];
                if (cand < 1e15) {
                    ret = cand + i * times - cur_num;
                    break;
                }
            }
        }

        if (ret != -1) {
            break;
        }

        for (int i = 0; i <= cur; i++) {
            if (line_cnt[i] <= cur_cnt) {
                long long cand = dp[pos][cur_cnt - line_cnt[i]];
                if (cand < ori_num) {
                    small_ret = min(small_ret, cand + i * times - cur_num);
                }
            }
        }
        times *= 10;
    }

    if (ret != -1) {
        printf("%lld", ret);
    } else {
        printf("%lld", times + small_ret);
    }

    return 0;
}