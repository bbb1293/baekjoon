#include <bits/stdc++.h>

using namespace std;

struct Point {
    long long x, y;
};

struct Slice {
    Point s, e;
    long long w;

    bool operator<(Slice &a) { return w < a.w; }
};

const int MAXN = 2500;
int n;
Slice s[MAXN];

int orientation(Point &a, Point &b, Point &c) {
    long long v = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);

    if (v < 0) {
        return -1;
    } else if (v == 0) {
        return 0;
    }

    return 1;
}

bool cross(int i, int j) {
    if (((orientation(s[i].s, s[i].e, s[j].s) *
          orientation(s[i].s, s[i].e, s[j].e)) <= 0) &&
        ((orientation(s[j].s, s[j].e, s[i].s) *
          orientation(s[j].s, s[j].e, s[i].e)) <= 0)) {
        return true;
    }

    return false;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld %lld %lld %lld", &s[i].s.x, &s[i].s.y, &s[i].e.x, &s[i].e.y,
              &s[i].w);
    }
    sort(s, s + n);

    long long ret = 0;
    for (int i = 0; i < n; i++) {
        ret += s[i].w;

        for (int j = 0; j < i; j++) {
            if (cross(i, j)) {
                ret += s[j].w;
            }
        }
    }

    printf("%lld", ret);

    return 0;
}
