#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1024;
int n, m;
int num[MAXN][MAXN];
int tree[4 * MAXN][4 * MAXN];

void init_y(int cur_x, int l_x, int r_x, int cur_y, int l_y, int r_y) {
    if (l_y == r_y) {
        if (l_x == r_x) {
            tree[cur_y][cur_x] = num[l_y][l_x];
        } else {
            tree[cur_y][cur_x] =
                tree[cur_y][cur_x * 2] + tree[cur_y][cur_x * 2 + 1];
        }
    } else {
        int m_y = (l_y + r_y) / 2;
        init_y(cur_x, l_x, r_x, cur_y * 2, l_y, m_y);
        init_y(cur_x, l_x, r_x, cur_y * 2 + 1, m_y + 1, r_y);
        tree[cur_y][cur_x] =
            tree[cur_y * 2][cur_x] + tree[cur_y * 2 + 1][cur_x];
    }
}

void init_x(int cur_x, int l_x, int r_x) {
    if (l_x != r_x) {
        int m_x = (l_x + r_x) / 2;
        init_x(cur_x * 2, l_x, m_x);
        init_x(cur_x * 2 + 1, m_x + 1, r_x);
    }
    init_y(cur_x, l_x, r_x, 1, 0, n - 1);
}

int get_y(int cur_x, int cur_y, int l_y, int r_y, int l_qy, int r_qy) {
    if ((r_y < l_qy) || (r_qy < l_y)) {
        return 0;
    } else if ((l_qy <= l_y) && (r_y <= r_qy)) {
        return tree[cur_y][cur_x];
    } else {
        int m_y = (l_y + r_y) / 2;
        return get_y(cur_x, cur_y * 2, l_y, m_y, l_qy, r_qy) +
               get_y(cur_x, cur_y * 2 + 1, m_y + 1, r_y, l_qy, r_qy);
    }
}

int get_x(int cur_x, int l_x, int r_x, int l_qx, int r_qx, int l_qy, int r_qy) {
    if ((r_x < l_qx) || (r_qx < l_x)) {
        return 0;
    } else if ((l_qx <= l_x) && (r_x <= r_qx)) {
        return get_y(cur_x, 1, 0, n - 1, l_qy, r_qy);
    } else {
        int m_x = (l_x + r_x) / 2;
        return get_x(cur_x * 2, l_x, m_x, l_qx, r_qx, l_qy, r_qy) +
               get_x(cur_x * 2 + 1, m_x + 1, r_x, l_qx, r_qx, l_qy, r_qy);
    }
}

void update_y(int cur_x, int l_x, int r_x, int cur_y, int l_y, int r_y, int y,
              int new_val) {
    if (l_y == r_y) {
        if (l_x == r_x) {
            tree[cur_y][cur_x] = new_val;
        } else {
            tree[cur_y][cur_x] =
                tree[cur_y][cur_x * 2] + tree[cur_y][cur_x * 2 + 1];
        }
    } else {
        int m_y = (l_y + r_y) / 2;
        if (m_y < y) {
            update_y(cur_x, l_x, r_x, cur_y * 2 + 1, m_y + 1, r_y, y, new_val);
        } else {
            update_y(cur_x, l_x, r_x, cur_y * 2, l_y, m_y, y, new_val);
        }
        tree[cur_y][cur_x] =
            tree[cur_y * 2][cur_x] + tree[cur_y * 2 + 1][cur_x];
    }
}

void update_x(int cur_x, int l_x, int r_x, int x, int y, int new_val) {
    if (l_x != r_x) {
        int m_x = (l_x + r_x) / 2;
        if (m_x < x) {
            update_x(cur_x * 2 + 1, m_x + 1, r_x, x, y, new_val);
        } else {
            update_x(cur_x * 2, l_x, m_x, x, y, new_val);
        }
    }
    update_y(cur_x, l_x, r_x, 1, 0, n - 1, y, new_val);
}

int main() {
    freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            scanf("%d", &num[y][x]);
        }
    }

    init_x(1, 0, n - 1);

    while (m--) {
        int w, x1, y1, x2, y2;
        scanf("%d %d %d", &w, &x1, &y1);

        if (w == 0) {
            scanf("%d", &x2);
            update_x(1, 0, n - 1, y1 - 1, x1 - 1, x2);
        } else {
            scanf("%d %d", &x2, &y2);

            if (x2 < x1) {
                swap(x1, x2);
            }

            if (y2 < y1) {
                swap(y1, y2);
            }

            printf("%d\n", get_x(1, 0, n - 1, y1 - 1, y2 - 1, x1 - 1, x2 - 1));
        }
    }

    return 0;
}