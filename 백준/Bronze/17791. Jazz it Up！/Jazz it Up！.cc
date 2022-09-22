#include <bits/stdc++.h>

using namespace std;

int n;
bool non_prime[100000];

void init() {
    for (int i = 3; i < 100000; i += 2) {
        if (!non_prime[i]) {
            for (int j = i + i; j < 100000; j += i) {
                non_prime[j] = true;
            }
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    init();

    scanf("%d", &n);

    if (n & 1) {
        printf("2");
    } else {
        for (int i = 3; i < n; i += 2) {
            if (!non_prime[i] && (n % i)) {
                printf("%d", i);
                return 0;
            }
        }
    }

    return 0;
}