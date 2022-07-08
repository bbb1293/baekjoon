#include <bits/stdc++.h>

using namespace std;

int n;

int get_gcd(int a, int b) {
    if (b < a) {
        swap(a, b);
    }

    while (a != 0) {
        int tmp = b % a;
        b = a;
        a = tmp;
    }

    return b;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    n -= 2;

    int ret = 1;
    while (n--) {
        int t;
        scanf("%d", &t);

        int gcd = get_gcd(ret, t);
        ret /= gcd;
        ret *= t;
    }

    printf("%d", ret);

    return 0;
}
