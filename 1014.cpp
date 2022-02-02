#include <bits/stdc++.h>

#define LAST 1024

using namespace std;

int n, m;
int dp[2][LAST];
char classroom[11];
vector<vector<int> > states(LAST, vector<int>(12, 0));

void init() {
    int last = LAST - 1;
    for (int i = 0; i <= last; i++) {
        int cur = i, idx = 1;
        while (cur) {
            states[i][idx] = (cur % 2);
            idx++;
            cur /= 2;
        }
    }
}

int count_bit(int a) {
    int ret = 0;
    while (a) {
        ret += (a % 2);
        a /= 2;
    }
    return ret;
}

bool is_valid(int bits) {
    int prev = 0, idx = 0;
    while (bits) {
        if (bits % 2) {
            if ((prev == 1) || (classroom[idx]) == 'x') {
                return false;
            }
        }
        idx++;
        prev = (bits % 2);
        bits /= 2;
    }
    return true;
}

bool are_valid(int prev_bits, int cur_bits) {
    vector<int> &prev = states[prev_bits];
    vector<int> &cur = states[cur_bits];

    for (int i = 1; i <= m; i++) {
        if (cur[i]) {
            if (prev[i - 1] || prev[i + 1]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    freopen("input.txt", "r", stdin);

    init();

    int t;
    scanf("%d", &t);

    while (t--) {
        memset(dp, 0, sizeof(dp));

        scanf("%d %d", &n, &m);
        int last = (1 << m) - 1;

        for (int y = 0; y < n; y++) {
            scanf(" %s", classroom);

            for (int bits = 0; bits <= last; bits++) {
                int cur = (y % 2), prev = ((y + 1) % 2);
                dp[cur][bits] = 0;
                if (!is_valid(bits)) {
                    continue;
                }

                int cnt = count_bit(bits);
                for (int prev_bits = 0; prev_bits <= last; prev_bits++) {
                    if (are_valid(prev_bits, bits)) {
                        dp[cur][bits] =
                            max(dp[cur][bits], dp[prev][prev_bits] + cnt);
                    }
                }
            }
        }

        int cur = ((n - 1) % 2), ret = 0;
        for (int bits = 0; bits <= last; bits++) {
            ret = max(ret, dp[cur][bits]);
        }
        printf("%d\n", ret);
    }

    return 0;
}