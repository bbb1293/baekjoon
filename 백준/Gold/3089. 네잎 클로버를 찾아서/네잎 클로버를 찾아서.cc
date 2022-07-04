#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<pair<int, int> > yx, xy;

int main() {
    // freopen("input.txt", "r", stdin);

    bool check = false;

    scanf("%d %d", &n, &m);
    while (n--) {
        int x, y;
        scanf("%d %d", &x, &y);
        yx.push_back({y, x});
        xy.push_back({x, y});

        if (x == 0 && y == 0) {
            check = true;
        }
    }

    if (!check) {
        yx.push_back({0, 0});
        xy.push_back({0, 0});
    }

    sort(yx.begin(), yx.end());
    sort(xy.begin(), xy.end());

    pair<int, int> cur = {0, 0};
    while (m--) {
        char c;
        scanf(" %c", &c);

        if (c == 'L') {
            auto it = lower_bound(yx.begin(), yx.end(),
                                  make_pair(cur.second, cur.first));
            it--;

            cur = {it->second, it->first};

        } else if (c == 'R') {
            auto it = lower_bound(yx.begin(), yx.end(),
                                  make_pair(cur.second, cur.first));
            it++;

            cur = {it->second, it->first};
        } else if (c == 'U') {
            auto it = lower_bound(xy.begin(), xy.end(), cur);
            it++;

            cur = *it;
        } else {
            auto it = lower_bound(xy.begin(), xy.end(), cur);
            it--;

            cur = *it;
        }
    }

    printf("%d %d", cur.first, cur.second);

    return 0;
}
