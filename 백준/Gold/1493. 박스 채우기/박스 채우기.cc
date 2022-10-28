#include <bits/stdc++.h>

using namespace std;

int all_cnt;
int cnt[20];

int get_cnt(int l, int h, int w) {
    if (l == 0 && h == 0 && w == 0) {
        return 0;
    }

    if (all_cnt == 0) {
        return -1;
    }

    for (int i = 19; i >= 0; i--) {
        if (!cnt[i]) {
            continue;
        }

        int cur_len = (1 << i);

        if (cur_len <= l && cur_len <= h && cur_len <= w) {
            int ret = 1;
            cnt[i]--;

            if (l - cur_len > 0) {
                int tmp =
                    get_cnt(l - cur_len, cur_len, cur_len);
                if (tmp == -1) {
                    return -1;
                }

                ret += tmp;
            }

            if (h - cur_len > 0) {
                int tmp = get_cnt(l, h - cur_len, cur_len);
                if (tmp == -1) {
                    return -1;
                }

                ret += tmp;
            }

            if (w - cur_len > 0) {
                int tmp = get_cnt(l, h, w - cur_len);
                if (tmp == -1) {
                    return -1;
                }

                ret += tmp;
            }

            return ret;
        }
    }

    return -1;
}

int main() {
    // freopen("input.txt", "r", stdin);

    int l, h, w;
    scanf("%d %d %d", &l, &h, &w);

    int n;
    scanf("%d", &n);

    while (n--) {
        int a, b;
        scanf("%d %d", &a, &b);

        all_cnt += b;
        cnt[a] = b;
    }

    printf("%d", get_cnt(l, h, w));

    return 0;
}