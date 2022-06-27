#include <bits/stdc++.h>

using namespace std;

int w, h, x, y, p;

int get_sqdist(int xx, int yy, double o_x, double o_y) {
    double x_diff = (xx - o_x);
    double y_diff = (yy - o_y);

    return x_diff * x_diff + y_diff * y_diff;
}

bool is_in(int xx, int yy) {
    if (x <= xx && xx <= x + w && y <= yy && yy <= y + h) {
        return true;
    }

    double r = (double)h / 2;
    if (get_sqdist(xx, yy, x, y + r) <= r * r) {
        return true;
    }

    if (get_sqdist(xx, yy, x + w, y + r) <= r * r) {
        return true;
    }

    return false;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d %d %d %d", &w, &h, &x, &y, &p);

    int ret = 0;
    while (p--) {
        int xx, yy;
        scanf("%d %d", &xx, &yy);

        if (is_in(xx, yy)) {
            ret++;
        }
    }

    printf("%d", ret);

    return 0;
}
