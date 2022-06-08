#include <bits/stdc++.h>

using namespace std;

int n;

int get_pos(int cur) {
    int pos = 0;
    while (cur) {
        pos++;
        cur /= 10;
    }

    return pos;
}

int get_cnt(int cur) {
    int cnt = 0;
    while (cur) {
        cnt += (cur & 1);
        cur /= 10;
    }

    return cnt;
}

int get_max(int cur) {
    int pos = get_pos(cur);
    int cnt = get_cnt(cur);

    if (pos == 1) {
        return cnt;
    } else if (pos == 2) {
        return cnt + get_max((cur / 10) + (cur % 10));
    } else {
        int ret = -1;

        int i_pos = 1;
        for (int i = 1; i < pos; i++) {
            int j_pos = i_pos * 10;
            for (int j = i + 1; j < pos; j++) {
                int cand = get_max((cur / (j_pos * 10)) +
                                   ((cur % (j_pos * 10)) / (i_pos * 10)) +
                                   (cur % (i_pos * 10)));

                if (ret == -1 || (cand > ret)) {
                    ret = cand;
                }

                j_pos *= 10;
            }

            i_pos *= 10;
        }

        return ret + cnt;
    }
}

int get_min(int cur) {
    int pos = get_pos(cur);
    int cnt = get_cnt(cur);

    if (pos == 1) {
        return cnt;
    } else if (pos == 2) {
        return cnt + get_min((cur / 10) + (cur % 10));
    } else {
        int ret = -1;

        int i_pos = 1;
        for (int i = 1; i < pos; i++) {
            int j_pos = i_pos * 10;
            for (int j = i + 1; j < pos; j++) {
                int cand = get_min((cur / (j_pos * 10)) +
                                   ((cur % (j_pos * 10)) / (i_pos * 10)) +
                                   (cur % (i_pos * 10)));

                if (ret == -1 || (cand < ret)) {
                    ret = cand;
                }

                j_pos *= 10;
            }

            i_pos *= 10;
        }

        return ret + cnt;
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    printf("%d %d", get_min(n), get_max(n));

    return 0;
}
