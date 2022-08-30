#include <bits/stdc++.h>

using namespace std;

int n, m, l, k;
pair<int, int> xy[100];
set<int> pos_x, pos_y;

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d %d %d", &n, &m, &l, &k);

    for (int i = 0; i < k; i++) {
        scanf("%d %d", &xy[i].first, &xy[i].second);
        pos_x.insert(xy[i].first);
        pos_y.insert(xy[i].second);
    }

    int ret = 0;
    for (auto x : pos_x) {
        for (auto y : pos_y) {
            int cnt = 0;

            for (int i = 0; i < k; i++) {
                auto [cur_x, cur_y] = xy[i];

                if (x <= cur_x && cur_x <= x + l && y <= cur_y &&
                    cur_y <= y + l) {
                    cnt++;
                }
            }

            ret = max(ret, cnt);
        }
    }

    printf("%d", k - ret);

    return 0;
}
