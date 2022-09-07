#include <bits/stdc++.h>

using namespace std;

int n;
long long s_x, s_y, e_x, e_y;

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    scanf("%lld %lld %lld %lld", &s_x, &s_y, &e_x, &e_y);

    int ret = 1;
    long long ret_dist = 1e15;

    for (int i = 1; i <= n; i++) {
        long long cur_x = s_x, cur_y = s_y;
        long long dist = 0;

        int m;
        scanf("%d", &m);

        while (m--) {
            long long x, y;
            scanf("%lld %lld", &x, &y);

            dist += (abs(x - cur_x) + abs(y - cur_y));
            cur_x = x;
            cur_y = y;
        }
        dist += (abs(e_x - cur_x) + abs(e_y - cur_y));

        if (dist < ret_dist) {
            ret = i;
            ret_dist = dist;
        }
    }

    printf("%d", ret);

    return 0;
}
