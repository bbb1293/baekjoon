#include <bits/stdc++.h>

using namespace std;

int n;
int ymd[3], abc[3];
set<int> m31 = {1, 3, 5, 7, 8, 10, 12};

bool is_possible(int y, int m, int d) {
    if (m > 12 || m == 0) {
        return false;
    }

    if (m31.count(m)) {
        return (0 < d) && (d <= 31);
    } else if (m == 2) {
        int add = !(y % 4) ? 1 : 0;
        return (0 < d) && (d <= 28 + add);
    }
    return (0 < d) && (d <= 30);
}

bool is_safe(int y, int m, int d) {
    if (y != ymd[0]) {
        return (y > ymd[0]);
    }

    if (m != ymd[1]) {
        return (m > ymd[1]);
    }

    return (d >= ymd[2]);
}

int main() {
    // freopen("input.txt", "r", stdin);

    for (int i = 0; i < 3; i++) {
        scanf("%d", &ymd[i]);
    }

    scanf("%d", &n);
    while (n--) {
        for (int i = 0; i < 3; i++) {
            scanf("%d", &abc[i]);
        }

        int cnt = 0;
        if (is_possible(abc[0], abc[1], abc[2])) {
            cnt++;
            if (!is_safe(abc[0], abc[1], abc[2])) {
                printf("unsafe\n");
                continue;
            }
        }

        if (is_possible(abc[2], abc[1], abc[0])) {
            cnt++;
            if (!is_safe(abc[2], abc[1], abc[0])) {
                printf("unsafe\n");
                continue;
            }
        }

        if (is_possible(abc[2], abc[0], abc[1])) {
            cnt++;
            if (!is_safe(abc[2], abc[0], abc[1])) {
                printf("unsafe\n");
                continue;
            }
        }

        if (cnt) {
            printf("safe\n");
        } else {
            printf("invalid\n");
        }
    }

    return 0;
}