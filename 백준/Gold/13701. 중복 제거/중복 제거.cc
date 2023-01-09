#include <bits/stdc++.h>

using namespace std;

int n;
int bit_set[(1 << 20)];

int main() {
    // freopen("input.txt", "r", stdin);

    while (scanf("%d", &n) > 0) {
        int front = (n >> 5), back = (n % 32);

        if (!(bit_set[front] & (1 << back))) {
            bit_set[front] |= (1 << back);
            printf("%d ", n);
        }
    }

    return 0;
}