#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);

    int cur = 1;
    while (cur <= n) {
        n -= cur;
        cur++;
    }

    if (cur & 1) {
        printf("%d", cur - n);

    } else {
        printf("0");
    }

    return 0;
}
