#include <bits/stdc++.h>

using namespace std;

int n;

int get_gcd(int a, int b) {
    if (b < a) {
        swap(a, b);
    }

    while (a) {
        int tmp = a;
        a = b % a;
        b = tmp;
    }

    return b;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);

    int a, b;
    scanf("%d %d", &a, &b);
    int d = abs(a - b);

    for (int i = 2; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);

        d = get_gcd(d, abs(a - tmp));
    }

    d = max(d, 1);

    printf("%d", d);

    return 0;
}