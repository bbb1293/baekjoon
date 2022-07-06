#include <bits/stdc++.h>

using namespace std;

const int MAXN = 32767;

int main() {
    // freopen("input.txt", "r", stdin);

    int a, b;
    scanf("%d %d", &a, &b);

    double min_diff = 1;
    int ret1, ret2;
    for (int d = 2; d <= MAXN; d++) {
        for (int c = max(1, a * d / b - 1); c <= min(MAXN, a * d / b + 1);
             c++) {
            double diff = abs((double)a / b - (double)c / d);
            if (diff && diff < min_diff) {
                min_diff = diff;
                ret1 = c;
                ret2 = d;
            }
        }
    }

    printf("%d %d", ret1, ret2);

    return 0;
}
