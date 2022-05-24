#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e3;
char s[MAXN + 1];
vector<int> all_cnt;

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%s", s);

    int ret = 0;
    int cur_mode = 0, cur_cnt = 0;
    for (int i = 0; s[i]; i++) {
        if (cur_mode == 0) {
            if ('a' <= s[i] && s[i] <= 'z') {
                cur_cnt++;
            } else {
                all_cnt.push_back(cur_cnt);
                cur_mode = 1;
                cur_cnt = 1;
            }

        } else {
            if ('a' <= s[i] && s[i] <= 'z') {
                all_cnt.push_back(cur_cnt);
                cur_mode = 0;
                cur_cnt = 1;
            } else {
                cur_cnt++;
            }
        }
        ret++;
    }

    if (cur_cnt != 0) {
        all_cnt.push_back(cur_cnt);
    }

    cur_mode = 0;
    for (int i = 1; i < all_cnt.size(); i++) {
        if (cur_mode != (i % 2)) {
            ret++;
            if (all_cnt[i] != 1) {
                cur_mode = cur_mode ^ 1;
            }
        }
    }

    printf("%d", ret);

    return 0;
}
