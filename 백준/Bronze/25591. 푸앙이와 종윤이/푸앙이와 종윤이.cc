#include <bits/stdc++.h>

using namespace std;

int a, b;

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &a, &b);

    printf("%d %d ", 100 - a, 100 - b);
    int c = a + b - 100, d = (100 - a) * (100 - b);
    printf("%d %d %d %d\n", c, d, d / 100, d % 100);

    c += (d / 100);
    d %= 100;

    printf("%d %d", c, d);

    return 0;
}
