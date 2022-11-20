#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);

    if (n == 1) {
        printf("0");
    } else {
        printf("%d", (n * n + 1) / 2);
    }

    return 0;
}
