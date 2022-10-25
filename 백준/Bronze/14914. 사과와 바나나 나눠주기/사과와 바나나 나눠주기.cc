#include <bits/stdc++.h>

using namespace std;

int a, b;

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &a, &b);

    for (int i = 1; i <= min(a, b); i++) {
        if (!(a % i) && !(b % i)) {
            printf("%d %d %d\n", i, a / i, b / i);
        }
    }

    return 0;
}