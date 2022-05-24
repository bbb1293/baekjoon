#include <bits/stdc++.h>

using namespace std;

int n;
int c[10];

int get_gcd(int a, int b) {
    if (b < a) {
        return get_gcd(b, a);
    }

    if (a == 0) {
        return b;
    }

    return get_gcd(b % a, a);
}

pair<int, int> get_sum(int bits) {
    int upper = 0, lower = 0;
    for (int i = 0; i < n; i++) {
        if (bits & (1 << i)) {
            if (upper == 0) {
                upper = 1, lower = c[i];
            } else {
                upper = (upper * c[i]) + lower;
                lower *= c[i];

                int gcd = get_gcd(upper, lower);
                upper /= gcd;
                lower /= gcd;
            }
        }
    }

    return {upper, lower};
}

bool is_ok(int upper, int lower) {
    int left = 99 * lower, right = 101 * lower;

    upper *= 100;

    return (left <= upper) && (upper <= right);
}

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    int ret = 0;

    int last = (1 << n);
    for (int bits = 1; bits < last; bits++) {
        auto [upper, lower] = get_sum(bits);

        if (is_ok(upper, lower)) {
            ret++;
        }
    }
    cout << ret;

    return 0;
}
