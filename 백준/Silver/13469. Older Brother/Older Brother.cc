#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
int q;
bool non_prime[MAXN];

void set_prime() {
    non_prime[0] = non_prime[1] = true;

    for (int i = 2; i < MAXN; i++) {
        if (!non_prime[i]) {
            for (int j = i + i; j < MAXN; j += i) {
                non_prime[j] = true;
            }
        }
    }
}

bool is_prime_power(int k) {
    if (k == 1) {
        return false;
    }

    for (int i = 2; i < MAXN; i++) {
        if (!non_prime[i] && !(k % i)) {
            while (!(k % i)) {
                k /= i;
            }

            return (k == 1);
        }
    }

    return true;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &q);

    if (is_prime_power(q)) {
        printf("yes");
    } else {
        printf("no");
    }

    return 0;
}