#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e4;
int n;
int dice[MAXN][6];

int get_sum(int cur, int down_num) {
    if (cur == n) {
        return 0;
    }

    int down_idx;
    for (int i = 0; i < 6; i++) {
        if (dice[cur][i] == down_num) {
            down_idx = i;
            break;
        }
    }

    int up_idx = (down_idx + 3) % 6;
    int max_num = 0;
    for (int i = 0; i < 6; i++) {
        if (i != down_idx && i != up_idx) {
            max_num = max(max_num, dice[cur][i]);
        }
    }

    return max_num + get_sum(cur + 1, dice[cur][up_idx]);
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &dice[i][0], &dice[i][1],
              &dice[i][2]);
        scanf("%d %d %d", &dice[i][4], &dice[i][5],
              &dice[i][3]);
    }

    int ret = 0;
    for (int i = 0; i < 6; i++) {
        ret = max(ret, get_sum(0, i + 1));
    }

    printf("%d", ret);

    return 0;
}