#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);

    if (n & 1) {
        printf("Bob");
    } else {
        printf("Alice\n1");
    }

    return 0;
}