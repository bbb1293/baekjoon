#include <bits/stdc++.h>

using namespace std;

struct State {
    int h, y, x;

    bool operator<(const State &a) const { return h < a.h; }
};

int h, w;
int height[500][500];
int dir_x[] = {0, 1, 0, -1}, dir_y[] = {1, 0, -1, 0};
bool visited[500][500];
priority_queue<State> pq, tmp;

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &h, &w);

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            scanf("%d", &height[y][x]);
            if (height[y][x] > 1) {
                pq.push({height[y][x], y, x});
            }
        }
    }

    int ret = 0;
    while (!pq.empty()) {
        auto [c, y, x] = pq.top();
        pq.pop();

        if (visited[y][x]) {
            continue;
        }
        visited[y][x] = true;

        ret++;
        tmp.push({c, y, x});

        while (!tmp.empty()) {
            auto [cur_c, cur_y, cur_x] = tmp.top();
            tmp.pop();

            for (int dir = 0; dir < 4; dir++) {
                int next_y = cur_y + dir_y[dir];
                int next_x = cur_x + dir_x[dir];

                if (next_y < 0 || next_x < 0 || next_y == h || next_x == w ||
                    visited[next_y][next_x] || height[next_y][next_x] < 2 ||
                    height[next_y][next_x] > cur_c) {
                    continue;
                }

                visited[next_y][next_x] = true;
                tmp.push({height[next_y][next_x], next_y, next_x});
            }
        }
    }

    printf("%d", ret);

    return 0;
}