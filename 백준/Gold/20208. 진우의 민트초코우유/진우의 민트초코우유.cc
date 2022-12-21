#include <bits/stdc++.h>

using namespace std;

int n, m, h;
int state[10][10];
int start_y, start_x;
vector<pair<int, int> > milk;
bool visited[10];

int get_dist(int y1, int x1, int y2, int x2) {
    return abs(y1 - y2) + abs(x1 - x2);
}

int get_ret(int cur, int rest, int cnt) {
    int ret = 0;

    if (get_dist(start_y, start_x, milk[cur].first,
                 milk[cur].second) <= rest) {
        ret = cnt;
    }

    for (int i = 0; i < milk.size(); i++) {
        int dist =
            get_dist(milk[cur].first, milk[cur].second,
                     milk[i].first, milk[i].second);

        if (!visited[i] && dist <= rest) {
            visited[i] = true;
            ret = max(ret,
                      get_ret(i, rest - dist + h, cnt + 1));
            visited[i] = false;
        }
    }

    return ret;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d %d", &n, &m, &h);

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            scanf("%d", &state[y][x]);

            if (state[y][x] == 1) {
                start_y = y;
                start_x = x;
            } else if (state[y][x] == 2) {
                milk.push_back({y, x});
            }
        }
    }

    int ret = 0;
    for (int i = 0; i < milk.size(); i++) {
        int dist = get_dist(start_y, start_x, milk[i].first,
                            milk[i].second);

        if (dist <= m) {
            visited[i] = true;
            ret = max(ret, get_ret(i, m - dist + h, 1));
            visited[i] = false;
        }
    }

    printf("%d", ret);

    return 0;
}