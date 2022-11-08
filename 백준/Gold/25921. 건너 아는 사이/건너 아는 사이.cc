#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;
int n;
bool non_prime[MAXN + 1];

long long get_ret() {
    non_prime[0] = non_prime[1] = true;

    long long ret = 0;
    int i;
    for (i = 2; i * i <= n; i++) {
        if (!non_prime[i]) {
            ret += i;

            for (int j = i + i; j <= n; j += i) {
                if (!non_prime[j]) {
                    non_prime[j] = true;
                    ret += i;
                }
            }
        }
    }

    for (; i <= n; i++) {
        if (!non_prime[i]) {
            ret += i;
        }
    }

    return ret;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);

    printf("%lld", get_ret());

    return 0;
}