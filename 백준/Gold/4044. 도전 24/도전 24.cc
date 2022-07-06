#include <bits/stdc++.h>

using namespace std;

int num[4];
bool used[4];

void set_m(map<int, bool> &m, int cur, int cnt) {
    if (cnt == 4) {
        m[cur] = true;
    } else {
        if (cnt == 2) {
            int a = -1, b;
            for (int i = 0; i < 4; i++) {
                if (!used[i]) {
                    if (a == -1) {
                        a = num[i];
                    } else {
                        b = num[i];
                    }
                }
            }

            set_m(m, cur * (a + b), 4);
            set_m(m, cur * (a - b), 4);
            set_m(m, cur * (b - a), 4);

            if ((a + b != 0) && (cur % (a + b) == 0)) {
                set_m(m, cur / (a + b), 4);
            }

            if ((a - b != 0) && (cur % (a - b) == 0)) {
                set_m(m, cur / (a - b), 4);
            }

            if ((b - a != 0) && (cur % (b - a) == 0)) {
                set_m(m, cur / (b - a), 4);
            }
        }

        for (int i = 0; i < 4; i++) {
            if (used[i]) {
                continue;
            }
            used[i] = true;

            set_m(m, cur + num[i], cnt + 1);
            set_m(m, cur - num[i], cnt + 1);
            set_m(m, num[i] - cur, cnt + 1);
            set_m(m, cur * num[i], cnt + 1);

            if (num[i] != 0 && cur % num[i] == 0) {
                set_m(m, cur / num[i], cnt + 1);
            }

            if (cur != 0 && num[i] % cur == 0) {
                set_m(m, num[i] / cur, cnt + 1);
            }

            used[i] = false;
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    int t = 0;
    while (true) {
        t++;
        for (int i = 0; i < 4; i++) {
            scanf("%d", &num[i]);
        }

        if (num[0] == 0) {
            break;
        }

        map<int, bool> m;

        for (int i = 0; i < 4; i++) {
            used[i] = true;

            set_m(m, num[i], 1);

            used[i] = false;
        }

        int ret, cnt = 0;
        for (auto &k : m) {
            if (k.second == false) {
                continue;
            }
            k.second = true;

            int cur_cnt = 1;
            while (m[k.first + cur_cnt] != false) {
                m[k.first + cur_cnt] = 0;
                cur_cnt++;
            }

            if (cnt <= cur_cnt) {
                ret = k.first;
                cnt = cur_cnt;
            }
        }

        printf("Case %d: %d to %d\n", t, ret, ret + cnt - 1);
    }

    return 0;
}
