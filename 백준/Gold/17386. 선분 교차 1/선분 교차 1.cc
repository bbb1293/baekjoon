#include <bits/stdc++.h>

using namespace std;

struct Point {
    long long x, y;
} p[4];

int orientation(Point &a, Point &b, Point &c) {
    long long v = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);

    if (v > 0) {
        return 1;
    } else if (v == 0) {
        return 0;
    }
    return -1;
}

bool is_cross(Point &a, Point &b, Point &c, Point &d) {
    if (orientation(a, b, c) * orientation(a, b, d) <= 0) {
        return true;
    }

    return false;
}

int main() {
    // freopen("input.txt", "r", stdin);

    for (int i = 0; i < 4; i++) {
        scanf("%lld %lld", &p[i].x, &p[i].y);
    }

    bool possible = true;
    for (int i = 0; i < 3; i += 2) {
        possible &=
            is_cross(p[i], p[(i + 1) % 4], p[(i + 2) % 4], p[(i + 3) % 4]);
    }

    if (possible) {
        printf("1");
    } else {
        printf("0");
    }

    return 0;
}
