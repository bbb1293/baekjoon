#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e6;
long long a, b;
bool non_prime[MAXN];
vector<int> primes;

void init_prime() {
    non_prime[1] = true;
    for (int i = 3; i < MAXN; i += 2) {
        if (!non_prime[i]) {
            primes.push_back(i);
            for (int j = i + i; j < MAXN; j += i) {
                non_prime[j] = true;
            }
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    init_prime();

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%lld %lld", &a, &b);
        a += b;

        if (!(a & 1)) {
            if (a == 2) {
                printf("NO\n");
            } else {
                printf("YES\n");
            }
        } else {
            a -= 2;
            if (a < MAXN) {
                if (!non_prime[a]) {
                    printf("YES\n");
                } else {
                    printf("NO\n");
                }
            } else {
                bool prime = true;
                for (auto p : primes) {
                    if (!(a % p)) {
                        prime = false;
                        break;
                    }
                }

                if (prime) {
                    printf("YES\n");
                } else {
                    printf("NO\n");
                }
            }
        }
    }

    return 0;
}
