#include <bits/stdc++.h>

using namespace std;

struct Point {
    int x, y;
};

int n;
Point a[50], b[50];

void adjust(Point &p) {
    if (p.x == 1) {
        p.x = p.y;
        p.y = 0;
    } else if (p.x == 2) {
        p.x = p.y;
        p.y = 51;
    } else if (p.x == 3) {
        p.x = 0;
    } else {
        p.x = 51;
    }
}

bool between(Point &a, Point &b, Point &c) {
    if (a.x == b.x && a.x == c.x) {
        if (a.y < b.y && b.y < c.y) {
            return true;
        } else if (c.y < b.y && b.y < a.y) {
            return true;
        }
    } else if (a.y == b.y && a.y == c.y) {
        if (a.x < b.x && b.x < c.x) {
            return true;
        } else if (c.x < b.x && b.x < a.x) {
            return true;
        }
    }

    return false;
}

int orientation(Point &a, Point &b, Point &c) {
    int v = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);

    if (v < 0) {
        return -1;
    } else if (v == 0) {
        return 0;
    }
    return 1;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    n /= 2;

    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &a[i].x, &a[i].y, &b[i].x, &b[i].y);

        adjust(a[i]);
        adjust(b[i]);
    }

    int ret1 = 0, ret2 = 0;
    for (int i = 0; i < n; i++) {
        int cand = 0;
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }

            if (orientation(a[i], b[i], a[j]) * orientation(a[i], b[i], b[j]) ==
                -1) {
                ret1++;
                cand++;
            } else if (between(a[i], a[j], b[i]) ^ between(a[i], b[j], b[i])) {
                ret1++;
                cand++;
            }
        }

        ret2 = max(ret2, cand);
    }

    ret1 /= 2;
    printf("%d\n%d", ret1, ret2);

    return 0;
}
