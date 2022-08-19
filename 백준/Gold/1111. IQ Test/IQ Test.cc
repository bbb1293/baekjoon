#include <bits/stdc++.h>

using namespace std;

int n;
int a[50];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    if (n == 1) {
        printf("A");
    } else if (n == 2) {
        if (a[0] == a[1]) {
            printf("%d", a[0]);
        } else {
            printf("A");
        }
    } else {
        int up = a[2] - a[1], down = a[1] - a[0];
        int b;

        if (down == 0) {
            b = 0;
        } else {
            b = up / down;
        }

        int c = a[1] - (a[0] * b);

        for (int i = 1; i < n; i++) {
            if (a[i] != (a[i - 1] * b + c)) {
                printf("B");
                return 0;
            }
        }

        printf("%d", a[n - 1] * b + c);
    }

    return 0;
}
