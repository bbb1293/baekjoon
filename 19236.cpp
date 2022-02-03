#include <bits/stdc++.h>

using namespace std;

struct Fish {
    int x, y, dir;
};

int dir_x[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dir_y[] = {-1, -1, 0, 1, 1, 1, 0, -1};

bool is_valid(int x, int y) {
    return (0 <= x) && (0 <= y) && (x < 4) && (y < 4);
}

int solve(vector<Fish> fish, vector<vector<int> > fish_map) {
    int cur_x, cur_y, cur_dir;
    for (int i = 1; i < 17; i++) {
        cur_x = fish[i].x, cur_y = fish[i].y, cur_dir = fish[i].dir;

        if (cur_x == -1) {
            continue;
        }

        int new_x, new_y, new_dir;
        for (int j = 0; j < 8; j++) {
            new_dir = (cur_dir + j) % 8;
            new_x = cur_x + dir_x[new_dir], new_y = cur_y + dir_y[new_dir];

            if (is_valid(new_x, new_y)) {
                int move_fish = fish_map[new_y][new_x];

                if (move_fish == 0) {
                    continue;
                }

                fish_map[new_y][new_x] = i;
                fish_map[cur_y][cur_x] = move_fish;
                fish[i] = {new_x, new_y, new_dir};

                if (move_fish != -1) {
                    fish[move_fish].x = cur_x;
                    fish[move_fish].y = cur_y;
                }

                break;
            }
        }
    }

    Fish shark = fish[0];
    cur_x = shark.x, cur_y = shark.y, cur_dir = shark.dir;
    fish_map[cur_y][cur_x] = -1;
    int ret = 0;
    while (true) {
        cur_x += dir_x[cur_dir];
        cur_y += dir_y[cur_dir];

        if (!is_valid(cur_x, cur_y)) {
            break;
        }

        int catch_fish = fish_map[cur_y][cur_x];
        if (catch_fish == -1) {
            continue;
        }

        fish_map[cur_y][cur_x] = 0;
        fish[0] = fish[catch_fish];
        fish[catch_fish].x = -1;
        ret = max(ret, catch_fish + solve(fish, fish_map));
        fish_map[cur_y][cur_x] = catch_fish;
        fish[0] = shark;
        fish[catch_fish].x = cur_x;
    }
    return ret;
}

int main() {
    freopen("input.txt", "r", stdin);

    vector<Fish> fish(17);
    vector<vector<int> > fish_map(4, vector<int>(4));
    int fish_num, fish_dir;
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            scanf("%d %d", &fish_num, &fish_dir);
            fish_dir--;
            fish[fish_num] = {x, y, fish_dir};
            fish_map[y][x] = fish_num;
        }
    }

    int ret = fish_map[0][0];
    fish[0] = fish[ret];
    fish_map[0][0] = 0;
    fish[ret].x = -1;
    ret += solve(fish, fish_map);

    printf("%d", ret);

    return 0;
}