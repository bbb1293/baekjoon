#include <bits/stdc++.h>

using namespace std;

int n, m;
int dp[(1 << 11)][11];
vector<pair<int, int> > pos;

int get_dist(int i, int j) {
    return max(abs(pos[i].first - pos[j].first),
               abs(pos[i].second - pos[j].second));
}

int get_dp(int state, int cur) {
    int &ret = dp[state][cur];

    if (ret != -1) {
        return ret;
    }

    if (!state) {
        return ret = 0;
    }

    for (int i = 0; i < m; i++) {
        if (state & (1 << i)) {
            int cand = get_dp(state - (1 << i), i) + get_dist(i, cur);

            if (ret == -1 || cand < ret) {
                ret = cand;
            }
        }
    }

    return ret;
}

int main() {
    // freopen("input.txt", "r", stdin);

    memset(dp, -1, sizeof(dp));

    scanf("%d", &n);

    int origin = -1;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            int tmp;
            scanf("%d", &tmp);

            if (tmp) {
                pos.push_back({y, x});
                if (tmp == 2) {
                    origin = pos.size() - 1;
                }
            }
        }
    }

    m = pos.size();
    for (int i = 1; i < m; i++) {
        if (((pos[i - 1].first + pos[i - 1].second) & 1) !=
            ((pos[i].first + pos[i].second) & 1)) {
            printf("Shorei");
            return 0;
        }
    }

    printf("Undertaker\n%d", get_dp((1 << m) - 1 - (1 << origin), origin));

    return 0;
}
