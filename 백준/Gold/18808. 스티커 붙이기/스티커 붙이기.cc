#include <bits/stdc++.h>

using namespace std;

const int MAXK = 100;
int n, m, k;
int r[MAXK], c[MAXK];
int sticker[MAXK][40][40];
int space[40][40];

bool possible(int start_y, int start_x, int idx, int dir) {
    if (dir == 0) {
        for (int y = 0; y < r[idx]; y++) {
            for (int x = 0; x < c[idx]; x++) {
                if (sticker[idx][y][x] * space[start_y + y][start_x + x] == 1) {
                    return false;
                }
            }
        }
    } else if (dir == 1) {
        for (int x = 0; x < c[idx]; x++) {
            for (int y = r[idx] - 1; y >= 0; y--) {
                if (sticker[idx][y][x] *
                        space[start_y + x][start_x + (r[idx] - 1 - y)] ==
                    1) {
                    return false;
                }
            }
        }
    } else if (dir == 2) {
        for (int y = r[idx] - 1; y >= 0; y--) {
            for (int x = c[idx] - 1; x >= 0; x--) {
                if (sticker[idx][y][x] * space[start_y + (r[idx] - 1 - y)]
                                              [start_x + (c[idx] - 1 - x)] ==
                    1) {
                    return false;
                }
            }
        }
    } else {
        for (int x = c[idx] - 1; x >= 0; x--) {
            for (int y = 0; y < r[idx]; y++) {
                if (sticker[idx][y][x] *
                        space[start_y + (c[idx] - 1 - x)][start_x + y] ==
                    1) {
                    return false;
                }
            }
        }
    }

    return true;
}

void put_sticker(int start_y, int start_x, int idx, int dir) {
    if (dir == 0) {
        for (int y = 0; y < r[idx]; y++) {
            for (int x = 0; x < c[idx]; x++) {
                space[start_y + y][start_x + x] += sticker[idx][y][x];
            }
        }
    } else if (dir == 1) {
        for (int x = 0; x < c[idx]; x++) {
            for (int y = r[idx] - 1; y >= 0; y--) {
                space[start_y + x][start_x + (r[idx] - 1 - y)] +=
                    sticker[idx][y][x];
            }
        }
    } else if (dir == 2) {
        for (int y = r[idx] - 1; y >= 0; y--) {
            for (int x = c[idx] - 1; x >= 0; x--) {
                space[start_y + (r[idx] - 1 - y)][start_x + (c[idx] - 1 - x)] +=
                    sticker[idx][y][x];
            }
        }
    } else {
        for (int x = c[idx] - 1; x >= 0; x--) {
            for (int y = 0; y < r[idx]; y++) {
                space[start_y + (c[idx] - 1 - x)][start_x + y] +=
                    sticker[idx][y][x];
            }
        }
    }
}

void solve() {
    for (int i = 0; i < k; i++) {
        bool put = false;
        for (int dir = 0; dir < 4 && !put; dir++) {
            for (int y = 0; y < n && !put; y++) {
                if (dir & 1) {
                    if (y + c[i] > n) {
                        break;
                    }
                } else {
                    if (y + r[i] > n) {
                        break;
                    }
                }

                for (int x = 0; x < m; x++) {
                    if (dir & 1) {
                        if (x + r[i] > m) {
                            break;
                        }
                    } else {
                        if (x + c[i] > m) {
                            break;
                        }
                    }

                    if (possible(y, x, i, dir)) {
                        put_sticker(y, x, i, dir);
                        put = true;
                        break;
                    }
                }
            }
        }
    }

    int ret = 0;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            ret += space[y][x];
        }
    }

    printf("%d", ret);
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d %d", &n, &m, &k);

    for (int i = 0; i < k; i++) {
        scanf("%d %d", &r[i], &c[i]);

        for (int y = 0; y < r[i]; y++) {
            for (int x = 0; x < c[i]; x++) {
                scanf("%d", &sticker[i][y][x]);
            }
        }
    }

    solve();

    return 0;
}
