#include <bits/stdc++.h>

using namespace std;

long long n;

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%lld", &n);

    if (n % 5 == 0 || n % 5 == 2) {
        printf("CY");
    } else {
        printf("SK");
    }

    return 0;
}