#include <bits/stdc++.h>
#define MAXN 20

using namespace std;

int dir_x[] = {0, -1, 1, 0}, dir_y[] = {-1, 0, 0, 1};
int n, student[MAXN + 1][MAXN + 1];
bool does_like[MAXN * MAXN + 1][MAXN * MAXN + 1];

bool is_possible_pos(int x, int y) {
    return (0 < x) && (0 < y) && (x <= n) && (y <= n);
}

bool is_possible_sit(int x, int y) {
    return is_possible_pos(x, y) && (!student[y][x]);
}

int get_adj_like(int cur, int x, int y) {
    int ret = 0;

    for (int i = 0; i < 4; i++) {
        int new_x = x + dir_x[i];
        int new_y = y + dir_y[i];

        if (is_possible_pos(new_x, new_y)) {
            ret += does_like[cur][student[new_y][new_x]];
        }
    }

    return ret;
}

int get_adj_empty(int x, int y) {
    int ret = 0;

    for (int i = 0; i < 4; i++) {
        int new_x = x + dir_x[i];
        int new_y = y + dir_y[i];

        if (is_possible_pos(new_x, new_y)) {
            ret += (student[new_y][new_x] == 0);
        }
    }

    return ret;
}

void put_student(int cur) {
    int target_x, target_y;
    int adj_like = -1, adj_empty = -1;

    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= n; x++) {
            if (is_possible_sit(x, y)) {
                int cur_adj_like = get_adj_like(cur, x, y);
                int cur_adj_empty = get_adj_empty(x, y);

                if ((adj_like < cur_adj_like) ||
                    ((adj_like == cur_adj_like) &&
                     (adj_empty < cur_adj_empty))) {
                    target_x = x;
                    target_y = y;
                    adj_like = cur_adj_like;
                    adj_empty = cur_adj_empty;
                }
            }
        }
    }

    student[target_y][target_x] = cur;
}

int get_satisfaction() {
    int ret = 0;
    int satisfaction[] = {0, 1, 10, 100, 1000};

    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= n; x++) {
            int cur = student[y][x];
            int adj_like = get_adj_like(cur, x, y);
            ret += satisfaction[adj_like];
        }
    }

    return ret;
}

int main() {
    freopen("input.txt", "r", stdin);
    memset(student, 0, sizeof(student));
    memset(does_like, 0, sizeof(does_like));

    scanf("%d", &n);

    int student_num = n * n;
    int target, a;
    for (int i = 0; i < student_num; i++) {
        scanf("%d", &target);

        for (int i = 0; i < 4; i++) {
            scanf("%d", &a);
            does_like[target][a] = true;
        }
        put_student(target);
    }

    printf("%d", get_satisfaction());

    return 0;
}