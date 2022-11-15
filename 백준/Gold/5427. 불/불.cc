#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3;
int w, h;
int dir_y[] = {0, 1, 0, -1}, dir_x[] = {1, 0, -1, 0};
char state[MAXN][MAXN + 1];
queue<pair<int, int> > fire, sangun;

int main() {
    // freopen("input.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    while (t--) {
        while (!fire.empty()) {
            fire.pop();
        }

        while (!sangun.empty()) {
            sangun.pop();
        }

        scanf("%d %d", &w, &h);

        for (int y = 0; y < h; y++) {
            scanf("%s", state[y]);

            for (int x = 0; x < w; x++) {
                if (state[y][x] == '@') {
                    sangun.push({y, x});
                } else if (state[y][x] == '*') {
                    fire.push({y, x});
                }
            }
        }

        bool possible = false;
        int cnt = 1;
        while (true) {
            int fire_sz = fire.size();
            while (fire_sz--) {
                auto [y, x] = fire.front();
                fire.pop();

                for (int dir = 0; dir < 4; dir++) {
                    int next_y = y + dir_y[dir];
                    int next_x = x + dir_x[dir];

                    if (next_y < 0 || next_x < 0 ||
                        next_y == h || next_x == w ||
                        state[next_y][next_x] == '#' ||
                        state[next_y][next_x] == '*') {
                        continue;
                    }

                    state[next_y][next_x] = '*';
                    fire.push({next_y, next_x});
                }
            }

            int sangun_sz = sangun.size();
            while (sangun_sz--) {
                auto [y, x] = sangun.front();
                sangun.pop();

                if (y == 0 || x == 0 || y == h - 1 ||
                    x == w - 1) {
                    possible = true;
                    break;
                }

                for (int dir = 0; dir < 4; dir++) {
                    int next_y = y + dir_y[dir];
                    int next_x = x + dir_x[dir];

                    if (next_y < 0 || next_x < 0 ||
                        next_y == h || next_x == w ||
                        state[next_y][next_x] != '.') {
                        continue;
                    }

                    state[next_y][next_x] = '$';
                    sangun.push({next_y, next_x});
                }
            }

            if (possible) {
                break;
            }

            if (sangun.size() == 0) {
                break;
            }
            cnt++;
        }

        if (possible) {
            printf("%d\n", cnt);
        } else {
            printf("IMPOSSIBLE\n");
        }
    }

    return 0;
}