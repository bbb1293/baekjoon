#include <bits/stdc++.h>

using namespace std;

int n;
int sand[499][499];

int dir_x[] = {-1, 0, 1, 0}, dir_y[] = {0, 1, 0, -1};
int sand_dir_x[4][9];
int sand_dir_y[4][9];
int sand_ratio[9] = {5, 10, 10, 7, 2, 7, 2, 1, 1};

void set_sand_dir() {
    int first_xs[] = {-2, -1, -1, 0, 0, 0, 0, 1, 1};
    int first_ys[] = {0, -1, 1, -1, -2, 1, 2, -1, 1};

    copy(first_xs, first_xs + 9, sand_dir_x[0]);
    copy(first_ys, first_ys + 9, sand_dir_y[0]);

    for (int i = 0; i < 9; i++) {
        sand_dir_x[1][i] = -sand_dir_y[0][i];
        sand_dir_y[1][i] = -sand_dir_x[0][i];
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 9; j++) {
            sand_dir_x[i + 2][j] = -sand_dir_x[i][j];
            sand_dir_y[i + 2][j] = -sand_dir_y[i][j];
        }
    }
}

bool are_valid(int x, int y) {
    return (0 <= x) && (0 <= y) && (x < n) && (y < n);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    set_sand_dir();

    scanf("%d", &n);

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            scanf("%d", &sand[y][x]);
        }
    }

    int dir = 0;
    int prev_x = n / 2, prev_y = n / 2;
    int times = 0, step = 1;
    int ret = 0;
    while (prev_x >= 0) {
        for (int i = 0; i < step; i++) {
            prev_x += dir_x[dir];
            prev_y += dir_y[dir];

            if (prev_x < 0) {
                break;
            }

            if (!sand[prev_y][prev_x]) {
                continue;
            }

            int rest = sand[prev_y][prev_x];
            for (int sand_dir = 0; sand_dir < 9; sand_dir++) {
                int sand_x = prev_x + sand_dir_x[dir][sand_dir];
                int sand_y = prev_y + sand_dir_y[dir][sand_dir];
                int sand_mass =
                    sand[prev_y][prev_x] * sand_ratio[sand_dir] / 100;
                rest -= sand_mass;

                if (are_valid(sand_x, sand_y)) {
                    sand[sand_y][sand_x] += sand_mass;
                } else {
                    ret += sand_mass;
                }
            }

            int alpha_x = prev_x + dir_x[dir];
            int alpha_y = prev_y + dir_y[dir];

            if (are_valid(alpha_x, alpha_y)) {
                sand[alpha_y][alpha_x] += rest;
            } else {
                ret += rest;
            }
            sand[prev_y][prev_x] = 0;
        }

        dir = (dir + 1) % 4;

        times++;
        if (times == 2) {
            times = 0;
            step++;
        }
    }

    printf("%d", ret);

    return 0;
}