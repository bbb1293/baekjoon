#include <bits/stdc++.h>

using namespace std;

int get_gcd(int a, int b) {
    if (b < a) {
        return get_gcd(b, a);
    }

    if (a == 0) {
        return b;
    }

    return get_gcd(b % a, a);
}

int main() {
    // freopen("input.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    while (t--) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        int gcd = get_gcd(a, b);
        if (c % gcd || max(a, b) < c) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }

    return 0;
}
