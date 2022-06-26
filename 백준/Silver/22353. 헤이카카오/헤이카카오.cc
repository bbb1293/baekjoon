#include <bits/stdc++.h>

using namespace std;

int a, k;
double d;

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %lf %d", &a, &d, &k);

    double ret = a * d / 100;
    double lose = (100 - d) / 100;
    int t = 2 * a;

    while (true) {
        d += (d * k / 100);

        if (d >= 100) {
            ret += (t * lose);
            break;
        }
        ret += (t * lose * d / 100);
        lose *= ((100 - d) / 100);
        t += a;
    }

    printf("%lf", ret);

    return 0;
}
