#include <bits/stdc++.h>

using namespace std;

int n, m, t, k;
pair<int, int> pos[100];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d %d %d", &n, &m, &t, &k);

    for (int i = 0; i < t; i++) {
        scanf("%d %d", &pos[i].second, &pos[i].first);
    }

    pair<int, int> ret_pos;
    int ret = -1;

    for (int i = 0; i < t; i++) {
        for (int j = 0; j < t; j++) {
            int y = pos[i].first, x = pos[j].second;

            int cnt = 0;
            for (int l = 0; l < t; l++) {
                if (y <= pos[l].first &&
                    pos[l].first <= y + k &&
                    x <= pos[l].second &&
                    pos[l].second <= x + k) {
                    cnt++;
                }
            }

            if (ret < cnt) {
                if (y + k > m) {
                    y = m - k;
                }

                if (x + k > n) {
                    x = n - k;
                }

                ret_pos = {y + k, x};
                ret = cnt;
            }
        }
    }

    printf("%d %d\n", ret_pos.second, ret_pos.first);
    printf("%d", ret);

    return 0;
}