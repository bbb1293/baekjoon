#include <bits/stdc++.h>

using namespace std;

long long w, h, l;

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%lld %lld %lld", &w, &h, &l);

    long long ret = l + 1;
    for (long long y = 1; y < l; y++) {
        ret += ((long long)sqrt(l * l - y * y) * 3 + 1);
    }

    if (l > w) {
        long long cur_l = l - w;
        for (long long y = 0; y < min(cur_l, h); y++) {
            ret += ((long long)sqrt(cur_l * cur_l - y * y));
        }
    }

    if (l > h) {
        long long cur_l = l - h;
        for (long long x = 0; x < min(cur_l, w); x++) {
            ret += ((long long)sqrt(cur_l * cur_l - x * x));
        }
    }

    if (l > h + w) {
        long long max_y = (long long)sqrt((l - h) * (l - h) - w * w);
        for (long long y = 0; y <= max_y; y++) {
            long long cand1 =
                (y + h > l - w)
                    ? 0
                    : (long long)sqrt((l - w) * (l - w) - (y + h) * (y + h));
            long long cand2 = (long long)sqrt((l - h) * (l - h) - y * y) - w;

            ret += (max(cand1, cand2) + 1);
        }
        ret--;
    }

    printf("%lld", ret);

    return 0;
}
