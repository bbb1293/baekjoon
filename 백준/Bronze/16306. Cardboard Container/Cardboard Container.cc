#include <bits/stdc++.h>

using namespace std;

int v;

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &v);

    int ret = 1e9;
    for (int a = 1; a <= 100; a++) {
        if (v < a) {
            break;
        }

        if (v % a) {
            continue;
        }

        for (int b = a; b <= 1000; b++) {
            if (v / a < b) {
                break;
            }

            if ((v / a) % b) {
                continue;
            }

            int c = v / a / b;

            ret = min(ret, 2 * (a * b + b * c + c * a));
        }
    }

    printf("%d", ret);

    return 0;
}