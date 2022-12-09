#include <bits/stdc++.h>

using namespace std;

int n, a;
bool non_prime[120];

void set_prime() {
    non_prime[0] = non_prime[1] = true;

    for (int i = 2; i < 120; i++) {
        if (!non_prime[i]) {
            for (int j = i + i; j < 120; j += i) {
                non_prime[j] = true;
            }
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);

    set_prime();

    while (n--) {
        scanf("%d", &a);

        bool possible = false;
        for (int i = 2; i < a - 1; i++) {
            if (!non_prime[i] && !non_prime[a - i]) {
                possible = true;
                break;
            }
        }

        if (possible) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}