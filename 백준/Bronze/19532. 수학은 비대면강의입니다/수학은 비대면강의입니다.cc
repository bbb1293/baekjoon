#include <bits/stdc++.h>

using namespace std;

int a, b, c, d, e, f;

int main() {
    //freopen("input.txt", "r", stdin);

    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);

    for (int i = -999; i <= 999; i++) {
        for (int j = -999; j <= 999; j++) {
            if ((a * i + b * j == c) && (d * i + e * j == f)) {
                printf("%d %d", i, j);
                return 0;
            }
        }
    }

    return 0;
}
