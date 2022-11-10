#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;
int state[5][5][5];
int dir_y[] = {0, 1, 0, -1}, dir_x[] = {1, 0, -1, 0};
bool used[5], visited[5][5][5];

struct Position {
    int x, y, z;
};

int get_state(int x, int y, int z, int rotate) {
    if (rotate == 1) {
        int tmp = y;
        y = 4 - x;
        x = tmp;
    } else if (rotate == 2) {
        x = 4 - x;
        y = 4 - y;
    } else if (rotate == 3) {
        int tmp = x;
        x = 4 - y;
        y = tmp;
    }

    return state[z][y][x];
}

int get_dist(vector<pair<int, int> > &order) {
    if (order.size() == 5) {
        if (get_state(0, 0, order[0].first,
                      order[0].second) == 0 ||
            get_state(4, 4, order[4].first,
                      order[4].second) == 0) {
            return INF;
        }

        memset(visited, 0, sizeof(visited));

        queue<Position> q;
        q.push({0, 0, 0});
        visited[0][0][0] = true;

        int dist = 0;
        while (!q.empty()) {
            int sz = q.size();
            dist++;

            while (sz--) {
                auto [x, y, z] = q.front();
                q.pop();

                if (x == 4 && y == 4 && z == 4) {
                    return dist - 1;
                }

                for (int dir = 0; dir < 4; dir++) {
                    int next_x = x + dir_x[dir];
                    int next_y = y + dir_y[dir];

                    if (next_x < 0 || next_y < 0 ||
                        next_x == 5 || next_y == 5 ||
                        visited[next_x][next_y][z]) {
                        continue;
                    }

                    if (get_state(next_x, next_y,
                                  order[z].first,
                                  order[z].second) == 1) {
                        visited[next_x][next_y][z] = true;
                        q.push({next_x, next_y, z});
                    }
                }

                if (z != 0) {
                    if (!visited[x][y][z - 1] &&
                        get_state(x, y, order[z - 1].first,
                                  order[z - 1].second) ==
                            1) {
                        q.push({x, y, z - 1});
                        visited[x][y][z - 1] = true;
                    }
                }

                if (z != 4) {
                    if (!visited[x][y][z + 1] &&
                        get_state(x, y, order[z + 1].first,
                                  order[z + 1].second) ==
                            1) {
                        q.push({x, y, z + 1});
                        visited[x][y][z + 1] = true;
                    }
                }
            }
        }

        return INF;

    } else {
        int ret = INF;

        for (int i = 0; i < 5; i++) {
            if (!used[i]) {
                for (int rotate = 0; rotate < 4; rotate++) {
                    order.push_back({i, rotate});
                    used[i] = true;

                    ret = min(ret, get_dist(order));

                    order.pop_back();
                    used[i] = false;
                }
            }
        }

        return ret;
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    for (int z = 0; z < 5; z++) {
        for (int y = 0; y < 5; y++) {
            for (int x = 0; x < 5; x++) {
                scanf("%d", &state[z][y][x]);
            }
        }
    }

    vector<pair<int, int> > order;
    int ret = get_dist(order);

    if (ret == INF) {
        ret = -1;
    }

    printf("%d", ret);

    return 0;
}