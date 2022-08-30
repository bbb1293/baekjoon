#include <bits/stdc++.h>

using namespace std;

struct P {
    int x, y;
};

P xy[4];

int ccw(int a, int b, int c) {
    int v = xy[a].x * (xy[b].y - xy[c].y) + xy[b].x * (xy[c].y - xy[a].y) +
            xy[c].x * (xy[a].y - xy[b].y);

    if (v < 0) {
        return -1;
    } else if (v == 0) {
        return 0;
    }
    return 1;
}

int main() {
    // freopen("input.txt", "r", stdin);

    for (int i = 0; i < 4; i++) {
        scanf("%d %d", &xy[i].x, &xy[i].y);
    }

    if (ccw(0, 1, 2) * ccw(0, 1, 3) < 0 && ccw(2, 3, 0) * ccw(2, 3, 1) < 0) {
        printf("1");
    } else {
        printf("0");
    }

    return 0;
}
