#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e4;
int n, p;
int t[MAXN + 1];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &p);

    bool non_zero = false;
    for (int i = 0; i < n; i++) {
        scanf("%d", &t[i]);

        if (t[i]) {
            non_zero = true;
        }
    }
    t[n] = 0;

    for (int i = 0; i < n; i++) {
        if (t[i] > t[i + 1]) {
            t[i] = p;
            p--;
        } else {
            t[i] = p;
        }
    }

    if (!non_zero) {
        for (int i = 0; i < n; i++) {
            printf("0\n");
        }
        return 0;
    }

    if (p != 0) {
        printf("ambiguous");
    } else {
        for (int i = 0; i < n; i++) {
            printf("%d\n", t[i]);
        }
    }

    return 0;
}