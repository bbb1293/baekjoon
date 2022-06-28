#include <bits/stdc++.h>

using namespace std;

int k;
int r, c;
int tile_idx;
char output[1024][1025];
int x_type[] = {0, 1, 0, 1}, y_type[] = {0, 0, 1, 1};

void put_l(int y, int x, int type, int level, char color) {
    if (level == 2) {
        for (int i = 0; i < 4; i++) {
            if (i == type) {
                continue;
            }
            output[y + y_type[i]][x + x_type[i]] = color;
        }
        tile_idx++;

    } else {
        for (int i = 0; i < 4; i++) {
            if (i == type) {
                continue;
            }

            char next_color = 'b';
            if (i == 1 || i == 2) {
                next_color = 'c';
            }

            put_l(y + y_type[i] * level / 2, x + x_type[i] * level / 2, 3 - i,
                  level / 2, next_color);
        }

        put_l(y + level / 4, x + level / 4, type, level / 2, 'a');
    }
}

void put_square(int y, int x, int level, char color) {
    if (level == 1) {
        output[y][x] = '@';
        return;
    }

    int type;
    for (int i = 0; i < 4; i++) {
        int tmp_y = y + (level / 2) * (y_type[i] + 1);
        int tmp_x = x + (level / 2) * (x_type[i] + 1);

        if (r < tmp_y && c < tmp_x) {
            type = i;
            break;
        }
    }

    put_l(y, x, type, level, color);

    char next_color = 'b';
    if (type == 1 || type == 2) {
        next_color = 'c';
    }

    put_square(y + (level / 2) * y_type[type], x + (level / 2) * x_type[type],
               level / 2, next_color);
}

int main() {
    // freopen("input.txt", "r", stdin);

    int t;
    scanf("%d %d", &t, &k);

    while (t--) {
        scanf("%d %d", &r, &c);
        r--;
        c--;

        tile_idx = 1;
        put_square(0, 0, 1 << k, 'a');

        for (int y = 0; y < (1 << k); y++) {
            printf("%s\n", output[y]);
        }
    }

    return 0;
}
