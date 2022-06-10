#include <bits/stdc++.h>

using namespace std;

int g;

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &g);

    int a = 1, b = 1;
    bool pos = false;
    while (true) {
        int diff = a * a - b * b;

        if (diff > g) {
            if (a - b == 1) {
                break;
            }
            b++;
        } else {
            if (diff == g) {
                printf("%d\n", a);
                pos = true;
            }

            a++;
        }
    }

    if (!pos) {
        printf("-1");
    }

    return 0;
}
