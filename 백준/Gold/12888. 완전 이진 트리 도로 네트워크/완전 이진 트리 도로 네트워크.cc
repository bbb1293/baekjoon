#include <bits/stdc++.h>

using namespace std;

int h;

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &h);

    long long sum = 0, prev = 1;
    for (int i = 0; i < h; i++) {
        long long cur = sum * 2 + 1;
        sum += prev;
        prev = cur;
    }

    printf("%lld", prev);

    return 0;
}