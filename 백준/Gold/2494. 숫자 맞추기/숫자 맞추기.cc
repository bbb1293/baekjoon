#include <bits/stdc++.h>

using namespace std;

int n;
int dp[10000][10];
int ori[10000], want[10000];
vector<int> ans;

int get_dp(int cur, int diff) {
    int &ret = dp[cur][diff];

    if (ret != -1) {
        return ret;
    }

    if (cur == n) {
        return 0;
    }

    int cur_num = (ori[cur] + diff) % 10;
    ret = ((cur_num - want[cur] + 10) % 10) + get_dp(cur + 1, diff);

    int new_diff = (want[cur] - cur_num + 10) % 10;
    int cand = new_diff + get_dp(cur + 1, (diff + new_diff) % 10);

    if (ret > cand) {
        ret = cand;
    }

    return ret;
}

vector<int> solve() {
    vector<int> ans;

    int diff = 0;

    for (int i = 0; i < n; i++) {
        int cur_num = (ori[i] + diff) % 10;
        int diff1 = (cur_num - want[i] + 10) % 10;
        int ret = (diff1 + get_dp(i + 1, diff));

        int diff2 = (want[i] - cur_num + 10) % 10;
        int cand = diff2 + get_dp(i + 1, (diff + diff2) % 10);

        if (ret < cand) {
            ans.push_back(-diff1);
        } else {
            ans.push_back(diff2);
            diff = (diff + diff2) % 10;
        }
    }

    return ans;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%1d", &ori[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%1d", &want[i]);
    }

    memset(dp, -1, sizeof(dp));
    printf("%d\n", get_dp(0, 0));

    vector<int> ret = solve();
    for (int i = 0; i < n; i++) {
        printf("%d %d\n", i + 1, ret[i]);
    }

    return 0;
}